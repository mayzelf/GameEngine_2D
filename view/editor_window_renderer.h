#ifndef EDITOR_WINDOW_RENDERER_H
#define EDITOR_WINDOW_RENDERER_H

#include <GL/glew.h>
#include <SDL.h>
#include "SDL_opengl.h"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_opengl3.h>
#include "../model/editor_window.h"
#include "../utils.h"
#include "../resource.h"
#include "sdl_render_handler.h"


class Editor_Window_Renderer
{

    EditorWindow& editorWindow;
public:
    Editor_Window_Renderer(EditorWindow& window, HINSTANCE hInstance);
	~Editor_Window_Renderer();

    void init();
    void present();
    void shutdown();


    //Components
	void drawTitleBar();

private:
    Sdl_Render_Handler* sdl_render_handler;
    HINSTANCE hInstance;
};

#endif


