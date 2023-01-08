#ifndef DIFFERENCE_FUNCTION_H
#define DIFFERENCE_FUNCTION_H

#include <memory>

#include "binary_operation_function.h"
#include "real_function.h"

namespace RealFunctionAPI{
class DifferenceFunction : public BinaryOperationFunction{

    public:
        DifferenceFunction(const RealFunction &, const RealFunction &);
        DifferenceFunction(std::unique_ptr<RealFunction>, std::unique_ptr<RealFunction>);
        DifferenceFunction *clone() const override;
        
    private:
        std::unique_ptr<RealFunction> calculateDerivative() const override;
        void print(std::ostream &os) const override;
};

}

#endif