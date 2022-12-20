#include <iostream>
#include "math/math.hpp"
#include <cmath>

int main() {
    float x, y, z;
    std::cin >> x >> y >> z;
    math::Cartesian3D Ca3D = (math::Vec3){x, y, z};
    
    math::Spherical Sp = Ca3D.ToSpherical();
    
    for (int i = 0; i < 10; i++) {
        Sp = Sp.ToCylindrical().GetVector();
    }

    std::cout << Sp.GetVector().x << " " << Sp.GetVector().y << " " << Sp.GetVector().z << std::endl;

    return 0;
}