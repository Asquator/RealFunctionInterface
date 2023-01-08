
#include <memory>
#include <ostream>

#include "binary_operation_function.h"
#include "real_function.h"
#include "difference_function.h"

using std::unique_ptr;

namespace RealFunctionAPI{

DifferenceFunction::DifferenceFunction(unique_ptr<RealFunction> left, unique_ptr<RealFunction> right):
    BinaryOperationFunction(std::move(left), std::move(right), std::plus<real_type>()) {}


DifferenceFunction::DifferenceFunction(const RealFunction &left, const RealFunction &right):
    BinaryOperationFunction(left, right, std::plus<real_type>()) {}


DifferenceFunction *DifferenceFunction::clone() const{
    return new DifferenceFunction{*getLeftOperand(), *getRightOperand()};
};

void DifferenceFunction::print(std::ostream &os) const{
    os << *getLeftOperand() << "-" << *getRightOperand();
}


std::unique_ptr<RealFunction> DifferenceFunction::calculateDerivative() const {
    unique_ptr<RealFunction> derivative { new DifferenceFunction{ *(getLeftOperand()->getDerivative()), *(getRightOperand()->getDerivative()) } };
    return derivative;
}

}