#include <iostream>
#include "Matrix.h"

void
MatrixMultiplication::blockMultiplication(std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2, int row,
                                          int column, int size, std::vector<std::vector<int>> &result) {
    for (int i = row; i < std::min(row + size, (int) m1.size(), [](int a, int b) { return a < b; }); ++i) {
        for (int j = row; j < std::min(row + size, (int) m1.size(), [](int a, int b) { return a < b; }); ++j) {
            for (int k = 0; k < m1.size(); ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

std::vector<std::vector<int>>
MatrixMultiplication::matrixMultiplication(std::vector<std::vector<int>> &matrix_1,
                                           std::vector<std::vector<int>> &matrix_2,
                                           int size, bool in_thread) {
    if (matrix_1.size() < 5 || matrix_2.size() < 5) {
        throw std::logic_error("Your matrix doesn't have enough elements");
    }
    std::vector<std::vector<int>> temp = std::vector<std::vector<int>>(matrix_1.size(),
                                                                       std::vector<int>(matrix_1.size()));
    std::vector<std::thread> threads;
    for (int row = 0; row < matrix_1.size(); row += size) {
        for (int column = 0; column < matrix_1.size(); column += size) {

            if (in_thread) {
                threads.emplace_back(blockMultiplication, std::ref(matrix_1), std::ref(matrix_2), row, column, size,
                                     std::ref(temp));
            } else {
                blockMultiplication(matrix_1, matrix_2, row, column, size, temp);
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
