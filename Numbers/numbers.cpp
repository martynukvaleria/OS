#include "numbers.h"
#include <cmath>

namespace number {
    Number::Number(double value) : value_(value) {}

    Number::Number(const Number &SameNum) {
        value_ = SameNum.value_;
    }

    Number Number::Add(const Number &Number_) const {
        return value_ + Number_.value_;
    }

    Number Number::Subtract(const Number &Number_) const {
        return value_ - Number_.value_;
    }

    Number Number::Multiply(const Number &Number_) const {
        return value_ * Number_.value_;
    }

    Number Number::Divide(const Number &Number_) const {
        return value_ / Number_.value_;
    }

    Number Number::sqrt() const {
        return {std::sqrt(value_)};
    }

    Number Number::atan() const {
        return {std::atan(value_)};
    }

    Number::operator double() const {
        return value_;
    }

    double Number::GetValue() const {
        return value_;
    }

    Number GetNum(double value) {
        return {value};
    }
}


