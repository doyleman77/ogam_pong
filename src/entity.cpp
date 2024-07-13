#include "entity.hpp"

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
	if (not alive) return;

}

void Entity::move(float x, float y)
{
	if (not alive) return;

	x_pos += x;
	y_pos += y;

	collision_box.x = static_cast<int>(x_pos);
	collision_box.y = static_cast<int>(y_pos);
}

void Entity::set_position(int x, int y)
{
	collision_box.x = x;
	collision_box.y = y;
	x_pos = collision_box.x;
	y_pos = collision_box.y;
}

void Entity::draw(SDL_Renderer* renderer)
{
	if (not alive) return;

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
	if (this->texture != NULL)
	{
		SDL_QueryTexture(tex, NULL, NULL, &collision_box.w, &collision_box.h);
		return true;
	}
	else
	{
		return false;
	}
}

void Entity::register_rect(SDL_Rect& rect)
{
	collision_box = rect;
}

void Entity::set_size(int w, int h)
{
	collision_box.w = w;
	collision_box.h = h;
}

void Entity::stretch_width(float width)
{
	collision_box.w *= width;
}

void Entity::stretch_height(float height)
{
	collision_box.h *= height;
}

int Entity::get_height()
{
	return collision_box.h;
}

int Entity::get_width()
{
	return collision_box.w;
}

int Entity::get_xpos()
{
	return collision_box.x;
}

int Entity::get_ypos()
{
	return collision_box.y;
}