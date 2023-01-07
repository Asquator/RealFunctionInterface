#include <iostream>

#include <RealFunctionAPI/real_function.h>
#include <RealFunctionAPI/polynomial.h>

using namespace std;

int main(){
    RealFunctionAPI::Polynomial p {1,-2};    
    auto &de= p.getDerivative();
    cout << p << endl << de << endl;
    cout << *(p + de) << endl;
    return 0;
}
