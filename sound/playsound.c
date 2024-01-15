#include <SDL2/SDL.h>

int playsound()
{
    playSound("sounds/door1.wav", SDL_MIX_MAXVOLUME / 2);
}
