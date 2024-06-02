#ifndef SDL_RENDER_HANDLER_H
#define SDL_RENDER_HANDLER_H
#include <SDL.h>

#include "../model/editor_window.h"

class Sdl_Render_Handler
{
public:
	static Sdl_Render_Handler& getInstance();
	~Sdl_Render_Handler();

	void init(EditorWindow& editorWindow);

	void setWindowSize(int width, int height);
	void setWindowPosition(int x, int y);
	void swapWindowBuffer() { SDL_GL_SwapWindow(window); }
	void minimizeWindow() { SDL_MinimizeWindow(window); }

	SDL_Window* getWindow() { return window; }
	SDL_GLContext getGLContext() { return gl_context; }
	glm::vec<2, int> getWindowSize() const;
	glm::vec<2, int> getWindowPosition() const;

private:
	Sdl_Render_Handler() = default; // Private constructor
	Sdl_Render_Handler(const Sdl_Render_Handler&) = delete; // Prevent copy
	Sdl_Render_Handler& operator=(const Sdl_Render_Handler&) = delete; // Prevent assignment

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_GLContext gl_context;
};

#endif