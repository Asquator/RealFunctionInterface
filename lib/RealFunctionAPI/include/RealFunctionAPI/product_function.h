#ifndef PRODUCT_FUNCTION_H
#define PRODUCT_FUNCTION_H

#include "binary_operation_function.h"

namespace RealFunctionAPI{

class ProductFunction : public BinaryOperationFunction {

    public:
        using BinaryOperationFunction::BinaryOperationFunction;
        ProductFunction(const RealFunction &, const RealFunction &);
        ProductFunction(std::unique_ptr<RealFunction>, std::unique_ptr<RealFunction>);
        ProductFunction *clone() const override;

    private:
        std::unique_ptr<RealFunction> calculateDerivative() const override;
        void print(std::ostream &os) const override;

};

}


#endif