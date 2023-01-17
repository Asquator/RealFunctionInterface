#include <functional>
#include <memory>
#include <iostream>

#include "binary_operation_function.h"

using std::unique_ptr;

namespace RealFunctionAPI_impl{



BinaryOperationFunction::BinaryOperationFunction(unique_ptr<RealFunctionBase> left,
                                                unique_ptr<RealFunctionBase> right,
                                                const operation_type &op):
    leftOperand{std::move(left)}, rightOperand{std::move(right)}, operation{op} {}


BinaryOperationFunction::BinaryOperationFunction(const RealFunctionBase &left,
                                                const RealFunctionBase &right,
                                                const operation_type &op):
    BinaryOperationFunction(unique_ptr<RealFunctionBase>(left.clone()), unique_ptr<RealFunctionBase>(right.clone()), op){}

real_type BinaryOperationFunction::operator()(real_type x) const {
    return operation((*leftOperand)(x), (*rightOperand)(x));
}

bool BinaryOperationFunction::isDefined(real_type x) const {
    return leftOperand->isDefined(x) &&
    rightOperand->isDefined(x);
}




}
