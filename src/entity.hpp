#ifndef ENTITY_HPP
#define ENTITY_HPP

#ifndef _WIN32
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif

class Entity
{
public:

private:
    SDL_Texture* texture;
    int x_pos, y_pos;
    float x_accel, y_accel;
};

#endif