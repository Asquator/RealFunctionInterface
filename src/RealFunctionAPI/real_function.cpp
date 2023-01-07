
#include <memory>

#include "real_function.h"
#include "sum_function.h"

using namespace std;

namespace RealFunctionAPI{

RealFunction::~RealFunction(){};

const RealFunction &RealFunction::getDerivative() const{
    if(!derivative)
        derivative = calculateDerivative();

    return *derivative;    
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
 std::unique_ptr<RealFunction> operator+(const RealFunction &left, const RealFunction &right){
    std::unique_ptr<RealFunction> ret {new SumFunction {left, right}};
    return ret;
 }


}