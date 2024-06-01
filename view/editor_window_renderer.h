#ifndef EDITOR_WINDOW_RENDERER_H
#define EDITOR_WINDOW_RENDERER_H

#include <SDL2/include/SDL.h>
#include "../model/editor_window.h"

class Editor_Window_Renderer
{
public:
	Editor_Window_Renderer();
	~Editor_Window_Renderer();

    void init(const EditorWindow& window);
    void clear();
    void present();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif


