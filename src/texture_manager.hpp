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
#include <unordered_map>
#include <iostream>

class Texture_Manager
{
    public:
    //Texture_Manager();
    //~Texture_Manager();
    SDL_Texture* get_texture(std::string filename, SDL_Renderer* renderer);
    private:
        std::unordered_map<std::string, SDL_Texture*> textures;
};