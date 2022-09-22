#include <iostream>
#include "Vector.h"

int main() {
    number::Number a = number::GetNum(1);
    number::Number b = number::GetNum(5.6);
    std::cout << "a + b = " << double(a.Add(b)) << std::endl;

    vector::Vector vector1(1, 2), vector2(3, 4);
    vector::Vector sum = vector::Vector::Add(vector1, vector2);
    std::cout << "vector1 + vector2 = " << double(sum.GetA()) << " " << double(sum.GetB()) << std::endl;
    std::cout << "vector1 + vector2  in polar = " << double(sum.Radius()) << " " << double(sum.Angle()) << std::endl;
    vector::Vector zero = vector::zero_vector;
    vector::Vector one = vector::one_vector;
    std::cout << "Zero vector: " << double(zero.GetA()) << " " << double(zero.GetB()) << std::endl;
    std::cout << "One vector: " << double(one.GetA()) << " " << double(one.GetB()) << std::endl;
}
