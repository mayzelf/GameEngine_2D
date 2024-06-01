#ifndef UTILS_H
#define UTILS_H
#include "SDL_opengl.h"
#define STB_IMAGE_IMPLEMENTATION
#include "externals/stb_image.h"

namespace utils
{
	namespace resources
	{
		GLuint loadTexture(const char* path);
	}
};

#endif // UTILS_H