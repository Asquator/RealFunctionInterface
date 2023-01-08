#include <iostream>

#include <RealFunctionAPI/real_function.h>
#include <RealFunctionAPI/polynomial.h>
#include <RealFunctionAPI/fraction_function.h>

using namespace std;
using namespace RealFunctionAPI;

int main(){
    Polynomial p {1,-2};    
    auto der = p.getDerivative();
   // cout << p << endl << *der << endl;

    FractionFunction frac = FractionFunction{*der, p};

    cout << frac;
    cout << frac(3);

    return 0;
}
