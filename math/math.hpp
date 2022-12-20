#pragma once

namespace math
{
    class Cartesian2D;
    class Polar;
    class Cartesian3D;
    class Spherical;
    class Cylindrical;

    struct Vec2 {
        float x;
        float y;
    };

    struct Vec3 {
        float x;
        float y;
        float z;
    };

    class Cartesian2D {
        float x;
        float y;

        public:
            Cartesian2D(Vec2 v);

            Vec2 GetVector();

            Polar ToPolar();
    };

    class Polar {
        float radius;
        float theta;

        public:
            Polar(Vec2 v);

            Vec2 GetVector();
            
            Cartesian2D ToCartesian();
    };

    class Cartesian3D {
        float x;
        float y;
        float z;

        public:
            Cartesian3D(Vec3 v);

            Vec3 GetVector();
            
            Spherical ToSpherical();
            Cylindrical ToCylindrical();
    };

    class Spherical {
        float radius;
        float theta;
        float phi;

        public:
            Spherical(Vec3 v);

            Vec3 GetVector();

            Cartesian3D ToCartesian();
            Cylindrical ToCylindrical();
    };

    class Cylindrical {
        float rho;
        float phi;
        float z;

        public:
            Cylindrical(Vec3 v);

            Vec3 GetVector();

            Cartesian3D ToCartesian();
            Spherical ToSpherical();
    };
} // namespace math
