#pragma once

#ifndef _WIN32
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <string>
#include "texture_manager.hpp"
#include "entity.hpp"
#include "paddle.hpp"

class Game
{
    public:
        Game(std::string title, int width, int height);
        ~Game();
        void run(int fps);
        
    private:
        void update(int dt);
        void draw();
        void input();
        void draw_net();

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event ev;

        Texture_Manager texture_manager;

        std::vector<Entity*> entities;

        Paddle player;
        Paddle bot;
        bool down_key, up_key, space_key;
        bool running;
        int fps;
};