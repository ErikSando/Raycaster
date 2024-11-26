#pragma once

#include <iostream>
#include <cmath>

//#include "Math.h" // this line fixes some problems some how

class Vector2 {
    public:
    
    float x, y;

    Vector2() : x(0.0), y(0.0) {}
    Vector2(float x, float y) : x(x), y(y) {}

    float magnitude();
    Vector2& normalised(); // DELETE THE VECTOR YOU ASSIGN THIS TO LATER!!!!!

    float dot(const Vector2& v);
    float cross(const Vector2& v);

    float DistanceFrom(const Vector2& v);

    friend std::ostream& operator<<(std::ostream& os, const Vector2& v);

    friend Vector2& operator*(const Vector2& v, const float n);
    friend Vector2& operator/(const Vector2& v, const float n);
    friend Vector2& operator+(const Vector2& v1, const Vector2& v2);
    friend Vector2& operator-(const Vector2& v1, const Vector2& v2);

    friend bool operator==(const Vector2& v1, const Vector2& v2);
    friend bool operator!=(const Vector2& v1, const Vector2& v2);

    friend Vector2& operator-(const Vector2& v);

    Vector2& operator*=(const float n);
    Vector2& operator/=(const float n);
    Vector2& operator+=(const Vector2& v);
    Vector2& operator-=(const Vector2& v);

    static Vector2 Zero() { return Vector2(0, 0); }
    static Vector2 One() { return Vector2(1, 1); }
    static Vector2 Left() { return Vector2(-1, 0); }
    static Vector2 Right() { return Vector2(1, 0); }
    static Vector2 Up() { return Vector2(0, -1); }
    static Vector2 Down() { return Vector2(0, 1); }
    
    static float DistanceBetween(const Vector2& v1, const Vector2& v2);

    private:

    Vector2& Multiply(const float n);
    Vector2& Divide(const float n);
    Vector2& Add(const Vector2& v);
    Vector2& Subtract(const Vector2& v);
    Vector2& Inverse();
};