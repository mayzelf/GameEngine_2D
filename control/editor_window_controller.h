#ifndef EDITOR_WINDOW_CONTROLLER_H
#define EDITOR_WINDOW_CONTROLLER_H
#include "../view/editor_window_renderer.h"
#include <SDL.h>

class Editor_Window_Controller {
public:
    Editor_Window_Controller(Editor_Window_Renderer& renderer);
    void handleEvents();

private:
    Editor_Window_Renderer& renderer;
};

#endif

