#include "model/editor_window.h"
#include "view/editor_window_renderer.h"
#include "control/editor_window_controller.h"
#include <windows.h>
#include <SDL.h>
#define STB_IMAGE_IMPLEMENTATION
#include "externals/stb_image.h"


int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    EditorWindow& window = EditorWindow::getInstance();
    window.setTitle("Maygine");
    window.setSize(800, 600);
    window.setMinimumSize(400, 300);
    TitleBar titleBar = TitleBarBuilder()
        .setIconPath(IDB_PNG1)
        .setFlags(SHOW_MINIMIZE_BUTTON | SHOW_CLOSE_BUTTON)
        .setTitle("Maygine")
        .build();
    window.setTitleBar(titleBar);

    Editor_Window_Renderer editor_window_renderer(EditorWindow::getInstance(), hInstance);
    editor_window_renderer.init();

    Editor_Window_Controller editor_window_controller(editor_window_renderer);

    while (true)
    {
        editor_window_controller.handleEvents();

        // Draw stuff
        editor_window_renderer.present();
    }
    editor_window_renderer.shutdown();

    return 0;
}
