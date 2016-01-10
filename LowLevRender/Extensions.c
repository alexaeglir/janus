/**
 * @file Extensions.h
 * @brief initializes extensions to opengl under windows
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 01/01/16
 */

#include "Extensions.h"
#include <windows.h>
PFNGLCREATESHADERPROC glCreateShader;
PFNGLSHADERSOURCEPROC glShaderSource;
PFNGLCOMPILESHADERPROC glCompileShader;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
PFNGLGETSHADERIVPROC glGetShaderiv;
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLGETPROGRAMIVPROC glGetProgramiv;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
PFNGLATTACHSHADERPROC glAttachShader;

PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLUSEPROGRAMPROC glUseProgram;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;

PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
PFNGLBINDBUFFERBASEPROC glBindBufferBase;

void initExtensions(void)
{
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)wglGetProcAddress("glGetUniformBlockIndex");
	if(!glGetUniformBlockIndex)
		return;
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)wglGetProcAddress("glGetActiveUniformBlockiv");
	if(!glGetActiveUniformBlockiv)
		return;
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)wglGetProcAddress("glGetUniformIndices");
	if(!glGetUniformIndices)
		return;
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)wglGetProcAddress("glGetActiveUniformsiv");
	if(!glGetActiveUniformsiv)
		return;
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)wglGetProcAddress("glBindBufferBase");
	if(!glBindBufferBase)
		return;

	glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	if(!glCreateShader)
		return;
	glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	if(!glShaderSource)
		return;
	glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	if(!glCompileShader)
		return;
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	if(!glGetShaderInfoLog)
		return;
	glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	if(!glGetShaderiv)
		return;
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	if(!glCreateProgram)
		return;
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	if(!glGetProgramiv)
		return;
	glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	if(!glLinkProgram)
		return;
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
	if(!glGetProgramInfoLog)
			return;
	glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	if(!glAttachShader)
		return;


	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
	if(!glAttachShader)
		return;
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
	if(!glAttachShader)
		return;
	glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	if(!glAttachShader)
		return;
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	if(!glAttachShader)
		return;

	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	if(!glAttachShader)
		return;

	glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	if(!glAttachShader)
		return;

	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
	if(!glAttachShader)
		return;

	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
	if(!glAttachShader)
		return;



	return ;

}

