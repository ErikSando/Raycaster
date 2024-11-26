#include "Tilemap.h"

int Tilemap::TileAt(int x, int y) {
    return tilemap[y * width + x];
}