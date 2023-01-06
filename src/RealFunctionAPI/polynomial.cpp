#include "polynomial.h"
#include <memory>
#include <ostream>

using namespace std;
using real_type = RealFunctionAPI::RealFunction::real_type;


namespace RealFunctionAPI{
/**
 * @brief Construct a default zero Polynomial
 * 
 */
Polynomial::Polynomial() : coefficients{0}{};


/**
 * @brief Construct a new Polynomial from initializer list
 * 
 * @param coefficients_list initializer list of coefficients
 */
Polynomial::Polynomial(initializer_list<real_type> coefficients_list) : 
coefficients(coefficients_list) {

    //preserving the invariant: at least one coefficient should exist
    if(coefficients.size() == 0)
        coefficients = {0};
    reduce();
}



/**
 * @brief Construct a new Polynomial from a given vector
 * 
 * @param coefficients_vector vector of coefficients
 */
Polynomial::Polynomial(const vector<real_type> &coefficients_vector) : 
coefficients(coefficients_vector) {
    reduce();
}

/**
 * @brief Remove trailing zeroes from the vector of coefficients
 * 
 */
void Polynomial::reduce(){
    //remove trailing 0 elements except the first one
    while(coefficients.size() > 1 && coefficients.back() == 0)
        coefficients.pop_back();
    coefficients.shrink_to_fit();
}



/**
 * @brief  Compute the Polynomial value at a point
 * Apply Horner rule to calculate the value in linear time
 * @param x given point
 * @return real_type Polynomial value
 */
real_type Polynomial::operator()(real_type x) const {
    real_type val = 0;
    
    for(auto p = coefficients.crbegin(); p != coefficients.crend(); ++p)
        val = x * val + *p;

    return val;
}


ostream &Polynomial::print(ostream &os) const{
    os << coefficients[0] << (coefficients.size() > 1 ? " + " : "");

    for(vector<real_type>::size_type i = 1; i < coefficients.size(); i++)
        os << coefficients[i] << Polynomial::variableName << "^" << i
        << (i < coefficients.size() - 1 ? " + " : "");

    return os;
}


/**
 * @brief Return true iff the Polynomial equals to zero
 * 
 */
bool Polynomial::isZero() const{
    return coefficients.size() == 1 && coefficients[0] == 0;
}


/**
 * @brief Return degree of the polynomial. Zero polynomial is said to have 0 degree.
 * @return int degree of the polynomial
*/
vector<real_type>::size_type Polynomial::getDegree() const{
    return coefficients.size() - 1;
}



Polynomial *Polynomial::clone() const {
    return new Polynomial(coefficients);
}



unique_ptr<RealFunction> Polynomial::calculateDerivative() {
    Polynomial *deriv = new Polynomial;
   
    //if the polynomial isn't const
    if(getDegree()){
        deriv->coefficients = {};
        for(auto c = coefficients.begin() + 1; c != coefficients.end(); ++c)
            deriv->coefficients.push_back(*c);
    }
    
    return unique_ptr<RealFunction> {deriv};
}

}