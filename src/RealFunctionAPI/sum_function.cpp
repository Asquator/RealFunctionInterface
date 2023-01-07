
#include <memory>
#include <ostream>
#include "sum_function.h"

namespace RealFunctionAPI{

SumFunction::SumFunction(const RealFunction &left, const RealFunction &right):
BinaryOperationFunction(left, right, std::plus<real_type>()) {}

SumFunction *SumFunction::clone() const{
    return new SumFunction(getLeftOperand(), getRightOperand());
};

void SumFunction::print(std::ostream &os) const{
    os << getLeftOperand() << "+" << getRightOperand();
}

std::unique_ptr<RealFunction> SumFunction::calculateDerivative() const{
    std::unique_ptr<RealFunction> derivative {
       new SumFunction {getLeftOperand().getDerivative(), 
                        getRightOperand().getDerivative()}};
    return derivative;
}

}