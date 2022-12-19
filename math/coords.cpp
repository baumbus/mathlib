#include "coords.hpp"
#include <cmath>

math::Cartesian2 math::PolarToCartesian(Polar2 p) {
    Cartesian2 c;
    c.x = p.radius * std::cos(p.theta);
    c.y = p.radius * std::sin(p.theta);
    return c;
};

math::Polar2 math::CartesianToPolar(Cartesian2 c) {
    Polar2 p;
    p.radius = std::sqrt(c.x * c.x + c.y * c.y);
    p.theta = std::atan(c.y/c.x);
    return p;
};