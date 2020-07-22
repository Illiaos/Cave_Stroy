#ifndef SPRITE_H
#define SPRITE_h
//#include "graphics.h"
#include <string>
#include "SDL2/SDL.h"
class Graphics;
class  Sprite
{
private:
    SDL_Rect sourceREct;
    SDL_Texture *spriteSheet;
    float _x; float _y;
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
    
   virtual ~ Sprite();
   virtual void update();
   void draw(Graphics &graphics, int x, int y);

};


#endif