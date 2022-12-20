#include <iostream>
#include <cmath>

#include "math/vector.hpp"
#include "math/polynomial.hpp"

using namespace math;

int main() {
    
    Linear f{2, 0};
    Linear g{3, 0};
    Linear h = f + g;

    return 0;
}