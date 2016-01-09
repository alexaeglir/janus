/**
 * @file CRenderer.cpp
 * @brief Basic renderer
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 12/31/15
 */
#include "CRenderer.hpp"
#include "Extensions.h"
#include "IOpenGlRed.hpp"

namespace Aeglir{
namespace LowLevRender{

		CRenderer& CRenderer::getInstance(IOpenGlRed &example)
		{
			static CRenderer renderer(example);//initialized once first time function is called
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
			_openGlExample.init();

		}
		void CRenderer::render(void)
		{

			_openGlExample.draw();
			SwapBuffers(_deviceContext);
		}
		void CRenderer::deinit(void)
		{
			wglMakeCurrent(_deviceContext,NULL);
			wglDeleteContext(_renderContext);
		}
}
}
