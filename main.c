#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

void scc(int code)
{
    if (code < 0)
    {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
    }
}

void *scp(void *ptr)
{
    if (ptr == NULL)
    {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }

    return ptr;
}

int main(void)
{
    scc(SDL_Init(SDL_INIT_VIDEO));

    SDL_Window *window = SDL_CreateWindow(
        "Text Editor",
        0, 0, 800, 600, SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer =
        scp(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));

    bool quit = false;
    while (!quit)
    {
        SDL_Event event = {0};
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
            {
                quit = true;
            }
            break;
            }
        }

        scc(SDL_SetRenderDrawColor(renderer, 100, 0, 0, 0));
        scc(SDL_RenderClear(renderer));

        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

    return 0;
}