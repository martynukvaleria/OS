#pragma once
#include <cmath>
#include <windows.h>

#ifdef VECTOR_EXPORTS
#define VECTOR_API __declspec(dllexport)
#else
#define VECTOR_API __declspec(dllimport)
#endif

#include <Number.h>


namespace vector {

	class VECTOR_API Vector {
	public:
		using Number = number::Number;
		Vector(Number a, Number b);
		Vector(const Vector&) = default;
		Number Radius() const;
		Number Angle() const;
		Number GetA() const;
		Number GetB()const;
		static Vector Add(Vector& v1, Vector& v2);

	private:

		Number a_;
		Number b_;
	};

	const VECTOR_API Vector zero_vector;
	const VECTOR_API Vector one_vector;

}