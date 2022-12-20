#include "math.hpp"
#include <cmath>

math::Cartesian2D::Cartesian2D(Vec2 v) {
    x = v.x;
    y = v.y;
};

math::Vec2 math::Cartesian2D::GetVector() {
    return { x, y };
};

math::Polar math::Cartesian2D::ToPolar() {
    Vec2 v;
    v.x = std::sqrt(x * x + y * y);
    v.y = std::atan(y/x);
    return (Polar)v;
}

math::Polar::Polar(Vec2 v) {
    radius = v.x;
    theta = v.y;
};

math::Vec2 math::Polar::GetVector() {
    return { radius, theta };
};

math::Cartesian2D math::Polar::ToCartesian() {
    Vec2 v;
    v.x = radius * std::cos(theta);
    v.y = radius * std::sin(theta);
    return (Cartesian2D)v;
};

math::Cartesian3D::Cartesian3D(Vec3 v) {
    x = v.x;
    y = v.y;
    z = v.z;
};

math::Vec3 math::Cartesian3D::GetVector() {
    return { x, y, z };
};

math::Spherical math::Cartesian3D::ToSpherical() {
    Vec3 v;
    v.x = std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));

    if (z > 0)
        v.y = std::atan(std::sqrt(std::pow(x, 2) + std::pow(y, 2))/z);
    if (z < 0)
        v.y = M_PI + std::atan(std::sqrt(std::pow(x, 2) + std::pow(y, 2))/z);
    if (z == 0 && x * y != 0)
        v.y = M_PI / 2;
    if (x + y + z == 0)
        v.y = 0;

    if (x > 0)
        v.z = std::atan(y / x);
    if (x < 0 && y >= 0)
        v.z = std::atan(y / x) + M_PI;
    if (x < 0 && y < 0)
        v.z = std::atan(y / x) - M_PI;
    if (x == 0 && y > 0)
        v.z = M_PI / 2;
    if (x == 0 && y < 0)
        v.z = -(M_PI / 2);
    if (x == 0 && y == 0)
        v.z = 0;

    return (Spherical)v;
}

math::Cylindrical math::Cartesian3D::ToCylindrical() {
    Vec3 v;
    v.z = z;

    v.x = std::sqrt(std::pow(x, 2) + std::pow(y, 2));

    v.y = std::atan2(y, x);

    return (Cylindrical)v;
};

math::Spherical::Spherical(Vec3 v) {
    radius = v.x;
    theta = v.y;
    phi = v.z;
};

math::Vec3 math::Spherical::GetVector() {
    return { radius, theta, phi };
};

math::Cartesian3D math::Spherical::ToCartesian() {
    Vec3 v;
    v.x = radius * std::sin(theta) * std::cos(phi);
    v.y = radius * std::sin(theta) * std::sin(phi);
    v.z = radius * std::cos(theta);
    return (Cartesian3D)v;
};

math::Cylindrical math::Spherical::ToCylindrical() {
    Vec3 v;

    v.x = radius * std::sin(theta);
    v.y = phi;
    v.z = radius * std::sin(theta);

    return (Cylindrical)v;
};

math::Cylindrical::Cylindrical(Vec3 v) {
    rho = v.x;
    phi = v.y;
    z = v.z;
};

math::Vec3 math::Cylindrical::GetVector() {
    return { rho, phi, z};
};

math::Cartesian3D math::Cylindrical::ToCartesian() {
    Vec3 v;
    v.x = rho * std::cos(phi);
    v.y = rho * std::sin(phi);
    v.z = z;
    return (Cartesian3D)v;
};

math::Spherical math::Cylindrical::ToSpherical() {
    Vec3 v;

    v.x = std::sqrt(std::pow(phi, 2) + std::pow(z, 2));
    v.y = std::atan(rho/z);
    v.z = phi;

    return (Spherical)v;
};