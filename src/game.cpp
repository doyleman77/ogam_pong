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

    texture_manager.get_texture("paddle", renderer);
    texture_manager.get_texture("ball", renderer);

    Entity* paddle_one = new Entity(); // needs to be a Paddle()
    paddle_one->register_texture(texture_manager.get_texture("paddle", renderer));
    entities.push_back(paddle_one);
    Entity* paddle_two = new Entity(); // needs to be a Paddle()
    paddle_two->register_texture(texture_manager.get_texture("paddle", renderer));
    entities.push_back(paddle_two);
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Game::input()
{
    while (SDL_PollEvent(&ev))
    {
        if (ev.type == SDL_QUIT) running = false;
        switch (ev.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            running = false;
            continue;
        }
    }
}

void Game::draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (auto i : entities)
    {
        i->draw(renderer);
    }
    draw_net();
    SDL_RenderPresent(renderer);
}

void Game::draw_net()
{
    int x_pos = 0;
    int y_pos = 0;
    int win_height = 0;
    SDL_GetWindowSize(window, &x_pos, &win_height);
    x_pos /= 2;
    while (y_pos < win_height)
    {
        SDL_Rect net_rect;
        net_rect.w = 2;
        net_rect.h = 12;
        net_rect.x = x_pos - (net_rect.w / 2);
        net_rect.y = y_pos;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // white
        SDL_RenderFillRect(renderer, &net_rect);
        y_pos += 20; // temporary value
    }

}

void Game::update(int dt)
{
    for (auto i : entities)
    {
        i->update(dt);
    }
}

void Game::run(int fps)
{
    // TODO: clamp FPS probably within a range?
    running = true;
    int delay_milliseconds = 1000/fps;
    int last_time = SDL_GetTicks();
    while (running)
    {
        int current_time = last_time;
        input();
        draw();
        //update(); TODO: calculate frametime and pass difference into update
        SDL_Delay(delay_milliseconds);
    }
}