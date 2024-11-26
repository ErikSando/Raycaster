#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Colour.h"
#include "Camera.h"
#include "Input.h"

namespace Game {
    namespace Settings {
        extern Colour BackgroundColour;
        extern Colour GroundColour;
        extern int MouseSensitivity;
        extern int TileSize;
        extern int WindowWidth;
        extern int WindowHeight;
        extern int LineHeight;
    }

    void Start(const char* title = "Title", int width = 960, int height = 540, bool fullscreen = false);
    SDL_Renderer* GetRenderer();
    Camera& GetCamera();

    extern int mapW, mapH;
    extern int tilemap[];
}