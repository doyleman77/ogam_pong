#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "src/entity.hpp"

class Paddle : public Entity
{
public:
	Paddle();
	~Paddle() override;
private:
	SDL_Color color;
};
#endif