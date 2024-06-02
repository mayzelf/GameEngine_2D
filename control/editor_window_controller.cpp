#include "editor_window_controller.h"

Editor_Window_Controller::Editor_Window_Controller(Editor_Window_Renderer& renderer) : renderer(renderer) {}

void Editor_Window_Controller::handleEvents() {
    SDL_Event event;
    EditorWindow& window = EditorWindow::getInstance();
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);

        if (event.type == SDL_QUIT) {
            exit(0);
        }
        else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
            window.resize(event.window.data1, event.window.data2);
        }
        else if (event.type == SDL_MOUSEMOTION) {
            // Get the window size
            int width = 0, height = 0;
            SDL_GetWindowSize(renderer.getWindow(), &width, &height);

            // Check if the mouse is near the window's edge
            const int edge_dist = 10; // Distance from edge to change cursor
            if (event.motion.x >= width - edge_dist || event.motion.y >= height - edge_dist) {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE));
                if (isResizing) {
                    int newWidth = width + (event.motion.x - resizeStartPos.x);
                    int newHeight = height + (event.motion.y - resizeStartPos.y);
                    window.resize(newWidth, newHeight);
                    resizeStartPos = { event.motion.x, event.motion.y };
                }
            }
            else {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
            }
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            // Start resizing when the mouse button is pressed down
            int width = 0, height = 0;
            SDL_GetWindowSize(renderer.getWindow(), &width, &height);
            if (event.button.x >= width - 10 || event.button.y >= height - 10) {
                isResizing = true;
                resizeStartPos = { event.button.x, event.button.y };
            }
        }
        else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            // Stop resizing when the mouse button is released
            isResizing = false;
        }
    }
}







