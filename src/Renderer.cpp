#include <iostream>
#include <vector>

#include "Game.h"
#include "Renderer.h"
#include "Ray.h"
#include "Math.h"

Renderer::Renderer(int resolution) {
    resolution = resolution;

    HorizontalColour = Colour(180, 180, 180);
    VerticalColour = Colour(200, 200, 200);
}

void Renderer::Render(SDL_Renderer* renderer, Camera& camera) {
    //std::vector<Ray*> rays;
    // when using a list of rays, every ray in the list became equal to the last ray and i couldnt figure out how to fix it

    Colour* groundColour = &Game::Settings::GroundColour;

    int LineHeight = Game::Settings::LineHeight;
    int WindowWidth = Game::Settings::WindowWidth;
    int WindowHeight = Game::Settings::WindowHeight;

    SDL_Rect groundRect;
    groundRect.x = 0;
    groundRect.y = ceil(WindowHeight / 2);
    groundRect.w = WindowWidth;
    groundRect.h = floor(WindowHeight / 2);

    SDL_SetRenderDrawColor(renderer, groundColour->r, groundColour->g, groundColour->b, groundColour->a);
    SDL_RenderFillRect(renderer, &groundRect);
    
    int column = 0;

    for (double angle = camera.orientation - camera.FOV / 2; angle <= camera.orientation + camera.FOV / 2; angle += camera.FOV / WindowWidth * resolution, column++) {
        Vector2 position(camera.position.x, camera.position.y);
        Ray ray(position, angle, column);
        RaycastResult result = ray.Cast();

        if (!result.hit) continue;

        double _angle = Math::NormaliseAngle(camera.orientation) - ray.angle;
        Colour colour = result.WallType ? HorizontalColour : VerticalColour;

        double lineHeight = LineHeight * WindowHeight / result.distance / camera.FOV / cos(_angle);
        double centre = WindowHeight / 2 + camera.position.z / result.distance;
        double top = centre - lineHeight / 2;
        double bottom = centre + lineHeight / 2;
        
        SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
        SDL_RenderDrawLine(renderer, ray.column * resolution, top, ray.column * resolution, bottom);
    }
}