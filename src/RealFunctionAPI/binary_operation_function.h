#ifndef BINARY_OPERATION_FUNCTION_H
#define BINARY_OPERATION_FUNCTION_H

#include <functional>
#include <memory>
#include <ostream>
#include <string>

#include "real_function.h"

namespace RealFunctionAPI{
class BinaryOperationFunction : public RealFunction{

    private:
        std::function<real_type (const real_type &, const real_type &)> operation; 
        std::unique_ptr<RealFunction> leftOperand;   
        std::unique_ptr<RealFunction> rightOperand; 

    public:
        BinaryOperationFunction(const RealFunction&, const RealFunction&, const std::function<real_type (real_type, real_type)> &);
        real_type operator()(real_type) const override;
        bool isDefined(real_type) const override;

    protected:
        const inline RealFunction &getLeftOperand() const {return *leftOperand;};
        const inline RealFunction &getRightOperand() const {return *rightOperand;};
        
};

}

#endif
