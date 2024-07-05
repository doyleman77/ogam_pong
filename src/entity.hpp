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

#include <string>

class Entity
{
public:
    Entity();
    virtual ~Entity();
    void update(float dt);
    void draw(SDL_Renderer* renderer);
    bool register_texture(SDL_Texture* tex);
    void register_rect(SDL_Rect& rect);
    void move(int x, int y);

private:
    SDL_Texture* texture;
    SDL_Rect collision_box;

    int x_pos, y_pos;
    float x_accel, y_accel;
    bool alive;
};

#endif