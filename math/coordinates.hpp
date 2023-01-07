#pragma once

#include "vector.hpp"

#include <cmath>

namespace math {
    class Cartesian2D;
    class Polar;
    class Cartesian3D;
    class Spherical;
    class Cylindrical;

    class Cartesian2D {
        float x;
        float y;

        public:
            Cartesian2D(Vec2 v) {
                x = v.x;
                y = v.y;
            }

            Vec2 GetVector() {
                return { x, y };
            }

            Polar ToPolar() {
                Vec2 v;
                v.x = std::sqrt(x * x + y * y);
                v.y = std::atan(y/x);
                return (Polar)v; 
            }
    };

    class Polar {
        float radius;
        float theta;

        public:
            Polar(Vec2 v) {
                radius = v.x;
                theta = v.y;
            }

            Vec2 GetVector() {
                return { radius, theta };
            }
            
            Cartesian2D ToCartesian() {
                Vec2 v;
                v.x = radius * std::cos(theta);
                v.y = radius * std::sin(theta);
                return (Cartesian2D)v;
            }
    };

    class Cartesian3D {
        float x;
        float y;
        float z;

        public:
            Cartesian3D(Vec3 v) {
                x = v.x;
                y = v.y;
                z = v.z;
            }

            Vec3 GetVector() {
                return { x, y, z };
            }
            
            Spherical ToSpherical() {
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

            Cylindrical ToCylindrical() {
                Vec3 v;
                v.z = z;

                v.x = std::sqrt(std::pow(x, 2) + std::pow(y, 2));

                v.y = std::atan2(y, x);

                return (Cylindrical)v;
            }
    };

    class Spherical {
        float radius;
        float theta;
        float phi;

        public:
            Spherical(Vec3 v) {
                radius = v.x;
                theta = v.y;
                phi = v.z;
            }

            Vec3 GetVector() {
                return { radius, theta, phi };
            }

            Cartesian3D ToCartesian() {
                Vec3 v;
                v.x = radius * std::sin(theta) * std::cos(phi);
                v.y = radius * std::sin(theta) * std::sin(phi);
                v.z = radius * std::cos(theta);
                return (Cartesian3D)v;
            }

            Cylindrical ToCylindrical() {
                Vec3 v;

                v.x = radius * std::sin(theta);
                v.y = phi;
                v.z = radius * std::sin(theta);

                return (Cylindrical)v;
            }
    };

    class Cylindrical {
        float rho;
        float phi;
        float z;

        public:
            Cylindrical(Vec3 v) {
                rho = v.x;
                phi = v.y;
                z = v.z;
            }

            Vec3 GetVector() {
                return { rho, phi, z};
            }

            Cartesian3D ToCartesian() {
                Vec3 v;
                v.x = rho * std::cos(phi);
                v.y = rho * std::sin(phi);
                v.z = z;
                return (Cartesian3D)v;
            }

            Spherical ToSpherical() {
                Vec3 v;
                v.x = std::sqrt(std::pow(phi, 2) + std::pow(z, 2));
                v.y = std::atan(rho/z);
                v.z = phi;
                return (Spherical)v;
            }
    };
} // namespace math
