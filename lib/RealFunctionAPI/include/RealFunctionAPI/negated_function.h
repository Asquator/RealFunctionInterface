#ifndef NEGATED_FUNCTION_H
#define NEGATED_FUNCTION_H


#include <memory>
#include "real_function.h"

namespace RealFunctionAPI {

	class NegatedFunction : public RealFunctionBase {

		private:
			std::shared_ptr<RealFunctionBase> operand;

			const RealFunctionBase * calculateDerivative() const override;
			void print(std::ostream &) const override;

		public:

			NegatedFunction(std::unique_ptr<RealFunctionBase>);
			NegatedFunction(const RealFunctionBase &);

			RealFunctionBase * clone() const override;
			bool isDefined(real_type) const override;
			real_type operator()(real_type) const override;
			

	};

}



#endif