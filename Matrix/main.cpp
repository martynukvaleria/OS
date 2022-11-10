#include <iostream>
#include <random>
#include "Matrix.h"

void Tests(Matrix& m1, Matrix& m2) {
    auto start = std::chrono::high_resolution_clock::now();
    Matrix startResult = Matrix::matrixMultiplication(m1, m2, 2);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    for (int i = 1; i <= m1.getMatrix().size(); ++i) {
        start = std::chrono::high_resolution_clock::now();
        Matrix result = Matrix::matrixMultiplication(m1, m2, i);
        end = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        std::cout << "For block size " << i << ":" <<  elapsed.count() << std::endl;
    }
}

std::vector<std::vector<double>> GenerateMatrix(int m_size) {
    std::vector<std::vector<double>> matrix;
    for (int i = 0; i < m_size; ++i) {
        std::vector<double> row;
        row.reserve(m_size);
for (int j = 0; j < m_size; j++) {
            row.push_back(rand() % 1'000'000);
        }
        matrix.push_back(row);
    }
    return matrix;
}

int main() {
    std::vector<int> m_sizes{10, 100, 1000};
    for (auto m_size: m_sizes) {
        Matrix matrix_1 = GenerateMatrix(m_size);
        Matrix matrix_2 = GenerateMatrix(m_size);
        std::cout << "Testing matrix " << m_size << "x" << m_size << " ...\n";
        Tests(matrix_1, matrix_2);
        std::cout << "\n";
    }
}