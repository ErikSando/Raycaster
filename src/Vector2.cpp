#include "Vector2.h"

float Vector2::magnitude() {
    return sqrt(x * x + y * y);
}

Vector2& Vector2::normalised() {
    Vector2 temp(x, y);

    return magnitude() != 0 ? temp.Divide(magnitude()) : temp.Multiply(1);
}

float Vector2::dot(const Vector2& v) {
    return 0;
}

float Vector2::cross(const Vector2& v) {
    return 0;
}

float Vector2::DistanceFrom(const Vector2& v) {
    return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
}

float Vector2::DistanceBetween(const Vector2& v1, const Vector2& v2) {
    return sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

Vector2& Vector2::Multiply(const float n) {
    x *= n;
    y *= n;

    /*Vector2* newVec = this;

    x /= n;
    y /= n;*/

    return *this;
}

Vector2& Vector2::Divide(const float n) {
    x /= n;
    y /= n;

    return *this;
}

Vector2& Vector2::Add(const Vector2& v) {
    x += v.x;
    y += v.y;

    return *this;
}

Vector2& Vector2::Subtract(const Vector2& v) {
    x -= v.x;
    y -= v.y;

    return *this;
}

Vector2& Vector2::Inverse() {
    x = -x;
    y = -y;
    
    return *this;
}

Vector2& operator*(const Vector2& v, const float n) {
    Vector2 temp(v);
    return temp.Multiply(n);
}

Vector2& operator/(const Vector2& v, const float n) {
    Vector2 temp(v);
    return temp.Divide(n);
}

Vector2& operator+(const Vector2& v1, const Vector2& v2) {
    Vector2 temp(v1.x, v1.y);
    return temp.Add(v2);
}

Vector2& operator-(const Vector2& v1, const Vector2& v2) {
    Vector2 temp(v1);
    return temp.Subtract(v2);
}

Vector2& Vector2::operator*=(const float n) {
    x *= n;
    y *= n;

    return *this;
}

Vector2& Vector2::operator/=(const float n) {
    x /= n;
    y /= n;

    return *this;
}

Vector2& Vector2::operator+=(const Vector2& v) {
    x += v.x;
    y += v.y;

    return *this;
}

Vector2& Vector2::operator-=(const Vector2& v) {
    x -= v.x;
    y -= v.y;

    return *this;
}

Vector2& operator-(const Vector2& v) {
    Vector2 temp(v);
    return temp.Inverse();
}

bool operator==(const Vector2& v1, const Vector2& v2) {
    return (v1.x == v2.x && v1.y == v2.y);
}

bool operator!=(const Vector2& v1, const Vector2& v2) {
    return (v1.x != v2.x || v1.y != v2.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}