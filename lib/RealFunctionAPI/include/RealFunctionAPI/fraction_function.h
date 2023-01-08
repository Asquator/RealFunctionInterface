#ifndef FRACTION_FUNCTION_H
#define FRACTION_FUNCTION_H

#include "binary_operation_function.h"
#include <memory>
#include <ostream>

namespace RealFunctionAPI{

class FractionFunction : public BinaryOperationFunction {

    public:

        FractionFunction(const RealFunction &, const RealFunction &);
        FractionFunction(std::unique_ptr<RealFunction>, std::unique_ptr<RealFunction>);

        FractionFunction *clone() const override;

        bool isDefined(real_type) const override;


    private:
        std::unique_ptr<RealFunction> calculateDerivative() const override;
        void print(std::ostream &os) const override;

};

}


#endif