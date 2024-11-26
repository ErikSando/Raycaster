#pragma once

#include "Vector2.h"

typedef struct {
    int WallType; // 0 - horizontal, 1 - vertical
    Vector2 position;
    float distance;
    bool hit;

} RaycastResult;

class Ray {
    public:

    Vector2 start;
    double angle;
    int column;

    Ray(Vector2 _start, double _angle, int _column);

    RaycastResult Cast(float MaxDistance = 10000);
};