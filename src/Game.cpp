#include <iostream>

#include "Game.h"
#include "Renderer.h"
#include "Player.h"

namespace Game {
    namespace Settings {
        Colour BackgroundColour(0, 0, 0);
        Colour GroundColour(100, 100, 100);
        int MouseSensitivity = 100;
        int WindowWidth;
        int WindowHeight;
        int TileSize = 50;
        int LineHeight = 50;
    }

    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Camera camera(Vector3(200.0, 250.0, 0.0), 60.0);
    Renderer _renderer(1);

    bool setup = false;
    bool running = false;

    SDL_Renderer* GetRenderer() {
        return renderer;
    }

    Camera& GetCamera() {
        return camera;
    }

    int px, py, pa; // player x, player y, player angle

    int mapW = 10;
    int mapH = 10;

    int tilemap[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 1, 1, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 1,
        1, 1, 1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 1, 0, 0, 1, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    int GetRefreshRate() {
        int displayIndex = SDL_GetWindowDisplayIndex(window);

        SDL_DisplayMode mode;
        SDL_GetDisplayMode(displayIndex, 0, &mode);

        return mode.refresh_rate;
    }

    void PollEvents() {
        Input::Update();

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYDOWN:
                    Input::HandleKeyDown(event);
                    break;

                case SDL_KEYUP:
                    Input::HandleKeyUp(event);
                    break;

                case SDL_WINDOWEVENT_FOCUS_LOST:
                    Input::Reset();
                    break;
            }
        }
    }

    void Update(const float delta) {
        Player::Update(delta);
    }

    void Render() {
        Colour* bg = &Settings::BackgroundColour;
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, bg->r, bg->g, bg->b, bg->a);
        SDL_RenderFillRect(renderer, nullptr);

        /*
        
        How to draw line:

        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        
        */

        _renderer.Render(renderer, camera);

        SDL_RenderPresent(renderer);
    }

    void Clean() {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        IMG_Quit();
    }

    void Run() {
        if (!setup) {
            Clean();
            return;
        }

        running = true;

        // improve game loop !!!!!!

        const float delay = 1000.0 / GetRefreshRate();
        Uint32 lastUpdate = SDL_GetTicks();
        Uint32 lastFPS = lastUpdate;

        #ifdef DEBUG

        int fpsInterval = 1000;
        float fpsMultiplier = 1000.0 / fpsInterval;
        int frames = 0;

        #endif

        while (running) {
            Uint32 now = SDL_GetTicks();
            float delta = (now - lastUpdate) / 1000.0;
            lastUpdate = now;

            PollEvents();
            Update(delta);
            Render();

            Uint32 newNow = SDL_GetTicks();

            #ifdef DEBUG

            frames++;

            if (newNow - lastFPS > fpsInterval) {
                std::cout << "FPS: " << (int)(frames * fpsMultiplier) << std::endl;
                frames = 0;
                lastFPS += fpsInterval;
            }

            #endif

            int frameTime = newNow - now;

            if (frameTime < delay) {
                SDL_Delay(delay - frameTime);
            }
        }

        Clean();
    }

    void Start(const char* title, int width, int height, bool fullscreen) {
        renderer = nullptr;

        if (SDL_Init(SDL_INIT_VIDEO) > 0) {
            std::cout << "SDL_Init failed, error: " << SDL_GetError() << std::endl;
            return;
        }

        if (!IMG_Init(IMG_INIT_PNG)) {
            std::cout << "IMG_Init failed, error: " << SDL_GetError() << std::endl;
            return;
        }

        int windowFlags = 0;
        if (fullscreen) windowFlags |= SDL_WINDOW_FULLSCREEN;

        Settings::WindowWidth = width;
        Settings::WindowHeight = height;

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)width, (int)height, windowFlags);

        if (window == nullptr) {
            std::cout << "SDL_CreateWindow failed, error: " << SDL_GetError() << std::endl;
            return;
        }

        int rendererFlags = 0;//SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

        renderer = SDL_CreateRenderer(window, -1, rendererFlags);

        if (renderer == nullptr) {
            std::cout << "SDL_CreateRenderer failed, error: " << SDL_GetError() << std::endl;
            return;
        }

        Input::Init();

        setup = true;

        Run();
    }
}