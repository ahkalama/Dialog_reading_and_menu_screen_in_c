#include <SDL2/SDL.h>

// calısıp calısmadıgı test edilmedi cunku fucking sdl2 yüklenmiyor 
int main()
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        printf("SDL başlatılamadı: %s\n", SDL_GetError());
        return 1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("Ses yüklenemedi: %s\n", Mix_GetError());
        return 1;
    }

    Mix_Music *muzik = Mix_LoadMUS("sesdosyasi.mp3");
    if (!muzik)
    {
        printf("Ses dosyası yüklenemedi: %s\n", Mix_GetError());
        return 1;
    }

    Mix_PlayMusic(muzik, -1);

    printf("Ses dosyasını çalmak için herhangi bir tuşa basınız...\n");
    getchar();

    Mix_FreeMusic(muzik);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
