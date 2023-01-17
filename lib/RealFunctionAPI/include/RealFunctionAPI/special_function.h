#ifndef POOL_FUNCTION_H
#define POOL_FUNCTION_H

#include <functional>
#include <memory>
#include <map>

#include "real_function_base.h"


namespace RealFunctionAPI_impl {

class SpecialFunction : public RealFunctionBase {
		
	public:

		SpecialFunction() = default;
		
		enum class Specials{
			Exp, Ln,
			Sin, Cos, Tan
		};

	private:

		using mapping_type = std::function<real_type(real_type)>;
		using domain_type = std::function<bool(real_type)>;

		Specials specialType;
		
		mapping_type function_mapping;
		domain_type domain;
		std::string representation;

		SpecialFunction(Specials,
					const mapping_type &function_mapping,
					const domain_type &domain,
					const std::string &rep);

		//map of special function entities
	 	static std::map<Specials, SpecialFunction> specialFunctions;

		//calculate derivative of a special
		static RealFunctionBase *calculateDerivative(Specials);

		const RealFunctionBase *calculateDerivative() const final;

	
	public:

		SpecialFunction(Specials);

		SpecialFunction *clone() const override;

		bool isDefined(real_type) const override;

		real_type operator()(real_type) const override;

		void print(std::ostream &) const override;


};

}

#endif