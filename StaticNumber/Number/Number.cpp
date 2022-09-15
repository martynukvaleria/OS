#include "Number.h"
#include <cmath>

namespace number{
    Number::Number(double value) : value_(value) {}

    Number::Number(const Number& SameNum)
    {
        value_ = SameNum.value_;
    }

    const Number Number::Add(const Number& Number_)
    {
        return value_ + Number_.value_;
    }

    const Number Number::Subtract(const Number& Number_)
    {
        return value_ - Number_.value_;
    }

    const Number Number::Multiply(const Number& Number_)
    {
        return value_ * Number_.value_;
    }

    const Number Number::Divide(const Number& Number_)
    {
        return value_ / Number_.value_;
    }
    Number Number::sqrt()
    {
        return Number(std::sqrt(value_));
    }

    Number Number::atan()
    {
        return Number(std::atan(value_));
    }
   
    Number::operator double() const
    {
        return value_; 
    }
    
    Number GetNum(double value)
    {
        return Number(value);
    }
}