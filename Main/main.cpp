#include <iostream>
#include "Vector.h"

int main() {
    number::Number a = number::GetNum(1);
    number::Number b = number::GetNum(5.6);
    std::cout << "a + b = " << (a.Add(b)).GetValue() << std::endl;

    vector::Vector vector1(1, 2), vector2(3, 4);
    vector::Vector sum = vector::Vector::Add(vector1, vector2);
    std::cout << "vector1 + vector2 = " << sum.GetA().GetValue() << " " << sum.GetB().GetValue() << std::endl;
    std::cout << "vector1 + vector2  in polar = " << sum.Radius().GetValue() << " " << sum.Angle().GetValue() << std::endl;
    vector::Vector zero = vector::zero_vector;
    vector::Vector one = vector::one_vector;
    std::cout << "Zero vector: " << zero.GetA().GetValue() << " " << zero.GetB().GetValue() << std::endl;
    std::cout << "One vector: " << one.GetA().GetValue() << " " << one.GetB().GetValue() << std::endl;
}
