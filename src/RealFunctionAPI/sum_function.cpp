#include "sum_function.h"
#include "binary_operation_function.h"
#include "real_function.h"

SumFunction::SumFunction(const RealFunction &left, const RealFunction &right):
BinaryOperationFunction(left, right, std::plus<real_type>()) {}
