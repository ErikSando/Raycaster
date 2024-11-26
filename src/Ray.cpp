#include <iostream>

#include "Ray.h"
#include "Math.h"
#include "Game.h"

using namespace Math;

Ray::Ray(Vector2 _start, double _angle, int _column) {
    start = _start;
    angle = NormaliseAngle(_angle);
    column = _column;
}

RaycastResult Ray::Cast(float MaxDistance) {
    int WindowWidth = Game::Settings::WindowWidth;
    int WindowHeight = Game::Settings::WindowHeight;
    int TileSize = Game::Settings::TileSize;

    // HORIZONTAL RAYCAST

    bool horizontalHit = false;
    int horizontalHitX = 0, horizontalHitY = 0;

    float firstHitX, firstHitY;

    bool facingUp = angle > PI && angle < TwoPI;
    bool facingDown = angle > 0 && angle < PI;

    if (facingUp) firstHitY = floor(start.y / TileSize) * TileSize - 0.01;
    else if (facingDown) firstHitY = floor(start.y / TileSize) * TileSize + TileSize;

    firstHitX = start.x + (firstHitY - start.y) / tan(angle);

    float nextX = firstHitX, nextY = firstHitY;
    float yStep = 0, xStep = 0;;

    bool skip = false;

    if (facingUp) yStep = -TileSize;
    else if (facingDown) yStep = TileSize;
    else skip = true;

    xStep = yStep / tan(angle);

    if (!skip) {
        while (nextX >= 0 && nextX <= Game::mapW * TileSize && nextY >= 0 && nextY <= Game::mapH * TileSize) {
            int tilePosX = floor(nextX / TileSize);
            int tilePosY = floor(nextY / TileSize);
            
            if (Game::tilemap[tilePosY * Game::mapW + tilePosX]) {
                horizontalHit = true;
                horizontalHitX = nextX;
                horizontalHitY = nextY;
                break;
            }
            else {
                nextX += xStep;
                nextY += yStep;
            }
        }
    }

    // VERTICAL RAYCAST

    bool verticalHit = false;
    int verticalHitX = 0, verticalHitY = 0;

    bool facingRight = (angle > 3 * PI / 2 && angle <= TwoPI) || (angle >= 0 && angle < PI / 2);
    bool facingLeft = angle > PI / 2 && angle < 3 * PI / 2;

    if (facingRight) firstHitX = floor(start.x / TileSize) * TileSize + TileSize;
    else if (facingLeft) firstHitX = floor(start.x / TileSize) * TileSize - 0.01;

    firstHitY = start.y + (firstHitX - start.x) * tan(angle);

    nextX = firstHitX, nextY = firstHitY;

    skip = false;

    if (facingRight) xStep = TileSize;
    else if (facingLeft) xStep = -TileSize;
    else skip = true;

    yStep = xStep * tan(angle);

    if (!skip) {
        while (nextX >= 0 && nextX <= Game::mapW * TileSize && nextY >= 0 && nextY <= Game::mapH * TileSize) {
            int tilePosX = floor(nextX / TileSize);
            int tilePosY = floor(nextY / TileSize);
            
            if (Game::tilemap[tilePosY * Game::mapW + tilePosX]) {
                verticalHit = true;
                verticalHitX = nextX;
                verticalHitY = nextY;
                break;
            }
            else {
                nextX += xStep;
                nextY += yStep;
            }
        }
    }

    float horizontalDistance = 0, verticalDistance = 0;

    Vector2 horizontalHitPos(horizontalHitX, horizontalHitY);
    Vector2 verticalHitPos(verticalHitX, verticalHitY);

    if (horizontalHit) horizontalDistance = Vector2::DistanceBetween(start, horizontalHitPos);
    else horizontalDistance = MaxDistance;

    if (verticalHit) verticalDistance = Vector2::DistanceBetween(start, verticalHitPos);
    else verticalDistance = MaxDistance;

    RaycastResult result;
    result.hit = horizontalHit || verticalHit;

    if (!result.hit) return result;

    if (horizontalDistance < verticalDistance) {
        result.distance = horizontalDistance;
        result.position = horizontalHitPos;
        //result.WallType = 0;
    }
    else {
        result.distance = verticalDistance;
        result.position = verticalHitPos;
        result.WallType = 1;
    }

    return result;
}