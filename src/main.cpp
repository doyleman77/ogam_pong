#include <iostream>

#ifndef _WIN32
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <string>
#include "game.hpp"

using namespace std;

int main(int argc, char* args[])
{
    Game game("Pong", 640, 480);
    game.run(60);
    return 0;
}