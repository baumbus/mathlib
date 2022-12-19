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

    struct Polar2 {
        float radius;
        float theta;
    };

    struct Polar3 {
        float radius;
        float theta;
        float phi;
    };

    Cartesian2 PolarToCartesian(Polar2 p);
    Cartesian3 PolarToCartesian(Polar3 p);

    Polar2 CartesianToPolar(Cartesian2 c);
    Polar3 CartesianToPolar(Cartesian3 c);
    
} // namespace math
