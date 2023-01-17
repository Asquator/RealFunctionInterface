#include <iostream>

#include <RealFunctionAPI/real_function.h>

#include <memory>

using namespace std;
using namespace RealFunctionAPI;

int main(){
	RealFunction func = createSpecialFunction(Specials::Cos);
	RealFunction pol = createPolynomial({2,4,5});

	RealFunction der = func.getDerivativeCopy(); //-sin

	RealFunction target = func * pol + der;

	cout << target << endl;
	RealFunction target_der = target.getDerivativeCopy();
	cout << target_der << endl;
	//cout << target << endl << target_der << endl;

	cout << target(2) << "  " << target_der(2) << endl;

	return 0;
}
