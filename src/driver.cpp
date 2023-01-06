#include <iostream>

#include <RealFunctionAPI/real_function.h>
#include <RealFunctionAPI/polynomial.h>

using namespace std;

int main(){
    RealFunctionAPI::Polynomial p {1,-2};    
    auto der = p.getDerivative();
   
    
    

    return 0;
}
