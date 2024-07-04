#include "game.hpp"
#include <string>

Game::Game(std::string title, int width, int height) :
fps(0), running(false)
{
    // TODO: check for failing to init SDL and IMG
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    IMG_Init(IMG_INIT_PNG);

    // TODO:check for failing to create window and renderer
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Game::run(int fps)
{
    // TODO: clamp FPS probably within a range?
    running = true;
    int delay_milliseconds = 1000/fps;
    while (running)
    {
        while(SDL_PollEvent(&ev))
        {
            if(ev.type == SDL_QUIT) running = false;
            switch(ev.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                running = false;
                continue;
            }
        }
        SDL_Delay(delay_milliseconds);
    }
}