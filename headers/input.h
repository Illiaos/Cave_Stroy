#ifndef INPUT_H
#define INPUT_H
#include <SDL2/SDL.h>
#include <map>

class Input
{
public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event &event);
    void keyDownEvent(const SDL_Event &event);
    
    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyRealeased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
private:
    std::map<SDL_Scancode, bool> heldKey;
    std::map<SDL_Scancode, bool> pressedKey;
    std::map<SDL_Scancode, bool> releasedKey;
};
#endif
