#pragma once

#include "entity.hpp"

class Paddle : public Entity
{
public:
	Paddle();
	~Paddle() override;
private:
	SDL_Color color;
};
