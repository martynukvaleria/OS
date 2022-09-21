#pragma once

namespace number
{

    class Number {

    public:

        Number(double value);

        Number(const Number& Number_);

        const Number Add(const Number& Number_);

        const Number Subtract(const Number& Number_);

        const Number Multiply(const Number& Number_);

        const Number Divide(const Number& Number_);

        Number sqrt();

        Number atan();

        operator double() const;

    private:

        double value_;
   
    };
    
    const int zero = 0;

    const int one = 1;

    Number GetNum(double value);

    

}
