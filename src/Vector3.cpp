#include "Vector3.h"

float Vector3::dot(const Vector3& v) {
    return 0;
}

float Vector3::cross(const Vector3& v) {
    return 0;
}

Vector3& Vector3::Multiply(const float n) {
    x *= n;
    y *= n;
    z *= n;

    /*Vector3* newVec = this;

    x /= n;
    y /= n;*/

    return *this;
}

Vector3& Vector3::Divide(const float n) {
    x /= n;
    y /= n;
    z /= n;

    return *this;
}

Vector3& Vector3::Add(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

Vector3& Vector3::Subtract(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

Vector3& Vector3::Inverse() {
    x = -x;
    y = -y;
    z = -z;
    
    return *this;
}

Vector3& operator*(const Vector3& v, const float n) {
    Vector3 temp(v);
    return temp.Multiply(n);
}

Vector3& operator/(const Vector3& v, const float n) {
    Vector3 temp(v);
    return temp.Divide(n);
}

Vector3& operator+(const Vector3& v1, const Vector3& v2) {
    Vector3 temp(v1);
    return temp.Add(v2);
}

Vector3& operator-(const Vector3& v1, const Vector3& v2) {
    Vector3 temp(v1);
    return temp.Subtract(v2);
}

Vector3& Vector3::operator*=(const float n) {
    x *= n;
    y *= n;
    z *= n;

    return *this;
}

Vector3& Vector3::operator/=(const float n) {
    x /= n;
    y /= n;
    z /= n;

    return *this;
}

Vector3& Vector3::operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

Vector3& operator-(const Vector3& v) {
    Vector3 temp(v);
    return temp.Inverse();
}

bool operator==(const Vector3& v1, const Vector3& v2) {
    return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

bool operator!=(const Vector3& v1, const Vector3& v2) {
    return (v1.x != v2.x || v1.y != v2.y || v1.z != v2.z);
}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}