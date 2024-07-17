#include "game.hpp"
#include <string>

Game::Game(std::string title, int width, int height)
{
    fps = 0;
    running = false;
    up_key = down_key = space_key = false;

    // TODO: check for failing to init SDL and IMG
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    IMG_Init(IMG_INIT_PNG);

    // TODO:check for failing to create window and renderer
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

    //texture_manager.load_texture("paddle", renderer);
    texture_manager.load_texture("ball", renderer);

    player.set_size(8, 64);
    SDL_Color c = SDL_Color{ 255, 0, 0, 255 };
    player.set_color(c);
    player.set_position(width - player.get_width() - 10, (height / 2) - (player.get_height() / 2));
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

        else if (ev.type == SDL_KEYDOWN)
        {
            switch (ev.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                running = false;
                continue;
            case SDLK_UP:
                up_key = true;
                continue;
            case SDLK_DOWN:
                down_key = true;
                continue;
            }
        }
        else if (ev.type == SDL_KEYUP)
        {
            switch (ev.key.keysym.sym)
            {
            case SDLK_UP:
                up_key = false;
                continue;
            case SDLK_DOWN:
                down_key = false;
                continue;
            }
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
    player.draw(renderer);
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
    if (up_key) player.move(0, -1);
    else if (down_key) player.move(0, 1);
    for (auto i : entities)
    {
        i->update(dt);
    }

    //paddle locking
    int window_height, window_width;
    SDL_GetWindowSize(window, &window_width, &window_height);
    if (player.get_height() + player.get_ypos() > window_height)
        player.set_position(player.get_xpos(), window_height - player.get_height());
    else if (player.get_ypos() < 0)
        player.set_position(player.get_xpos(), 0);
}

void Game::run(int fps)
{
    // TODO: clamp FPS probably within a range?
    running = true;
    float delay_milliseconds = 1000/fps;
    
    while (running)
    {
        int last_time = SDL_GetTicks();
        input();
        draw();
        update(0); //TODO: calculate frametime and pass difference into update
        SDL_Delay(delay_milliseconds);
        int frame_time = SDL_GetTicks() - last_time;
    }
}