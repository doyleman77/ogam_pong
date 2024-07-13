#pragma once

#include "entity.hpp"

class Paddle : public Entity
{
public:
	Paddle();
	~Paddle() override;
	void set_color(SDL_Color& c);
	void draw(SDL_Renderer* r);
private:
	SDL_Color color;
	float speed;
};
