#include "coords.hpp"
#include <cmath>

math::Cartesian2 math::PolarToCartesian(Polar p) {
    Cartesian2 c;
    c.x = p.radius * std::cos(p.theta);
    c.y = p.radius * std::sin(p.theta);
    return c;
};

math::Cartesian3 math::SphericalToCartesian(Spherical p) {
    Cartesian3 c;
    c.x = p.radius * std::sin(p.theta) * std::cos(p.phi);
    c.y = p.radius * std::sin(p.theta) * std::sin(p.phi);
    c.z = p.radius * std::cos(p.theta);
    return c;
};

math::Polar math::CartesianToPolar(Cartesian2 c) {
    Polar p;
    p.radius = std::sqrt(c.x * c.x + c.y * c.y);
    p.theta = std::atan(c.y/c.x);
    return p;
};

math::Spherical math::CartesianToPolar(Cartesian3 c) {
    Spherical p;
    p.radius = std::sqrt(std::pow(c.x, 2) + std::pow(c.y, 2) + std::pow(c.z, 2));

    if (c.z > 0)
        p.theta = std::atan(std::sqrt(std::pow(c.x, 2) + std::pow(c.y, 2))/c.z);
    if (c.z < 0)
        p.theta = M_PI + std::atan(std::sqrt(std::pow(c.x, 2) + std::pow(c.y, 2))/c.z);
    if (c.z == 0 && c.x * c.y != 0)
        p.theta = M_PI / 2;
    if (c.x + c.y + c.z == 0)
        throw "undefined";

    if (c.x > 0)
        p.phi = std::atan(c.y / c.x);
    if (c.x < 0 && c.y >= 0)
        p.phi = std::atan(c.y / c.x) + M_PI;
    if (c.x < 0 && c.y < 0)
        p.phi = std::atan(c.y / c.x) - M_PI;
    if (c.x == 0 && c.y > 0)
        p.phi = M_PI / 2;
    if (c.x == 0 && c.y < 0)
        p.phi = -(M_PI / 2);
    if (c.x == 0 && c.y == 0)
        throw "undefined";

    return p;
};