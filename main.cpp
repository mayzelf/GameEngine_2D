#include "model/editor_window.h"
#include "view/editor_window_renderer.h"
#include "control/editor_window_controller.h"
#include <windows.h>
#include <SDL2/include/SDL.h>


int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    EditorWindow& window = EditorWindow::getInstance();
    window.setTitle("Game");
    window.setSize(800, 600);

    Editor_Window_Renderer renderer;
    renderer.init(window);

    Editor_Window_Controller controller(renderer);

    while (true)
    {
        controller.handleEvents();

        renderer.clear();
        // Draw stuff
        renderer.present();
    }
    return 0;
}
