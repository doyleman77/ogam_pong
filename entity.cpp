#include "src\entity.hpp"

Entity::Entity()
{
	collision_box = SDL_Rect{ 0,0,0,0 };
	texture = NULL;
	x_accel = y_accel = 0.f;
	x_pos = y_pos = 0;
	alive = true;
}

Entity::~Entity()
{

}

void Entity::update(float dt)
{

}

void Entity::draw(SDL_Renderer* renderer)
{
	if (this->texture != NULL)
	{
		SDL_RenderCopy(renderer, texture, NULL, &collision_box); // TODO: 3RD PARAM -- CHANGE SOURCE RECT FOR SPRITEMAP PURPOSES
	}
	else
		return; // NO TEXTURE REGISTERED
}

bool Entity::register_texture(SDL_Texture* tex)
{
	this->texture = tex;
	if (this->texture != NULL) return true;
	else return false;
}

void Entity::register_rect(SDL_Rect& rect)
{
	collision_box = rect;
}