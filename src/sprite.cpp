#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include "../headers/sprite.h"
#include "../headers/graphics.h"
Sprite::Sprite()
{

}
Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY)
{
    this->_x = posX;
    this->_y = posY;
    this->sourceREct.x = sourceX;
    this->sourceREct.y = sourceY;
    this->sourceREct.w = width;
    this->sourceREct.h = height;

    this->spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.load_image(filePath));
    if(this->spriteSheet == NULL)
    {
        printf("Error\n");
    }
}

Sprite::~Sprite()
{

}
void Sprite::draw(Graphics &graphics, int x, int y)
{
    SDL_Rect destR = {x, y, this->sourceREct.w, this->sourceREct.h};
    graphics.blitSurface(this->spriteSheet, &this->sourceREct, &destR);
}
void Sprite::update()
{

}