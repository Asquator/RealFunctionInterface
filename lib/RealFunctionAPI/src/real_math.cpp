
#include <cmath>
#include "real_math.h"

bool round_compare(real_type x, real_type y){
	return fabs(x - y) < real_epsilon;
}