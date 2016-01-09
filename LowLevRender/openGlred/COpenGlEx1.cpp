/**
 * @file COpenGlEx1.cpp
 * @brief example 1 from opengl red book
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 01/09/2016
 */
#include "COpenGlEx1.hpp"
#include "Extensions.h"
#include <Gl/gl.h>
namespace Aeglir{
namespace LowLevRender{
#define BUFFER_OFFSET(offset) ((void*)(offset))
enum VAOIds {Triangles,NumVAOs};
enum BufferIds {ArrayBuffer,NumBuffers};
enum AttribIds {vPosition = 0};
static GLuint VAOs[NumVAOs];
static GLuint Buffers[NumBuffers];
const GLuint numVertices = 6;
	void COpenGlEx1::init(void)
	{
		glGenVertexArrays(NumVAOs,VAOs);
		glBindVertexArray(VAOs[Triangles]);
		GLfloat vertices[numVertices][2] = {{-0.90,-0.90},{0.85,-0.90},{-0.90,0.85},{0.90,-0.85},{0.90,0.90},{-0.85,0.90}};
		glGenBuffers(NumBuffers,Buffers);
		glBindBuffer(GL_ARRAY_BUFFER,Buffers[ArrayBuffer]);
		glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
		_shaderInfo.vShaderFile = "F:\\Documents and Settings\\Alex\\My Documents\\AndroidDev\\workspace\\JanusEngine\\LowLevRender\\triangles.vert";
		_shaderInfo.fShaderFile = "F:\\Documents and Settings\\Alex\\My Documents\\AndroidDev\\workspace\\JanusEngine\\LowLevRender\\triangles.frag";
		GLuint program =  _shaderInfo.LoadShader(_shaderInfo);
		glUseProgram(program);
		glVertexAttribPointer(vPosition,2,GL_FLOAT,GL_FALSE,0,BUFFER_OFFSET(0));
		glEnableVertexAttribArray(vPosition);
	}
	void COpenGlEx1::draw(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(VAOs[Triangles]);
		glDrawArrays(GL_TRIANGLES,0,numVertices);
		glFlush();
	}
}
}
