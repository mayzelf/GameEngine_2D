#include "sdl_render_handler.h"


Sdl_Render_Handler& Sdl_Render_Handler::getInstance()
{
    static Sdl_Render_Handler instance;
    return instance;
}

Sdl_Render_Handler::~Sdl_Render_Handler()
{
	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Sdl_Render_Handler::init(EditorWindow& editorWindow)
{
    SDL_Init(SDL_INIT_VIDEO);

    // Use OpenGL 3.3 core profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Create an SDL window without a title bar
    this->window = SDL_CreateWindow(editorWindow.getTitle().c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, editorWindow.getSize().y, editorWindow.getSize().x, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
    gl_context = SDL_GL_CreateContext(this->window);

    
}

void Sdl_Render_Handler::setWindowSize(int width, int height)
{
	SDL_SetWindowSize(window, width, height);
}

void Sdl_Render_Handler::setWindowPosition(int x, int y)
{
	SDL_SetWindowPosition(window, x, y);
}

glm::vec<2, int> Sdl_Render_Handler::getWindowSize() const
{
	int width, height;
	SDL_GetWindowSize(window, &width, &height);
	return glm::vec<2, int>(width, height);
}

glm::vec<2, int> Sdl_Render_Handler::getWindowPosition() const
{
	int x, y;
	SDL_GetWindowPosition(window, &x, &y);
	return glm::vec<2, int>(x, y);
}
