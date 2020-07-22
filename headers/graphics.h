#ifndef GRAPHICS_H
#define GRAPHICS_h
#include <map>
#include <string>
struct SDL_Window;
struct SDL_Renderer;
#include "SDL2/SDL.h"

class Graphics
{
    public:
        Graphics();
        ~Graphics();
        SDL_Surface *load_image(const std::string &filepath);
        void blitSurface(SDL_Texture *texture, SDL_Rect *sourceR, SDL_Rect *destR);
        void flip();
        void clear();
        SDL_Renderer *getRenderer() const;
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        std::map<std::string, SDL_Surface*> spriteSheet;
};
#endif