#ifndef BINARY_OPERATION_FUNCTION_H
#define BINARY_OPERATION_FUNCTION_H

#include <functional>
#include <memory>
#include <ostream>
#include <string>

#include "real_function.h"

namespace RealFunctionAPI{
class BinaryOperationFunction : public RealFunctionBase{

    using operation_type = std::function<real_type (real_type, real_type)>;

    private:
        operation_type operation; 
        std::shared_ptr<RealFunctionBase> leftOperand;   
        std::shared_ptr<RealFunctionBase> rightOperand; 

    public:

        BinaryOperationFunction(const RealFunctionBase &, const RealFunctionBase &, const operation_type&);
        BinaryOperationFunction(std::unique_ptr<RealFunctionBase>, std::unique_ptr<RealFunctionBase>, const operation_type &);
                    
        real_type operator()(real_type) const override;
        bool isDefined(real_type) const override;

    protected: 
        inline std::shared_ptr<const RealFunctionBase> getLeftOperand() const {return leftOperand;}
        inline std::shared_ptr<const RealFunctionBase> getRightOperand() const {return rightOperand;};
        
};


}

#endif
