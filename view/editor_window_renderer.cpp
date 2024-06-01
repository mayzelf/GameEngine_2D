#include "editor_window_renderer.h"

Editor_Window_Renderer::Editor_Window_Renderer() : window(nullptr), renderer(nullptr)
{
}

Editor_Window_Renderer::~Editor_Window_Renderer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Editor_Window_Renderer::init(const EditorWindow& window)
{
    SDL_Init(SDL_INIT_VIDEO);
    this->window = SDL_CreateWindow(window.getTitle().c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window.getWidth(), window.getHeight(), SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

void Editor_Window_Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Editor_Window_Renderer::present()
{
    SDL_RenderPresent(renderer);
}