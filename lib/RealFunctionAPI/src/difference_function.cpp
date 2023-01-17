
#include <memory>
#include <ostream>

#include "binary_operation_function.h"
#include "real_function.h"
#include "difference_function.h"

using std::unique_ptr;

namespace RealFunctionAPI{

DifferenceFunction::DifferenceFunction(unique_ptr<RealFunctionBase> left, unique_ptr<RealFunctionBase> right):
    BinaryOperationFunction(std::move(left), std::move(right), std::plus<real_type>()) {}


DifferenceFunction::DifferenceFunction(const RealFunctionBase &left, const RealFunctionBase &right):
    BinaryOperationFunction(left, right, std::plus<real_type>()) {}


DifferenceFunction *DifferenceFunction::clone() const{
    return new DifferenceFunction{*this};
};

void DifferenceFunction::print(std::ostream &os) const{
    os << *getLeftOperand() << " - " << *getRightOperand();
}


const RealFunctionBase *DifferenceFunction::calculateDerivative() const {
    return new DifferenceFunction{ *(getLeftOperand()->getDerivative()), *(getRightOperand()->getDerivative())};
}

}
