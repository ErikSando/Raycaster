#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Colour.h"
#include "Math.h"
#include "Camera.h"

class Renderer {
    public:

    int resolution = 1;

    Colour HorizontalColour;
    Colour VerticalColour;

    Renderer(int resolution);

    void Render(SDL_Renderer* renderer, Camera& camera);
};