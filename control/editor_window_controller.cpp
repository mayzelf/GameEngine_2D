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
    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
        EditorWindow& window = EditorWindow::getInstance();
        window.resize(event.window.data1, event.window.data2);
    }
}

void Editor_Window_Controller::handle_mouse_motion_event(const SDL_Event& event) {
    // Get the window size
    const glm::vec<2, int> window_size = sdl_render_handler_->getWindowSize();

    // Check if the mouse is near the window's edge
    if (constexpr int edge_dist = 10; event.motion.x >= window_size.x - edge_dist || event.motion.y >= window_size.y -
	    edge_dist)
    {
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE));
        if (isResizing) {
            resize_window(event);
        }
    }
    else {
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    }

}

void Editor_Window_Controller::handle_mouse_button_down_event(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        // Start resizing when the mouse button is pressed down
        if (const glm::vec<2, int> window_size = sdl_render_handler_->getWindowSize(); event.button.x >= window_size.x -
	        10 || event.button.y >= window_size.y - 10)
        {
            start_resizing(event);
        }

    }
}

void Editor_Window_Controller::handle_mouse_button_up_event(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        // Stop resizing when the mouse button is released
        stop_resizing();
    }
}

void Editor_Window_Controller::resize_window(const SDL_Event& event) {
    EditorWindow& window = EditorWindow::getInstance();
    const glm::vec<2, int> window_size = sdl_render_handler_->getWindowSize();
    const int new_width = window_size.x + (event.motion.x - resizeStartPos.x);
    const int new_height = window_size.y + (event.motion.y - resizeStartPos.y);
    window.resize(new_width, new_height);
    resizeStartPos = { event.motion.x, event.motion.y };
}

void Editor_Window_Controller::start_resizing(const SDL_Event& event) {
    isResizing = true;
    resizeStartPos = { event.button.x, event.button.y };
}

void Editor_Window_Controller::stop_resizing() {
    isResizing = false;
}

