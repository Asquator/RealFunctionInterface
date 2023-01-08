
#include <memory>

#include "real_function.h"

using namespace std;

namespace RealFunctionAPI{

RealFunction::~RealFunction(){};


/*
 * Manually defined copy control members: making a deep copy of the derivative
 

 
RealFunction::RealFunction(const RealFunction &other):
    derivative(other.getDerivative()->clone()){}

RealFunction &RealFunction::operator=(const RealFunction &other){
    derivative.reset(other.getDerivative()->clone());
    return *this;
}
*/

const std::shared_ptr<const RealFunction> RealFunction::getDerivative() const{
    if(!derivative)
        derivative = calculateDerivative();

    return derivative;    
}

ostream &operator<<(ostream &os, const RealFunction &func){
    func.print(os);
    return os;
}

/**
 * @brief Return a sum of functions
 * @param left 
 * @param right 
 * @return std::unique_ptr<RealFunction> a unique pointer to a sum real function object
 */
 

}