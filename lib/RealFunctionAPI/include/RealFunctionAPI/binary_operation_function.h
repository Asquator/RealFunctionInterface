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
        std::shared_ptr<RealFunction> leftOperand;   
        std::shared_ptr<RealFunction> rightOperand; 

    public:
        BinaryOperationFunction(const RealFunction &, const RealFunction &, const std::function<real_type (real_type, real_type)> &);

        BinaryOperationFunction(std::unique_ptr<RealFunction>, std::unique_ptr<RealFunction>, 
                    const std::function<real_type (real_type, real_type)> &);
                    
        real_type operator()(real_type) const override;
        bool isDefined(real_type) const override;

    protected: 
        inline std::shared_ptr<const RealFunction> getLeftOperand() const {return leftOperand;}
        inline std::shared_ptr<const RealFunction> getRightOperand() const {return rightOperand;};
        
};


}

#endif
