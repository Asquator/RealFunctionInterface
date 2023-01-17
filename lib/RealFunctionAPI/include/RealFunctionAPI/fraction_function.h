#ifndef FRACTION_FUNCTION_H
#define FRACTION_FUNCTION_H

#include "binary_operation_function.h"
#include <memory>
#include <ostream>

namespace RealFunctionAPI_impl{

class FractionFunction : public BinaryOperationFunction {

    public:

        FractionFunction(const RealFunctionBase &, const RealFunctionBase &);
        FractionFunction(std::unique_ptr<RealFunctionBase>, std::unique_ptr<RealFunctionBase>);

        FractionFunction *clone() const override;

        bool isDefined(real_type) const override;


    private:
        const RealFunctionBase *calculateDerivative() const override;
        void print(std::ostream &os) const override;

};

}


#endif
