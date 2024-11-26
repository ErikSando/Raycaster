#pragma once

class Tilemap {
    public:

    int width;
    int height;
    int tilemap[];

    Tilemap(int width, int height) : width(width), height(height) {}

    int TileAt(int x, int y);
};