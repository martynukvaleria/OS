#pragma once

#include <cmath>
#include <numbers.h>

namespace vector {

    class Vector {
    public:
        using Number = number::Number;

        Vector(const Number& a, const Number& b);

        Vector(const Vector &) = default;

        Number Radius() const;

        Number Angle() const;

        Number GetA() const;

        Number GetB() const;

        static Vector Add(Vector& v1, Vector& v2);

    private:

        Number a_;
        Number b_;
    };

    extern const Vector zero_vector;
    extern const Vector one_vector;

}
