#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <initializer_list>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>

#include "real_function.h"

/*
Polynomial: represents a real valued polynomial function
a class invariant is a reduced vector with polynomial coefficients without trailing zeroes
*/
class Polynomial : public RealFunction {

    public:
        using real_type = RealFunction::real_type;
        static const char variableName = 'x'; 

        /*constructors*/
        Polynomial();
        explicit Polynomial(std::initializer_list<real_type>);
        explicit Polynomial(const std::vector<real_type> &);

        /*
        copy control is inherited from RealFunction.
        as polynomials are copied/moved from other polynomials, the invariant is always preserved
        */

        Polynomial *clone() const override;

        inline std::vector<real_type>::size_type getDegree() const;
        inline bool isZero() const;
        
        /**
         * @brief Compute the Polynomial value at a point
         * 
         * @return real_type Polynomial value
         */
        real_type operator()(real_type) const override;

    private:
        std::vector<real_type> coefficients;
        void reduce();

        std::unique_ptr<RealFunction> calculateDerivative() override;

    protected:
        std::ostream &print(std::ostream &os) const override;
};

#endif