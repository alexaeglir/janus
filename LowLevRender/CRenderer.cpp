/**
 * @file CRenderer.cpp
 * @brief Basic renderer
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 12/31/15
 */
#include "CRenderer.hpp"
#include "Extensions.h"

///variable part
#define BUFFER_OFFSET(offset) ((void*)(offset))
enum VAOIds {Triangles,NumVAOs};
enum BufferIds {ArrayBuffer,NumBuffers};
enum AttribIds {vPosition = 0};
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
const GLuint numVertices = 6;
/////
namespace Aeglir{
namespace LowLevRender{

		CRenderer& CRenderer::getInstance()
		{
			static CRenderer renderer;//initialized once first time function is called
			return renderer;//returns a reference to the singleton
		}

		void CRenderer::init(HWND hwnd)
		{
			//define the pixel format for this renderer
			_pfd = {
					sizeof(PIXELFORMATDESCRIPTOR),
					1,
					PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
					32,
					0,0,0,0,0,0,
					0,
					0,
					0,
					0,0,0,0,
					24,
					8,0,
					PFD_MAIN_PLANE,
					0,
					0,0,0
			};
			_deviceContext = GetDC(hwnd);
			int pixelFormat;
			pixelFormat = ChoosePixelFormat(_deviceContext,&_pfd);
			SetPixelFormat(_deviceContext,pixelFormat,&_pfd);

			_renderContext = wglCreateContext(_deviceContext);
			wglMakeCurrent(_deviceContext,_renderContext);
			initExtensions();
			//_shaderInfo.initShaderInfo();
			MessageBoxA(0,(char*)glGetString(GL_VERSION),"OpenGl version",0);
			////Variable init part
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
		void CRenderer::render(void)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glBindVertexArray(VAOs[Triangles]);
			glDrawArrays(GL_TRIANGLES,0,numVertices);
			glFlush();

			SwapBuffers(_deviceContext);
		}
		void CRenderer::deinit(void)
		{
			wglMakeCurrent(_deviceContext,NULL);
			wglDeleteContext(_renderContext);
		}
}
}
