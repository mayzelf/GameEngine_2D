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
    bool isResizing;
    SDL_Point resizeStartPos;


    void handleQuitEvent();
    void handleWindowEvent(const SDL_Event& event);
    void handleMouseMotionEvent(const SDL_Event& event);
    void handleMouseButtonDownEvent(const SDL_Event& event);
    void handleMouseButtonUpEvent(const SDL_Event& event);
    void resizeWindow(const SDL_Event& event);
    void startResizing(const SDL_Event& event);
    void stopResizing();
};

#endif
