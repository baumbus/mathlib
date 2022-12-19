#pragma once

namespace math
{
    struct Cartesian2 {
        float x;
        float y;
    };

    struct Cartesian3 {
        float x;
        float y;
        float z;
    };

    struct Polar {
        float radius;
        float theta;
    };

    struct Spherical {
        float radius;
        float theta;
        float phi;
    };

    Cartesian2 PolarToCartesian(Polar p);
    Cartesian3 SphericalToCartesian(Spherical p);

    Polar CartesianToPolar(Cartesian2 c);
    Spherical CartesianToPolar(Cartesian3 c);
    
} // namespace math
