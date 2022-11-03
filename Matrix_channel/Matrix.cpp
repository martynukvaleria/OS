#include <iostream>
#include "Matrix.h"

void
MatrixMultiplication::blockMultiplication(std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2,
                                          std::vector<std::vector<int>> &result,
                                          BufferedChannel<std::pair<int, int>> &channel, int number) {
    std::pair<int, bool> pair = channel.Recv().first;
    for (int i = pair.first;
         i < std::min(pair.first + number, (int) m1.size(), [](int m1, int m2) { return m1 < m2; }); ++i) {
        for (int j = pair.second;
             j < std::min(pair.second + number, (int) m1.size(), [](int m1, int m2) { return m1 < m2; }); ++j) {
            for (int k = 0; k < m1.size(); ++k) {
                g_lock.lock();
                result[i][j] += m1[i][k] * m2[k][j];
                g_lock.unlock();
            }
        }
    }
}

std::vector<std::vector<int>>
MatrixMultiplication::matrixMultiplication(std::vector<std::vector<int>> &matrix_1,
                                           std::vector<std::vector<int>> &matrix_2, int number,
                                           bool in_thread) {
    if (matrix_1.size() < 5 || matrix_2.size() < 5) {
        throw std::logic_error("Your matrix doesn't have enough elements");
    }
    std::vector<std::vector<int>> temp = std::vector<std::vector<int>>(matrix_1.size(),
                                                                       std::vector<int>(matrix_1.size()));
    std::vector<std::thread> threads;
    BufferedChannel<std::pair<int, int>> channel(pow(matrix_1.size() / number + 1, 2));
    for (int i = 0; i < matrix_1.size(); i += number) {
        for (int j = 0; j < matrix_1.size(); j += number) {
            channel.Send(std::pair(i, j));
        }
    }
    for (int i = 0; i < matrix_1.size(); i += number) {
        for (int j = 0; j < matrix_1.size(); j += number) {

            if (in_thread) {
                threads.emplace_back(blockMultiplication, std::ref(matrix_1), std::ref(matrix_2), matrix_1.size(),
                                     std::ref(temp));
            } else {
                threads.front().join();
                threads.pop_front();
                threads.emplace_back(blockMultiplication, std::ref(matrix_1), std::ref(matrix_2), matrix_1.size(),
                                     std::ref(temp));
                blockMultiplication(matrix_1, matrix_2,temp);
            }
        }
    }
    if (in_thread) {
        for (auto &item: threads) {
            item.join();
        }
    }
    return temp;
}

void MatrixMultiplication::printMatrix(const std::vector<std::vector<int>> &m) {
    for (const auto &row: m) {
        for (auto &element: row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}
