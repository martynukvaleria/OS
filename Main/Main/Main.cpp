#include <iostream>
#include "Vector.h"

using vector::Vector;
using number::Number;

int main()
{
    Vector a = Vector(number::GetNum(2), number::GetNum(2));
    Vector b = Vector(number::GetNum(10.5), number::GetNum(12));
    Vector add = Vector::Add(a, b);
    std::cout << "Sum of two vectors: " << add.GetA() << " " << add.GetB() << std::endl;
    //std::cout << "Sum of two vectors in polar coordinates: " << add.Radius() << " " << add.Angle() << std::endl;
    Vector zero_vector = vector::zero_vector;
    std::cout << "Null vector: " << zero_vector.GetA() << " " << zero_vector.GetB() << std::endl;

    Number ten = number::GetNum(10);
    Number eight = number::GetNum(8.5);
    Number result = (ten * eight + 4.5 + number::one) / ten + number::zero;
    std::cout << "Result of calculation: " << result << std::endl;
}