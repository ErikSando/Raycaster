#include "Math.h"

namespace Math {
    double PI = 3.14159265358979323846; // no point in adding more decimals
    double TwoPI = 2 * PI;

    double DegreesToRadians = PI / 180;
    double RadiansToDegrees = 180 / PI;

    template<typename T>
    T Min(T a, T b) {
        return a < b ? a : b;
    }

    template<typename T>
    T Max(T a, T b) {
        return a > b ? a : b;
    }

    template<typename T>
    T Clamp(T value, T min, T max) {
        return Min<T>(Max<T>(value, min), max);
    }

    float Lerp(float a, float b, float t) {
        return a + (b - a) * t;
    }

    // float Sqrt(float n) {
    //     return sqrt(n);
    // }

    // float Cbrt(float n) {
    //     return cbrt(n);
    // }

    // double Pow(double n, double power) {
    //     return pow(n, power);
    // }

    double Root(double n, double root) {
        return pow(n, 1 / root);
    }

    // double Log10(double n) {
    //     return log10(n);
    // }

    // double Ln(double n) {
    //     return log(n);
    // }

    double Log(double base, double n) {
        return log(n) / log(base);
    }

    double NormaliseAngle(double angle) {
        if (angle >= TwoPI) {
            angle = std::fmod(angle, TwoPI);
        }
        else if (angle < 0) {
            while (angle < 0) {
                angle += TwoPI;
            }
        }

        return angle;
    }
}