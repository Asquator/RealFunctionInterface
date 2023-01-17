#ifndef SUM_FUNCTION_H
#define SUM_FUNCTION_H

#include <memory>

#include "binary_operation_function.h"
#include "real_function.h"


namespace RealFunctionAPI{
class SumFunction : public BinaryOperationFunction{

    public:
        SumFunction(const RealFunctionBase &, const RealFunctionBase &);
        SumFunction(std::unique_ptr<RealFunctionBase>, std::unique_ptr<RealFunctionBase>);
        SumFunction *clone() const override;
        
    private:
        const RealFunctionBase *calculateDerivative() const override;
        void print(std::ostream &os) const override;
};

}

#endif