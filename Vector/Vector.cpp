#include "Vector.h"

namespace vector {

    const Vector one_vector = Vector(number::one, number::one);

    const Vector zero_vector = Vector(number::zero, number::zero);

    Vector::Vector(const Number& a, const Number& b) : a_(a), b_(b) {}

    Vector::Vector(double a, double b) : a_(Number(a)), b_(Number (b)) {}

    number::Number Vector::Radius() const {
        Number z = a_.Multiply(a_).Add(b_.Multiply(b_));
        return z.sqrt();
    }

    number::Number Vector::Angle() const {
        Number z = a_.Divide(b_);
        return z.atan();
    }

    number::Number Vector::GetA() const {
        return a_;
    }

    number::Number Vector::GetB() const {
        return b_;
    }

    Vector Vector::Add(vector::Vector &v1, vector::Vector &v2) {
        return Vector(v1.GetA().Add(v2.GetA()), v1.GetB().Add(v2.GetB()));
    }
}
