#include <iostream>
#include <cmath>

#include "math/vector.hpp"
#include "math/polynomial.hpp"

int main() {
    using std::cout;

    math::Linear f{2, 0};
    math::Linear g{3, 0};
    math::Linear h = f + g;

    cout << h(123) << '\n';

    return 0;
}