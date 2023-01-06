#include "binary_operation_function.h"
#include "real_function.h"
#include <memory>

class SumFunction : public BinaryOperationFunction{

    public:
        SumFunction(const RealFunction &, const RealFunction &);
        bool isDefined(real_type) const override;

    private:
        std::unique_ptr<RealFunction> calculateDerivative() override;

};