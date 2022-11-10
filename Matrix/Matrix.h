#include <iostream>
#include <vector>
#include <windows.h>
#include <mutex>
#include <cmath>
#include <list>

class Matrix {
public:
    explicit Matrix() = default;

    Matrix(std::vector<std::vector<double>> matrix);

    static void
    blockMultiplication(const Matrix &m1, const Matrix &m2, Matrix &resultBlock, size_t row, size_t column,
                        size_t number);

    static Matrix matrixMultiplication(const Matrix& m1, const Matrix& m2, int number);

    static DWORD WINAPI Call(LPVOID args) {
        Args *castedArgs = (Args *) args;
        blockMultiplication(castedArgs->m1, castedArgs->m2, castedArgs->result, castedArgs->i, castedArgs->j,
                            castedArgs->number);
        ExitThread(0);
    }

    static void printMatrix(const Matrix &matrix);

    struct Args {
        Args(const Matrix &m1, const Matrix &m2, Matrix &result, size_t i, size_t j, size_t number)
                : m1(m1), m2(m2), result(result), i(i), j(j), number(number) {}

        const Matrix &m1;
        const Matrix &m2;
        Matrix &result;
        size_t i;
        size_t j;
        size_t number;
    };

    [[nodiscard]] std::vector<std::vector<double>> getMatrix() const;
    [[nodiscard]] int getSize() const;

private:
    std::vector<std::vector<double>> _matrix;
};