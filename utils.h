#ifndef UTILS_H
#define UTILS_H
#include <GL/glew.h>
#include "SDL_opengl.h"
#include "externals/stb_image.h"

#include "SDL_egl.h"
#include "SDL_log.h"

#include <Windows.h>
#include <shellapi.h>


namespace utils
{
	namespace resources
	{
		GLuint loadTexture(const char* path);
		GLuint loadTextureFromResource(HINSTANCE hInstance, int resourceId);
	}

	namespace windows
	{
		RECT GetMonitorSizeMinusTaskbar();
	}
};

#endif // UTILS_H