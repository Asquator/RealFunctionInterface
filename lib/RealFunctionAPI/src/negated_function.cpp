#include "negated_function.h"
#include "binary_operation_function.h"
#include "real_function.h"
#include <memory>
#include <ostream>


using std::unique_ptr;

namespace RealFunctionAPI {


NegatedFunction::NegatedFunction(std::unique_ptr<RealFunctionBase> other):
	operand(std::move(other)) {}


NegatedFunction::NegatedFunction(const RealFunctionBase &other):
	operand(unique_ptr<RealFunctionBase>(other.clone())){}


RealFunctionBase *NegatedFunction::clone() const {
	return new NegatedFunction(*this);
}

bool NegatedFunction::isDefined(real_type x) const {
	return operand->isDefined(x);
}

real_type NegatedFunction::operator()(real_type x) const{
	return -(*operand)(x);
}

void NegatedFunction::print(std::ostream &os) const{
	os << "-" << *operand;
}

const RealFunctionBase *NegatedFunction::calculateDerivative() const{
	return new NegatedFunction{std::unique_ptr<RealFunctionBase>(operand->clone())};
}

}