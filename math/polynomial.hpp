#pragma once

#include <cmath>

namespace math {

    struct Linear {
        float a, b;

        float operator()(float x) const {
            return a * x + b;
        }

        Linear operator+(Linear g) const {
            return {a + g.a, b + g.b};
        }
    };

    struct Quadratic {
        float a, b, c;

        float operator()(float x) const {
            return a * std::pow(x, 2) + b * x + c;
        }
    };

    struct Qubic {
        float a, b, c, d;

        float operator()(float x) const {
            return a * std::pow(x, 3) + b * std::pow(x, 2) + c * x + d;
        }
    };
};