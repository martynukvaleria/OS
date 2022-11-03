#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <algorithm>
#include <exception>
#include <mutex>
#include <thread>
#include <vector>
#include <fstream>
#include <sstream>
#include <valarray>
#include "buffered_channel.h"

class MatrixMultiplication {
private:
    std::vector<std::vector<int>> m1;
    std::vector<std::vector<int>> m2;

    static void
    blockMultiplication(std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2,
                        std::vector<std::vector<int>> &result, BufferedChannel<std::pair<int, int>> &channel,
                        int number);

public:

    static std::vector<std::vector<int>>
    matrixMultiplication(std::vector<std::vector<int>> &matrix_1, std::vector<std::vector<int>> &matrix_2, int size,
                         bool in_thread = true);

    static void printMatrix(const std::vector<std::vector<int>> &m);
};


#endif //MATRIX_MATRIX_H
