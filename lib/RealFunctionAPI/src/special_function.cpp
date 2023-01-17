#include <functional>
#include <memory>
#include <cmath>

#include "fraction_function.h"
#include "negated_function.h"
#include "product_function.h"
#include "real_function.h"
#include "real_math.h"
#include "special_function.h"
#include "polynomial.h"


using std::unique_ptr;
using std::map;

namespace RealFunctionAPI_impl {

SpecialFunction::SpecialFunction(Specials specialType,
						const mapping_type &function_mapping,
						const domain_type &domain,
						const std::string &rep):

specialType(specialType), function_mapping(function_mapping), 
					domain(domain), representation(rep) {}


SpecialFunction *SpecialFunction::clone() const {
	return new SpecialFunction(specialType, function_mapping, domain, representation);
}


SpecialFunction::SpecialFunction(Specials type):
	SpecialFunction(specialFunctions[type]) {}


map<SpecialFunction::Specials, SpecialFunction> SpecialFunction::specialFunctions {
	{Specials::Exp, SpecialFunction(Specials::Exp, exp, 
									[](real_type){return true;}, "exp")},
	{Specials::Ln, SpecialFunction(Specials::Ln, log, 
									[](real_type x){return x > 0;}, "ln")},
	{Specials::Sin, SpecialFunction(Specials::Sin, sin, 
									[](real_type){return true;}, "sin")},
	{Specials::Cos, SpecialFunction(Specials::Cos, cos, 
									[](real_type){return true;}, "cos")},
	{Specials::Tan, SpecialFunction(Specials::Tan, tan,
									[](real_type x){return !round_compare(cos(x), 0);}, "tan")}
};


bool SpecialFunction::isDefined(real_type x) const {return domain(x);}

real_type SpecialFunction::operator()(real_type x) const {return function_mapping(x);}


void SpecialFunction::print(std::ostream &os) const {
	os << representation;
}


const RealFunctionBase *SpecialFunction::calculateDerivative() const {
	return calculateDerivative(specialType);
}


RealFunctionBase *SpecialFunction::calculateDerivative(Specials type) {
	switch (type) {
        case Specials::Exp:
			return new SpecialFunction(Specials::Exp);
			break;

        case Specials::Ln:
			return new FractionFunction{unique_ptr<RealFunctionBase>(new Polynomial{1}),
										unique_ptr<RealFunctionBase>(new Polynomial{0,1})};
			break;

        case Specials::Sin:
			return new SpecialFunction(specialFunctions[Specials::Cos]);
			break;

        case Specials::Cos:
			return new NegatedFunction(specialFunctions[Specials::Sin]);
			break;
			
        case Specials::Tan:
			return new FractionFunction{unique_ptr<RealFunctionBase>{new Polynomial{1}}, 
										unique_ptr<RealFunctionBase>{new ProductFunction{
												unique_ptr<RealFunctionBase>{new SpecialFunction{Specials::Cos}}, 
												unique_ptr<RealFunctionBase>{new SpecialFunction{Specials::Cos}}
																						}
																		}
										};
        	break;

        default:
			return nullptr;

		}
		
}

}  