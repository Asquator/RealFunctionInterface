#include <iostream>

#include "real_function.h"
#include "polynomial.h"

using namespace std;

int main(){
    Polynomial p {1,-2};    
    auto der = p.getDerivative();

    cout << "Pol: " << p << endl;
    cout << "Der: " << *der << endl;

    cout << (*der)(2);
    auto fc = der->clone();
    

    return 0;
}
