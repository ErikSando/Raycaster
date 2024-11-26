#pragma once

#include <cstdint>

struct Colour {
    int r, g, b, a;

    Colour(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255) : r(r), g(g), b(b), a(a) {}

    static Colour Red() { return Colour(255); }
    static Colour Green() { return Colour(0, 255); }
    static Colour Blue() { return Colour(0, 0, 255); }
    static Colour Yellow() { return Colour(255, 255, 0); }
    static Colour Magenta() { return Colour(255, 0, 255); }
    static Colour Cyan() { return Colour(0, 255, 255); }
    static Colour White() { return Colour(255, 255, 255); }
    static Colour Black() { return Colour(0, 0, 0); }
};