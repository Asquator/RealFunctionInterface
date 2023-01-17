#include <functional>
#include <memory>

#include "binary_operation_function.h"
#include "product_function.h"
#include "sum_function.h"

using std::ostream;
using std::unique_ptr;


namespace RealFunctionAPI {

ProductFunction::ProductFunction(unique_ptr<RealFunctionBase> left, unique_ptr<RealFunctionBase> right):
    BinaryOperationFunction(std::move(left), std::move(right), std::multiplies<real_type>()) {}


ProductFunction::ProductFunction(const RealFunctionBase &left, const RealFunctionBase &right):
    BinaryOperationFunction(left, right, std::multiplies<real_type>()){}


ProductFunction *ProductFunction::clone() const {
    return new ProductFunction{*this};
}


void ProductFunction::print(ostream &os) const{
    os << "(" << *getLeftOperand() << ") * (" << *getRightOperand() << ")";  
}

/**
 * @brief Calculating the derivative of a product function using the Leibniz rule
 * 
 * @return std::unique_ptr<RealFunctionBase> unique pointer to the derivative
 */
const RealFunctionBase *ProductFunction::calculateDerivative() const {

    /*Applying Leibniz rule to calculate the derivative of a product*/

    unique_ptr<RealFunctionBase> prod1 { new ProductFunction{*(getLeftOperand()->getDerivative()), *getRightOperand()}};
    unique_ptr<RealFunctionBase> prod2 { new ProductFunction{*getLeftOperand(), *(getRightOperand()->getDerivative())}};
    return new SumFunction{std::move(prod1), std::move(prod2)};
}

}
