#include "Camera.h"
#include "Math.h"

Vector2 Camera::Forward() {
    return Vector2(cos(orientation), sin(orientation));
}

Vector2 Camera::Right() {
    return Vector2(cos(orientation + Math::PI / 2), sin(orientation + Math::PI / 2));
}