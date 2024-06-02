#include "editor_window_controller.h"

Editor_Window_Controller::Editor_Window_Controller(Editor_Window_Renderer& renderer) : renderer(renderer) {}

void Editor_Window_Controller::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);

        switch (event.type) {
        case SDL_QUIT:
            handleQuitEvent();
            break;
        case SDL_WINDOWEVENT:
            handleWindowEvent(event);
            break;
        case SDL_MOUSEMOTION:
            handleMouseMotionEvent(event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            handleMouseButtonDownEvent(event);
            break;
        case SDL_MOUSEBUTTONUP:
            handleMouseButtonUpEvent(event);
            break;
        }
    }
}

void Editor_Window_Controller::handleQuitEvent() {
    exit(0);
}

void Editor_Window_Controller::handleWindowEvent(const SDL_Event& event) {
    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
        EditorWindow& window = EditorWindow::getInstance();
        window.resize(event.window.data1, event.window.data2);
    }
}

void Editor_Window_Controller::handleMouseMotionEvent(const SDL_Event& event) {
    // Get the window size
    int width = 0, height = 0;
    SDL_GetWindowSize(renderer.getWindow(), &width, &height);

    // Check if the mouse is near the window's edge
    const int edge_dist = 10; // Distance from edge to change cursor
    if (event.motion.x >= width - edge_dist || event.motion.y >= height - edge_dist) {
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE));
        if (isResizing) {
            resizeWindow(event);
        }
    }
    else {
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    }

}

void Editor_Window_Controller::handleMouseButtonDownEvent(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        // Start resizing when the mouse button is pressed down
        int width = 0, height = 0;
        SDL_GetWindowSize(renderer.getWindow(), &width, &height);
        if (event.button.x >= width - 10 || event.button.y >= height - 10) {
            startResizing(event);
        }

    }
}

void Editor_Window_Controller::handleMouseButtonUpEvent(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        // Stop resizing when the mouse button is released
        stopResizing();
    }
}

void Editor_Window_Controller::resizeWindow(const SDL_Event& event) {
    EditorWindow& window = EditorWindow::getInstance();
    int width = 0, height = 0;
    SDL_GetWindowSize(renderer.getWindow(), &width, &height);
    int newWidth = width + (event.motion.x - resizeStartPos.x);
    int newHeight = height + (event.motion.y - resizeStartPos.y);
    window.resize(newWidth, newHeight);
    resizeStartPos = { event.motion.x, event.motion.y };
}

void Editor_Window_Controller::startResizing(const SDL_Event& event) {
    isResizing = true;
    resizeStartPos = { event.button.x, event.button.y };
}

void Editor_Window_Controller::stopResizing() {
    isResizing = false;
}

