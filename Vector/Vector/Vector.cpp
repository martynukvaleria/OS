#include "pch.h" 
#include "Vector.h"
#include <numbers>
#include <cmath>

namespace vector {

	const Vector one_vector = Vector(number::one, number::one);

	const Vector one_vector = Vector(number::zero, number::zero);

	Vector::Vector(Number a, Number b) : a_(a), b_(b) {}

	number::Number Vector::Radius() const
	{
		Number z = a_ * a_ + b_ * b_;
		return sqrt(z);
	}

	number::Number Vector::Angle() const
	{
		Number z = a_ / b_;
		return z.atan();
	}

	number::Number Vector::GetA() const {
		return a_;
	}

	number::Number Vector::GetB() const {
		return b_;
	}

	Vector Vector::Add(Vector& v1, Vector& v2)
	{
		return Vector(v1.GetA() + v2.GetA(), v1.GetB() + v2.GetB());
	}
}

