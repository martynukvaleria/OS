#include <iostream>
#include <random>
#include "Matrix.h"

void Tests(std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2) {
    for (int i = 1; i <= m1.size(); ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        auto result = MatrixMultiplication::matrixMultiplication(m1, m2, i, false);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "For block size " << i << ":\t" << elapsed.count() << std::endl;
    }
}

std::vector<std::vector<int>> GenerateMatrix(int m_size) {
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < m_size; ++i) {
        std::vector<int> row;
        for (int j = 0; j < m_size; j++) {
            row.push_back(random() % 1'000'000);
        }
        matrix.push_back(row);
    }
    return matrix;
}

int main() {
    std::vector<int> m_sizes{10, 100, 1000};
    for (auto m_size: m_sizes) {
        std::vector<std::vector<int>> matrix_1 = GenerateMatrix(m_size);
        std::vector<std::vector<int>> matrix_2 = GenerateMatrix(m_size);
        std::cout << "Testing matrix " << m_size << "x" << m_size << " ...\n";
        Tests(matrix_1, matrix_2);
        std::cout << "\n";
    }
}
