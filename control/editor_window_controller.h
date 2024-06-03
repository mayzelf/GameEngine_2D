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
    Sdl_Render_Handler* sdl_render_handler_;


    static void handle_quit_event();
    static void handle_window_event(const SDL_Event& event);
    void handle_mouse_motion_event(const SDL_Event& event);
    void handle_mouse_button_down_event(const SDL_Event& event);
    void handle_mouse_button_up_event(const SDL_Event& event);
    void resize_window(const SDL_Event& event);
};

#endif
