#include "real_function.h"
#include <memory>

using namespace std;

RealFunction::~RealFunction(){}

shared_ptr<const RealFunction> RealFunction::getDerivative(){
    if(!derivative)
        derivative = calculateDerivative();

    return derivative;    
}

ostream &operator<<(ostream &os, const RealFunction &func){
    return func.print(os);
}
