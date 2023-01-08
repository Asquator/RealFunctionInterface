#include <functional>
#include <memory>
#include <iostream>

#include "binary_operation_function.h"

using std::unique_ptr;
using real_type = RealFunctionAPI::RealFunction::real_type;


namespace RealFunctionAPI{


BinaryOperationFunction::BinaryOperationFunction(unique_ptr<RealFunction> left, 
                                                unique_ptr<RealFunction> right, 
                                                const operation_type &op):
    leftOperand{std::move(left)}, rightOperand{std::move(right)}, operation{op} {}


BinaryOperationFunction::BinaryOperationFunction(const RealFunction &left,
                                                const RealFunction &right, 
                                                const operation_type &op):
    BinaryOperationFunction(unique_ptr<RealFunction>(left.clone()), unique_ptr<RealFunction>(right.clone()), op){} 

real_type BinaryOperationFunction::operator()(real_type x) const {
    return operation((*leftOperand)(x), (*rightOperand)(x));
}

bool BinaryOperationFunction::isDefined(real_type x) const {
    return leftOperand->isDefined(x) &&
    rightOperand->isDefined(x);
}



}