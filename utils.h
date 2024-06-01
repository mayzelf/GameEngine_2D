#ifndef UTILS_H
#define UTILS_H
#include <GL/glew.h>
#include "SDL_opengl.h"
#include "externals/stb_image.h"

#include "SDL_egl.h"
#include "SDL_log.h"

namespace utils
{
	namespace resources
	{
		GLuint loadTexture(const char* path);
		GLuint loadTextureFromResource(HINSTANCE hInstance, int resourceId);
	}
};

#endif // UTILS_H