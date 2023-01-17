#ifndef PRODUCT_FUNCTION_H
#define PRODUCT_FUNCTION_H

#include "binary_operation_function.h"

namespace RealFunctionAPI_impl{

class ProductFunction : public BinaryOperationFunction {

    public:
        ProductFunction(std::unique_ptr<RealFunctionBase>, std::unique_ptr<RealFunctionBase>);
        ProductFunction(const RealFunctionBase &, const RealFunctionBase &);
        ProductFunction *clone() const override;

    private:
        const RealFunctionBase *calculateDerivative() const override;
        void print(std::ostream &os) const override;

};

}


#endif