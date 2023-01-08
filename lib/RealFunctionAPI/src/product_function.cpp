#include "product_function.h"
#include "sum_function.h"
#include "binary_operation_function.h"
#include <functional>
#include <memory>


using std::ostream;
using std::unique_ptr;


namespace RealFunctionAPI {

ProductFunction::ProductFunction(const RealFunction &left, const RealFunction &right):
    BinaryOperationFunction(left, right, std::divides<real_type>()){}


ProductFunction::ProductFunction(unique_ptr<RealFunction> left, unique_ptr<RealFunction> right):
    BinaryOperationFunction(std::move(left), std::move(right), std::multiplies<real_type>()){}


ProductFunction *ProductFunction::clone() const {
    return new ProductFunction(unique_ptr<RealFunction>(getLeftOperand()->clone()), 
                                unique_ptr<RealFunction>(getRightOperand()->clone()));
}


void ProductFunction::print(ostream &os) const{
    os << "(" << getLeftOperand() << ") * (" << getRightOperand() << ")";  
}

/**
 * @brief Calculating the derivative of a product function using the Leibniz rule
 * 
 * @return std::unique_ptr<RealFunction> unique pointer to the derivative
 */
unique_ptr<RealFunction> ProductFunction::calculateDerivative() const {

    /*Applying Leibniz rule to calculate the derivative of a product*/

    unique_ptr<RealFunction> prod1 { new ProductFunction{*(getLeftOperand()->getDerivative()), *getRightOperand()}};
    unique_ptr<RealFunction> prod2 { new ProductFunction{*getLeftOperand(), *(getRightOperand()->getDerivative())}};
    unique_ptr<RealFunction> derivative {new SumFunction{std::move(prod1), std::move(prod2)}};
    return derivative;
}

}