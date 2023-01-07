#include "binary_operation_function.h"
#include "real_function.h"
#include <memory>

namespace RealFunctionAPI{
class SumFunction : public BinaryOperationFunction{

    public:
        SumFunction(const RealFunction &, const RealFunction &);
        SumFunction *clone() const override;
        
    private:
        std::unique_ptr<RealFunction> calculateDerivative() const override;
        void print(std::ostream &os) const override;
};

}