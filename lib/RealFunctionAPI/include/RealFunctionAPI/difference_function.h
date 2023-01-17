#ifndef DIFFERENCE_FUNCTION_H
#define DIFFERENCE_FUNCTION_H

#include <memory>

#include "binary_operation_function.h"
#include "real_function.h"

namespace RealFunctionAPI{
class DifferenceFunction : public BinaryOperationFunction{

    public:
        DifferenceFunction(const RealFunctionBase &, const RealFunctionBase &);
        DifferenceFunction(std::unique_ptr<RealFunctionBase>, std::unique_ptr<RealFunctionBase>);
        DifferenceFunction *clone() const override;
        
    private:
        const RealFunctionBase *calculateDerivative() const override;
        void print(std::ostream &os) const override;
};

}

#endif