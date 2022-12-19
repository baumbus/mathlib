#include <iostream>
#include "math/coords.hpp"

int main() {
    math::Polar2 polar;
    math::Cartesian2 cartesian;

    std::cin >> cartesian.x >> cartesian.y;
    polar = math::CartesianToPolar(cartesian);
    std::cout << "R: " << polar.radius << "\nTheta: " << polar.theta << std::endl;
    return 0;
}