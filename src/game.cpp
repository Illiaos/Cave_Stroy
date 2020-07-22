#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/game.h"
#include "../headers/graphics.h"
#include "../headers/input.h"

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}
Game::~Game()
{

}
void Game::gameLoop()
{
    Graphics graphics;
    Input input;
    SDL_Event event;

    this->_player = Sprite(graphics, "assets/sprites/MyChar.png", 0, 0, 16, 16, 100, 100);

    while (true)
    {
        input.beginNewFrame();
        if(SDL_PollEvent(&event))
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.repeat == 0)
                {
                    input.keyDownEvent(event);
                }

            }
            else if(event.type == SDL_KEYUP)
            {
                input.keyUpEvent(event);
            }
            else if(event.type == SDL_QUIT)
            {
                return;
            }
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
        {
            return;
        }
        this->draw(&graphics);
    }
    
}
void Game::draw(Graphics *graphics)
{
    graphics->clear();
    this->_player.draw(*graphics, 100, 100);

    graphics->flip();
}