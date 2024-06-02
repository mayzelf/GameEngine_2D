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


class Editor_Window_Renderer
{

    EditorWindow& editorWindow;
public:
    Editor_Window_Renderer(EditorWindow& window, HINSTANCE hInstance);
	~Editor_Window_Renderer();

    void init();
    void present();
    void shutdown();

    SDL_Window* getWindow() { return window; }

    //Components
	void drawTitleBar();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_GLContext gl_context;
    HINSTANCE hInstance;
};

#endif


