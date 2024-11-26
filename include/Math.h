#pragma once

#include <cmath>

namespace Math {
    extern double PI;
    extern double TwoPI;
    
    extern double DegreesToRadians;
    extern double RadiansToDegrees;

    template<typename T>
    T Min(T a, T b);

    template<typename T>
    T Max(T a, T b);

    template<typename T>
    T Clamp(T value, T min, T max);

    float Lerp(float a, float b, float t);
    // float Sqrt(float n);
    // float Cbrt(float n);

    double Root(double n, double root);
    // double Log10(double n);
    // double Ln(double n);
    double Log(double base, double n);

    double NormaliseAngle(double angle);
}