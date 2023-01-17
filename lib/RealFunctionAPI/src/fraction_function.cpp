#include <functional>
#include <memory>
#include <ostream>

#include "binary_operation_function.h"
#include "difference_function.h"
#include "fraction_function.h"
#include "product_function.h"
#include "real_function.h"
#include "real_math.h"


using std::ostream;
using std::unique_ptr;

namespace RealFunctionAPI {

FractionFunction::FractionFunction(const RealFunctionBase &left, const RealFunctionBase &right):
    BinaryOperationFunction(left, right, std::divides<real_type>()){}

FractionFunction::FractionFunction(unique_ptr<RealFunctionBase> left, unique_ptr<RealFunctionBase> right):
    BinaryOperationFunction(std::move(left), std::move(right), std::divides<real_type>()) {}


FractionFunction *FractionFunction::clone() const {
    return new FractionFunction{*this};
}


void FractionFunction::print(ostream &os) const{
    os << "(" << *getLeftOperand() << ") / (" << *getRightOperand() << ")";  
}


bool FractionFunction::isDefined(real_type x) const {
    return BinaryOperationFunction::isDefined(x) && !round_compare(x, 0);
}


/*
 * Using the rule to calculate a derivative of fraction to construct the derivative
*/
const RealFunctionBase *FractionFunction::calculateDerivative() const {

    unique_ptr<RealFunctionBase> prod1 {new ProductFunction{ *(getLeftOperand()->getDerivative()), *getRightOperand()} };
    unique_ptr<RealFunctionBase> prod2 {new ProductFunction{ *getLeftOperand(), *(getRightOperand()->getDerivative())} };

    unique_ptr<RealFunctionBase> numerator {new DifferenceFunction{std::move(prod1), std::move(prod2)}};
    unique_ptr<RealFunctionBase> denominator {new ProductFunction{*getRightOperand(), *getRightOperand()}};

    return new FractionFunction{std::move(numerator), std::move(denominator)};
}

}