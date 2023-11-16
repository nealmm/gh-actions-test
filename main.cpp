#include <SDL.h>
#include <emscripten/html5.h>

int width, height;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;

void frame() {
    if (SDL_MUSTLOCK(surface)) SDL_LockSurface(surface);

    uint32_t* pixels = (uint32_t*)surface->pixels;

    for (int i = 0; i < width * height; i++) {
        pixels[i] = rand();
    }

    if (SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}

int main() {
    emscripten_get_canvas_element_size("canvas", &width, &height);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

    emscripten_set_main_loop(frame, 0, 1);
}
