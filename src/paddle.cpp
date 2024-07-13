#include "paddle.hpp"

Paddle::Paddle()
{
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
}

Paddle::~Paddle()
{

}

void Paddle::set_color(SDL_Color& c)
{
	color = c;
}

void Paddle::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &collision_box);
}