
#include <functional>
#include <memory>
#include <ostream>

#include "negated_function.h"
#include "real_function.h"

#include "difference_function.h"
#include "fraction_function.h"
#include "product_function.h"
#include "sum_function.h"

using namespace std;

namespace RealFunctionAPI{

RealFunctionBase::~RealFunctionBase(){}

std::shared_ptr<const RealFunctionBase> RealFunctionBase::getDerivative() const{
    if(!derivative)
        derivative.reset(calculateDerivative());

    return derivative;    
}

ostream &operator<<(ostream &os, const RealFunctionBase &func){
    func.print(os);
    return os;
}


/*Real function wrapper*/

RealFunction::RealFunction(unique_ptr<RealFunctionBase> ptr):
    functionPtr(std::move(ptr)){}

RealFunction::RealFunction(const RealFunction &other):
    functionPtr(unique_ptr<RealFunctionBase>(other.functionPtr->clone())) {}

RealFunction &RealFunction::operator=(const RealFunction &other){
    functionPtr = unique_ptr<RealFunctionBase>(other.functionPtr->clone());
    return *this;
}

RealFunction RealFunction::getDerivativeCopy() const{
    return RealFunction(unique_ptr<RealFunctionBase>(functionPtr->clone()));
}


bool RealFunction::isDefined(real_type x) const{
    return functionPtr->isDefined(x);
}

bool RealFunction::isDifferentiable(real_type x) const{
    return functionPtr->getDerivative()->isDefined(x);
}

real_type RealFunction::diff(real_type x){
    return functionPtr->getDerivative()->operator()(x);
}

ostream &operator<<(ostream &os, const RealFunction &func){
    return (os << *func.functionPtr);
}

/*
Assignment real function operators
*/


/*
Lvalue-reference assymetric operators
*/
RealFunction &RealFunction::operator+=(const RealFunction &other){
    functionPtr = unique_ptr<RealFunctionBase>( //moving the existing unique_ptr and copying the argument
        new SumFunction(std::move(functionPtr), unique_ptr<RealFunctionBase>(other.functionPtr->clone())));
    return *this;
}


RealFunction &RealFunction::operator-=(const RealFunction &other){
    functionPtr = unique_ptr<RealFunctionBase>( //moving the existing unique_ptr and copying the argument
        new DifferenceFunction(std::move(functionPtr), unique_ptr<RealFunctionBase>(other.functionPtr->clone())));
    return *this;
}

RealFunction &RealFunction::operator*=(const RealFunction &other){
    functionPtr = unique_ptr<RealFunctionBase>( //moving the existing unique_ptr and copying the argument
        new ProductFunction(std::move(functionPtr), unique_ptr<RealFunctionBase>(other.functionPtr->clone())));
    return *this;
}

RealFunction &RealFunction::operator/=(const RealFunction &other){
    functionPtr = unique_ptr<RealFunctionBase>( //moving the existing unique_ptr and copying the argument
        new FractionFunction(std::move(functionPtr), unique_ptr<RealFunctionBase>(other.functionPtr->clone())));
    return *this;
}




/*
Rvalue-reference assymetric operators
*/
RealFunction &RealFunction::operator+=(RealFunction &&other){
    functionPtr = unique_ptr<RealFunctionBase>( //moving the existing unique_ptr and the argument
        new SumFunction(std::move(functionPtr), std::move(other.functionPtr)));
    return *this;
}


RealFunction &RealFunction::operator-=(RealFunction &&other){
    functionPtr = unique_ptr<RealFunctionBase>( //moving the existing unique_ptr and the argument
        new DifferenceFunction(std::move(functionPtr), std::move(other.functionPtr)));
    return *this;
}

RealFunction &RealFunction::operator*=(RealFunction &&other){
    functionPtr = unique_ptr<RealFunctionBase>( //moving the existing unique_ptr and the argument
        new ProductFunction(std::move(functionPtr), std::move(other.functionPtr)));
    return *this;
}

RealFunction &RealFunction::operator/=(RealFunction &&other){
    functionPtr = unique_ptr<RealFunctionBase>( //moving the existing unique_ptr and the argument
        new FractionFunction(std::move(functionPtr), std::move(other.functionPtr)));
    return *this;
}



/*
Symmetric real function operators
*/


//SUM
RealFunction operator+(const RealFunction &left, const RealFunction &right){
    RealFunction tmp = left;
    return tmp += right;
}

RealFunction operator+(RealFunction &left, RealFunction &&right){
    RealFunction tmp = left;
    return tmp += std::move(right);
}

RealFunction operator+(RealFunction &&left, RealFunction &right){
    RealFunction tmp = right;
    return tmp += std::move(left);
}

//DIFFERENCE
RealFunction operator-(const RealFunction &left, const RealFunction &right){
    RealFunction tmp = left;
    return tmp -= right;
}

RealFunction operator-(RealFunction &left, RealFunction &&right){
    RealFunction tmp = left;
    return tmp -= std::move(right);
}

RealFunction operator-(RealFunction &&left, RealFunction &right){
    RealFunction tmp = right;
    return tmp -= std::move(left);
}

//PRODUCT
RealFunction operator*(const RealFunction &left, const RealFunction &right){
    RealFunction tmp = left;
    return tmp *= right;
}

RealFunction operator*(RealFunction &left, RealFunction &&right){
    RealFunction tmp = left;
    return tmp *= std::move(right);
}

RealFunction operator*(RealFunction &&left, RealFunction &right){
    RealFunction tmp = right;
    return tmp *= std::move(left);
}


//FRACTION
RealFunction operator/(const RealFunction &left, const RealFunction &right){
    RealFunction tmp = left;
    return tmp /= right;
}

RealFunction operator/(RealFunction &left, RealFunction &&right){
    RealFunction tmp = left;
    return tmp /= std::move(right);
}

RealFunction operator/(RealFunction &&left, RealFunction &right){
    RealFunction tmp = right;
    return tmp /= std::move(left);
}



RealFunction operator-(const RealFunction &op){
    return RealFunction(unique_ptr<RealFunctionBase>(new NegatedFunction(*op.functionPtr)));
}

RealFunction operator-(RealFunction &&op){
    return RealFunction(unique_ptr<RealFunctionBase>(new NegatedFunction(std::move(op.functionPtr))));
}

}