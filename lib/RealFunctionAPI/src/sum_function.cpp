
#include <memory>
#include <ostream>

#include "sum_function.h"

using std::unique_ptr;

namespace RealFunctionAPI{

SumFunction::SumFunction(unique_ptr<RealFunctionBase> left, unique_ptr<RealFunctionBase> right):
    BinaryOperationFunction(std::move(left), std::move(right), std::plus<real_type>()) {}


SumFunction::SumFunction(const RealFunctionBase &left, const RealFunctionBase &right):
    BinaryOperationFunction(left, right, std::plus<real_type>()) {}


SumFunction *SumFunction::clone() const{
    return new SumFunction{*this};
};

void SumFunction::print(std::ostream &os) const{
    os << *getLeftOperand() << " + " << *getRightOperand();
}


const RealFunctionBase *SumFunction::calculateDerivative() const {
   return new SumFunction{ *(getLeftOperand()->getDerivative()), *(getRightOperand()->getDerivative()) };
}

}