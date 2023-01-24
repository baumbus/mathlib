#pragma once

#include <cmath>

namespace emath
{
    template <class T>
    struct Vec2
    {
        T x;
        T y;
    };

    template <class T>
    struct Vec3
    {
        T x;
        T y;
        T z;
    };

    template <class T>
    struct Vec4
    {
        T x;
        T y;
        T z;
        T w;
    };

    template <class T>
    struct Linear
    {
        T a, b;

        T operator()(float x) const
        {
            return a * x + b;
        }

        Linear operator+(Linear g) const
        {
            return {a + g.a, b + g.b};
        }
    };

    template <class T>
    struct Cartesian2D : Vec2<T>
    {
        Vec2<T> ToPolar()
        {
            Vec2<T> v;
            v.x = std::sqrt(this->x * this->x + this->y * this->y);
            v.y = std::atan(this->y / this->x);
            return v;
        }
    };

    template <class T>
    struct Polar : Vec2<T>
    {
        Vec2<T> ToCartesian()
        {
            Vec2<T> v;
            v.x = this->x * std::cos(this->y);
            v.y = this->x * std::sin(this->y);
            return v;
        }
    };

    template <class T>
    struct Cartesian3D : Vec3<T>
    {
        Vec3<T> ToSpherical()
        {
            Vec3<T> v;
            v.x = std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(this->z, 2));

            if (this->z > 0)
                v.y = std::atan(std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2)) / this->z);
            if (this->z < 0)
                v.y = M_PI + std::atan(std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2)) / this->z);
            if (this->z == 0 && this->x * this->y != 0)
                v.y = M_PI / 2;
            if (this->x + this->y + this->z == 0)
                v.y = 0;

            if (this->x > 0)
                v.z = std::atan(this->y / this->x);
            if (this->x < 0 && this->y >= 0)
                v.z = std::atan(this->y / this->x) + M_PI;
            if (this->x < 0 && this->y < 0)
                v.z = std::atan(this->y / this->x) - M_PI;
            if (this->x == 0 && this->y > 0)
                v.z = M_PI / 2;
            if (this->x == 0 && this->y < 0)
                v.z = -(M_PI / 2);
            if (this->x == 0 && this->y == 0)
                v.z = 0;

            return v;
        }

        Vec3<T> ToCylindrical()
        {
            Vec3<T> v;
            v.z = this->z;

            v.x = std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));

            v.y = std::atan2(this->y, this->x);

            return v;
        }
    };

    template <class T>
    struct Spherical : Vec3<T>
    {
        Vec3<T> ToCartesian()
        {
            Vec3<T> v;
            v.x = this->x * std::sin(this->y) * std::cos(this->z);
            v.y = this->x * std::sin(this->y) * std::sin(this->z);
            v.z = this->x * std::cos(this->y);
            return v;
        }

        Vec3<T> ToCylindrical()
        {
            Vec3<T> v;

            v.x = this->x * std::sin(this->y);
            v.y = this->z;
            v.z = this->x * std::sin(this->y);

            return v;
        }
    };

    template <class T>
    struct Cylindrical : Vec3<T>
    {
        Vec3<T> ToCartesian()
        {
            Vec3<T> v;
            v.x = this->x * std::cos(this->y);
            v.y = this->x * std::sin(this->y);
            v.z = this->z;
            return v;
        }

        Vec3<T> ToSpherical()
        {
            Vec3<T> v;
            v.x = std::sqrt(std::pow(this->y, 2) + std::pow(this->z, 2));
            v.y = std::atan(this->x / this->z);
            v.z = this->y;
            return v;
        }
    };
}