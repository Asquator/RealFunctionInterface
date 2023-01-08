#include <functional>
#include <memory>
#include <ostream>

#include "binary_operation_function.h"
#include "difference_function.h"
#include "fraction_function.h"
#include "product_function.h"
#include "real_function.h"


using std::ostream;
using std::unique_ptr;

namespace RealFunctionAPI {

FractionFunction::FractionFunction(const RealFunction &left, const RealFunction &right):
    BinaryOperationFunction(left, right, std::divides<real_type>()){}

FractionFunction::FractionFunction(unique_ptr<RealFunction> left, unique_ptr<RealFunction> right):
    BinaryOperationFunction(std::move(left), std::move(right), std::divides<real_type>()) {}


FractionFunction *FractionFunction::clone() const {
    return new FractionFunction(*getLeftOperand(), *getRightOperand());
}


void FractionFunction::print(ostream &os) const{
    os << "(" << *getLeftOperand() << ") / (" << *getRightOperand() << ")";  
}


bool FractionFunction::isDefined(real_type x) const {
    return BinaryOperationFunction::isDefined(x) && (*this)(x);
}


/*
 * Using the rule to calculate a derivative of fraction to construct the derivative
*/
unique_ptr<RealFunction> FractionFunction::calculateDerivative() const {

    unique_ptr<RealFunction> prod1 {new ProductFunction{ *(getLeftOperand()->getDerivative()), *getRightOperand()} };
    unique_ptr<RealFunction> prod2 {new ProductFunction{ *getLeftOperand(), *(getRightOperand()->getDerivative())} };

    unique_ptr<RealFunction> numerator {new DifferenceFunction{std::move(prod1), std::move(prod2)}};
    unique_ptr<RealFunction> denominator {new ProductFunction{*getRightOperand(), *getRightOperand()}};

    unique_ptr<RealFunction> derivative {new FractionFunction{std::move(numerator), std::move(denominator)}};

    return derivative;
}

}