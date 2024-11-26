#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "Math.h"

class Camera {
    public:

    Vector3 position;
    double FOV = 60;
    double orientation = 0;

    Camera(Vector3 position, double FOV) : position(position), FOV(FOV * Math::DegreesToRadians) {}

    Vector2 Forward();
    Vector2 Right();
};