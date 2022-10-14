#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <algorithm>
#include <exception>
#include <mutex>
#include <thread>
#include <vector>

class MatrixMultiplication {
private:
    std::vector<std::vector<int>> m1;
    std::vector<std::vector<int>> m2;

    static void
    blockMultiplication(std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2, int row, int column,
                        int size, std::vector<std::vector<int>> &result);

public:

    static std::vector<std::vector<int>>
    matrixMultiplication(std::vector<std::vector<int>> &matrix_1, std::vector<std::vector<int>> &matrix_2, int size,
                         bool in_thread = true);

    static void printMatrix(const std::vector<std::vector<int>> &m);
};


#endif //MATRIX_MATRIX_H
