/**
 * @file COpenGlEx2.cpp
 * @brief code for chapter 2
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 01/10/2016
 */
#include "Extensions.h"
#include <Gl/gl.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "COpenGlEx2.hpp"
using namespace std;
namespace Aeglir{
namespace LowLevRender{
#define BUFFER_OFFSET(offset) ((void*)(offset))
	enum VAOIds {Triangles,NumVAOs};
	enum BufferIds {ArrayBuffer,NumBuffers};
	enum AttribIds {vPosition = 0};
	static GLuint VAOs[NumVAOs];
	static GLuint Buffers[NumBuffers];
	const GLuint numVertices = 6;
	static size_t TypeSize(GLenum Type)
	{
		size_t size;
#define CASE(Enum, Count, Type) case Enum: size = sizeof(Type)*Count; break
		switch(Type){
			CASE(GL_FLOAT,				1,GLfloat);
			CASE(GL_FLOAT_VEC2,			2,GLfloat);
			CASE(GL_FLOAT_VEC3,			3,GLfloat);
			CASE(GL_FLOAT_VEC4,			4,GLfloat);
			CASE(GL_INT,				1,GLint);
			CASE(GL_INT_VEC2,			2,GLint);
			CASE(GL_INT_VEC3,			3,GLint);
			CASE(GL_INT_VEC4,			4,GLint);
			CASE(GL_UNSIGNED_INT,		1,GLuint);
			CASE(GL_UNSIGNED_INT_VEC2,	2,GLuint);
			CASE(GL_UNSIGNED_INT_VEC3,	3,GLuint);
			CASE(GL_UNSIGNED_INT_VEC4,	4,GLuint);
			CASE(GL_BOOL,				1,GLboolean);
			CASE(GL_BOOL_VEC2,			2,GLboolean);
			CASE(GL_BOOL_VEC3,			3,GLboolean);
			CASE(GL_BOOL_VEC4,			4,GLboolean);
			CASE(GL_FLOAT_MAT2,4,GLfloat);
			CASE(GL_FLOAT_MAT2x3,6,GLfloat);
			CASE(GL_FLOAT_MAT2x4,8,GLfloat);
			CASE(GL_FLOAT_MAT3,9,GLfloat);
			CASE(GL_FLOAT_MAT3x2,6,GLfloat);
			CASE(GL_FLOAT_MAT3x4,12,GLfloat);
			CASE(GL_FLOAT_MAT4,16,GLfloat);
			CASE(GL_FLOAT_MAT4x2,8,GLfloat);
			CASE(GL_FLOAT_MAT4x3,12,GLfloat);
#undef CASE
		default:
			cerr << "Unknown type" << Type;
			break;
		}
		return size;
	}
	void COpenGlEx2::init(void)
	{
		GLuint program;
		glClearColor(1,0,0,1);
		GLint numExt;
		glGetIntegerv(GL_NUM_EXTENSIONS,&numExt);

		printf("%s\n",glGetString(GL_EXTENSIONS));

		_shaderInfo.vShaderFile ="F:\\Documents and Settings\\Alex\\My Documents\\AndroidDev\\workspace\\JanusEngine\\LowLevRender\\shaders\\chap2.vert";
		_shaderInfo.fShaderFile ="F:\\Documents and Settings\\Alex\\My Documents\\AndroidDev\\workspace\\JanusEngine\\LowLevRender\\shaders\\chap2.frag";
		program = _shaderInfo.LoadShader();
		glUseProgram(program);
		//get the index of the uniform buffer in the shader and init an object
		GLuint ubo;
		GLuint uboIndex;
		GLint uboSize;
		GLvoid *buffer;//buffer in local memory that holds the values to pass to shader uniform buffer
		uboIndex = glGetUniformBlockIndex(program,"Uniforms");
		glGetActiveUniformBlockiv(program,uboIndex,GL_UNIFORM_BLOCK_DATA_SIZE,&uboSize);
		buffer = malloc(uboSize);
		if(buffer == NULL){
			printf("Unable to allocate buffer\n");
		}else{
			enum{Translation, Rotation, Scale, Enabled, numUniforms};
			GLfloat scale = 0.5;
			GLfloat translation[] = {0.1,0.2,0.0};
			GLfloat rotation[] = {90.0,0.0,0.0,1.0};
			GLboolean enabled = GL_TRUE;
			//names of the uniforms
			const char *uniformNames[numUniforms] = { "translation","rotation","scale","enabled"};
			GLuint indices[numUniforms];
			GLint size[numUniforms];
			GLint offset[numUniforms];
			GLint type[numUniforms];

			glGetUniformIndices(program,numUniforms,uniformNames,indices);
			glGetActiveUniformsiv(program,numUniforms,indices,GL_UNIFORM_OFFSET,offset);
			glGetActiveUniformsiv(program,numUniforms,indices,GL_UNIFORM_SIZE,size);
			glGetActiveUniformsiv(program,numUniforms,indices,GL_UNIFORM_TYPE,type);
			memcpy(buffer+offset[Scale],&scale,size[Scale]*TypeSize(type[Scale]));
			memcpy(buffer+offset[Translation],&scale,size[Translation]*TypeSize(type[Translation]));
			memcpy(buffer+offset[Rotation],&scale,size[Rotation]*TypeSize(type[Rotation]));
			memcpy(buffer+offset[Enabled],&scale,size[Enabled]*TypeSize(type[Enabled]));

			glGenBuffers(1,&ubo);
			glBindBuffer(GL_UNIFORM_BUFFER,ubo);
			glBufferData(GL_UNIFORM_BUFFER,uboSize,buffer,GL_STATIC_DRAW);
			glBindBufferBase(GL_UNIFORM_BUFFER,uboIndex,ubo);
			glGenVertexArrays(NumVAOs,VAOs);
			glBindVertexArray(VAOs[Triangles]);
			GLfloat vertices[numVertices][2] = {{-0.45,-0.45},{0.42,-0.45},{-0.45,0.42},{0.45,-0.42},{0.45,0.45},{-0.42,0.45}};
			glGenBuffers(NumBuffers,Buffers);
			glBindBuffer(GL_ARRAY_BUFFER,Buffers[ArrayBuffer]);
			glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
			glUseProgram(program);
			glVertexAttribPointer(vPosition,2,GL_FLOAT,GL_FALSE,0,BUFFER_OFFSET(0));
			glEnableVertexAttribArray(vPosition);
		}


	}
	void COpenGlEx2::draw(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(VAOs[Triangles]);
		glDrawArrays(GL_TRIANGLES,0,numVertices);
		glFlush();
	}
}
}
