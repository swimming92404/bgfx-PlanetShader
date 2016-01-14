#ifndef __BASEAPPLICATION_H__
#define __BASEAPPLICATION_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <bgfx/bgfxplatform.h>
#include <bgfx/bgfxdefines.h>

#include <stdio.h>
#include <bx/handlealloc.h>
#include <bx/fpumath.h>
#include <bx/readerwriter.h>
#include <bx/string.h>

#include <GL/gl.h>

#include <bgfx/bgfx.h>
#include <bx/uint32_t.h>

#include "engine/mesh.h"
#include "engine/texture.h"
#include "programloader.h"

class BaseApplication
{
public:
	bgfx::ProgramHandle loadProgram(const char* _vsName, const char* _fsName);
	BaseApplication();
	~BaseApplication();

	void run();

protected:
	SDL_Window *m_mainWindow;
	int m_width;
	int m_height;

	ProgramLoader m_programloader;
};


#endif
