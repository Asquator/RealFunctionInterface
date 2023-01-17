#ifndef REAL_FUNCTION_H
#define REAL_FUNCTION_H


#include <memory>
#include <ostream>
#include "real_math.h"
#include "real_function_base.h"

namespace RealFunctionAPI{


class RealFunction{

	private:
	
		std::unique_ptr<RealFunctionBase> functionPtr = nullptr;
	
	public:
		
		explicit RealFunction(std::unique_ptr<RealFunctionBase>);
		friend std::ostream &operator<<(std::ostream &, const RealFunction &);
		
		RealFunction(const RealFunction &);
		RealFunction &operator=(const RealFunction &);

		RealFunction(RealFunction &&) = default;
		RealFunction &operator=(RealFunction &&) = default;

		/**
		 * @brief Get the copy of the derivative
		 * @return RealFunction Copy of the derivative object
		 */
		RealFunction getDerivativeCopy() const;


		bool isDefined(real_type) const;

		real_type operator()(real_type) const;

		bool isDifferentiable(real_type) const;

		real_type diff(real_type x);



		/*
		Lvalue-reference assymetric operators
		*/
		RealFunction &operator+=(const RealFunction &);
		RealFunction &operator-=(const RealFunction &);
		RealFunction &operator*=(const RealFunction &);
		RealFunction &operator/=(const RealFunction &);

		/*
		Rvalue-reference assymetric operators
		*/
		RealFunction &operator+=(RealFunction &&);
		RealFunction &operator-=(RealFunction &&);
		RealFunction &operator*=(RealFunction &&);
		RealFunction &operator/=(RealFunction &&);


		friend RealFunction operator+(const RealFunction&, const RealFunction&);
		friend RealFunction operator+(const RealFunction&&, const RealFunction&);
		friend RealFunction operator+(const RealFunction&, const RealFunction&&);
		
		friend RealFunction operator-(const RealFunction&, const RealFunction&);
		friend RealFunction operator-(const RealFunction&&, const RealFunction&);
		friend RealFunction operator-(const RealFunction&, const RealFunction&&);

		friend RealFunction operator*(const RealFunction&, const RealFunction&);
		friend RealFunction operator*(const RealFunction&&, const RealFunction&);
		friend RealFunction operator*(const RealFunction&, const RealFunction&&);

		friend RealFunction operator/(const RealFunction&, const RealFunction&);
		friend RealFunction operator/(const RealFunction&&, const RealFunction&);
		friend RealFunction operator/(const RealFunction&, const RealFunction&&);

		friend RealFunction operator-(const RealFunction&);
		friend RealFunction operator-(RealFunction&&);
		

};


/*
Operators on real function wrapper
*/

RealFunction operator+(const RealFunction&, const RealFunction&);
RealFunction operator+(const RealFunction&&, const RealFunction&);
RealFunction operator+(const RealFunction&, const RealFunction&&);

RealFunction operator-(const RealFunction&, const RealFunction&);
RealFunction operator-(const RealFunction&&, const RealFunction&);
RealFunction operator-(const RealFunction&, const RealFunction&&);

RealFunction operator*(const RealFunction&, const RealFunction&);
RealFunction operator*(const RealFunction&&, const RealFunction&);
RealFunction operator*(const RealFunction&, const RealFunction&&);

RealFunction operator/(const RealFunction&, const RealFunction&);
RealFunction operator/(const RealFunction&&, const RealFunction&);
RealFunction operator/(const RealFunction&, const RealFunction&&);

RealFunction operator-(const RealFunction&);
RealFunction operator-(RealFunction&&);
}

#endif