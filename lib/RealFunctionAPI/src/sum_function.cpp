
#include <memory>
#include <ostream>

#include "binary_operation_function.h"
#include "real_function.h"
#include "sum_function.h"

using std::unique_ptr;

namespace RealFunctionAPI{

SumFunction::SumFunction(unique_ptr<RealFunction> left, unique_ptr<RealFunction> right):
    BinaryOperationFunction(std::move(left), std::move(right), std::plus<real_type>()) {}


SumFunction::SumFunction(const RealFunction &left, const RealFunction &right):
    BinaryOperationFunction(left, right, std::plus<real_type>()) {}


SumFunction *SumFunction::clone() const{
    return new SumFunction{unique_ptr<RealFunction>{getLeftOperand()->clone()}, 
                            unique_ptr<RealFunction>{getRightOperand()->clone()}};
};

void SumFunction::print(std::ostream &os) const{
    os << *getLeftOperand() << "+" << *getRightOperand();
}


std::unique_ptr<RealFunction> SumFunction::calculateDerivative() const {
    unique_ptr<RealFunction> derivative { new SumFunction{ *(getLeftOperand()->getDerivative()), *(getRightOperand()->getDerivative()) } };
    return derivative;
}

}