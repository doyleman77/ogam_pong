#include "texture_manager.hpp"

SDL_Texture* Texture_Manager::get_texture(std::string filename, SDL_Renderer* renderer)
{
    const std::string image_path = "./assets/art/";
    const std::string image_extension = ".png";
    const std::string filepath = image_path + filename + image_extension;
    auto iter = textures.find(filename);
    // no such file exists. create it.
    if (iter == textures.end())
    {
        std::string filepath = image_path + filename + image_extension;
        SDL_Surface* loaded_surface =IMG_Load(filepath.c_str());
        if (loaded_surface == NULL)
        {
            std::cout << "Couldn't load image " << filename << " with SDL error " << SDL_Error;
            SDL_FreeSurface(loaded_surface);
            return nullptr;
        }
        SDL_Texture* temp_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
        if (temp_texture == NULL)
        {
            std::cout << "Couldn't convert surface into texture with SDL Error " << SDL_Error;
            SDL_FreeSurface(loaded_surface);
            SDL_DestroyTexture(temp_texture);
            return nullptr;
        }
        textures.insert({ filename, temp_texture });
        
        SDL_FreeSurface(loaded_surface);
        //SDL_DestroyTexture(temp_texture);
    }
    return textures.at(filename);
}