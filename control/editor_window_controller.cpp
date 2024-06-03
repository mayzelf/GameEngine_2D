#include "editor_window_controller.h"

Editor_Window_Controller::Editor_Window_Controller(Editor_Window_Renderer& renderer) : renderer(renderer) {}

void Editor_Window_Controller::handleEvents() {
    if(!sdl_render_handler_)
    {
    	sdl_render_handler_ = &Sdl_Render_Handler::getInstance();
    }

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);

        switch (event.type) {
        case SDL_QUIT:
            handle_quit_event();
            break;
        case SDL_WINDOWEVENT:
            handle_window_event(event);
            break;
        case SDL_MOUSEMOTION:
            handle_mouse_motion_event(event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            handle_mouse_button_down_event(event);
            break;
        case SDL_MOUSEBUTTONUP:
            handle_mouse_button_up_event(event);
            break;
		default: ;
        }
    }
}

void Editor_Window_Controller::handle_quit_event() {
    exit(0);
}

void Editor_Window_Controller::handle_window_event(const SDL_Event& event) {
    
}

void Editor_Window_Controller::handle_mouse_motion_event(const SDL_Event& event) {
    // Get the window size
    EditorWindow& window = EditorWindow::getInstance();
    int x, y;
    SDL_GetMouseState(&x, &y);
    // Check if the mouse is near the window's edge
    if (x >= window.getPosition().x + window.getSize().x - 5 && x <= window.getPosition().x + window.getSize().x + 5 &&
        y >= window.getPosition().y + window.getSize().y - 5 && y <= window.getPosition().y + window.getSize().y + 5)
    {
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE));
    }
    else {
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    }

    if (isResizing) {
        resize_window(event);
    }
    
}

void Editor_Window_Controller::handle_mouse_button_down_event(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        // Start resizing when the mouse button is pressed down
        EditorWindow& window = EditorWindow::getInstance();
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x >= window.getPosition().x + window.getSize().x - 5 && x <= window.getPosition().x + window.getSize().x + 5 &&
            y >= window.getPosition().y + window.getSize().y - 5 && y <= window.getPosition().y + window.getSize().y + 5)
        {
            isResizing = true;
        }

    }
    else if (event.button.button == SDL_BUTTON_RIGHT) {
        
    }


}

void Editor_Window_Controller::handle_mouse_button_up_event(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        // Stop resizing when the mouse button is released
        isResizing = false;
    }
}

void Editor_Window_Controller::resize_window(const SDL_Event& event) {
    EditorWindow& window = EditorWindow::getInstance();
    int x, y;
    SDL_GetMouseState(&x, &y);
    const int new_width = x - window.getPosition().x;
    const int new_height = y - window.getPosition().y;
    window.resize(new_width, new_height);
}

