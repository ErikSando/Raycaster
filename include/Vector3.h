#pragma once

#include <iostream>
#include <cmath>

//#include "Math.h" // this line fixes some problems some how

class Vector3 {
    public:
    
    float x, y, z;

    Vector3() : x(0.0), y(0.0), z(0.0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    float magnitude() { return sqrt(x * x + y * y + z * z); }

    Vector3 normalised() { return Vector3(x / magnitude(), y / magnitude(), z / magnitude()); } // DELETE THE VECTOR YOU ASSIGN THIS TO LATER!!!!!

    float dot(const Vector3& v);
    float cross(const Vector3& v);

    friend std::ostream& operator<<(std::ostream& os, const Vector3& v);

    friend Vector3& operator*(const Vector3& v, const float n);
    friend Vector3& operator/(const Vector3& v, const float n);
    friend Vector3& operator+(const Vector3& v1, const Vector3& v2);
    friend Vector3& operator-(const Vector3& v1, const Vector3& v2);

    friend bool operator==(const Vector3& v1, const Vector3& v2);
    friend bool operator!=(const Vector3& v1, const Vector3& v2);

    friend Vector3& operator-(const Vector3& v);

    Vector3& operator*=(const float n);
    Vector3& operator/=(const float n);
    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(const Vector3& v);

    private:

    Vector3& Multiply(const float n);
    Vector3& Divide(const float n);
    Vector3& Add(const Vector3& v);
    Vector3& Subtract(const Vector3& v);
    Vector3& Inverse();
};