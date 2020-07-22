#include "../headers/graphics.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->window, &this->renderer);
    SDL_SetWindowTitle(this->window,"Simpsons Travel");

}
Graphics::~Graphics()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}
SDL_Surface* Graphics::load_image(const std::string &filepath)
{
    if(this->spriteSheet.count(filepath)==0)
    {
        this->spriteSheet[filepath] = IMG_Load(filepath.c_str());
    }
    return this->spriteSheet[filepath];
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceR, SDL_Rect *destR)
{
    SDL_RenderCopy(this->renderer, texture, sourceR, destR);
}
void Graphics::flip()
{
    SDL_RenderPresent(this->renderer);
}
void Graphics::clear()
{
    SDL_RenderClear(this->renderer);
}
SDL_Renderer* Graphics::getRenderer() const
{
    return this->renderer;
}