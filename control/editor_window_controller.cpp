#include "editor_window_controller.h"

Editor_Window_Controller::Editor_Window_Controller(Editor_Window_Renderer& renderer) : renderer(renderer) {}

void Editor_Window_Controller::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);

        if (event.type == SDL_QUIT) {
            exit(0);
        }
        else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
            EditorWindow& window = EditorWindow::getInstance();
            window.resize(event.window.data1, event.window.data2);
        }
    }
}
