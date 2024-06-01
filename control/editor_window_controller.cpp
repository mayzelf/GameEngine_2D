#include "editor_window_controller.h"

Editor_Window_Controller::Editor_Window_Controller(Editor_Window_Renderer& renderer) : renderer(renderer) {}

void Editor_Window_Controller::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        }
        // Handle other events...
    }
}
