/**
 * @file Extensions.h
 * @brief initializes extensions to opengl under windows
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 01/01/16
 */

#ifndef _EXTENSIONS_H_
#define _EXTENSIONS_H_
#include <Gl/gl.h>
#include <Gl/glext.h>
#ifdef __cplusplus
extern "C"{
#endif
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
extern PFNGLGETSHADERIVPROC glGetShaderiv;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLUSEPROGRAMPROC glUseProgram;
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
extern PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
extern PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
extern PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
extern PFNGLBINDBUFFERBASEPROC glBindBufferBase;
void initExtensions(void);
#ifdef __cplusplus
}
#endif
#endif

