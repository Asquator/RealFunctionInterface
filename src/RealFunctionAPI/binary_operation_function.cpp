#include <functional>
#include <memory>

#include "binary_operation_function.h"
#include "real_function.h"

using std::function;
using real_type = RealFunction::real_type;

BinaryOperationFunction::BinaryOperationFunction(const RealFunction &left, const RealFunction &right, const function<real_type(real_type, real_type)> &op):
operation(op), leftOperand(left.clone()), rightOperand(right.clone()) {}

real_type BinaryOperationFunction::operator()(real_type x) const {
    return operation((*leftOperand)(x), (*rightOperand)(x));
}


bool BinaryOperationFunction::isDefined(real_type x) const {
    return leftOperand->isDefined(x) &&
    rightOperand->isDefined(x);
}

/*
const RealFunction &BinaryOperationFunction::getLeftOperand() const{
    return *leftOperand;
}

const RealFunction &BinaryOperationFunction::getRightOperand() const{
    return *rightOperand;
}

*/