#ifndef PRODUCT_FUNCTION_H
#define PRODUCT_FUNCTION_H

#include "binary_operation_function.h"

namespace RealFunctionAPI{

class ProductFunction : public BinaryOperationFunction {

    public:
        ProductFunction(std::unique_ptr<RealFunction>, std::unique_ptr<RealFunction>);
        ProductFunction(const RealFunction &, const RealFunction &);
        ProductFunction *clone() const override;

    private:
        std::unique_ptr<RealFunction> calculateDerivative() const override;
        void print(std::ostream &os) const override;

};

}


#endif