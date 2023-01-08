#include "fraction_function.h"
#include "binary_operation_function.h"
#include "real_function.h"
#include <memory>
#include <ostream>

using std::ostream;

namespace RealFunctionAPI {

FractionFunction::FractionFunction(const RealFunction &left, const RealFunction &right):
BinaryOperationFunction(left, right, std::divides<real_type>()){}

FractionFunction *FractionFunction::clone() const {
    return new FractionFunction(getLeftOperand(), getRightOperand());
}

void FractionFunction::print(ostream &os) const{
    os << "(" << getLeftOperand() << ") / (" << getRightOperand() << ")";  
}

std::unique_ptr<RealFunction> FractionFunction::calculateDerivative() const {
    std::unique_ptr<RealFunction> derivative {
        

    }
}

}