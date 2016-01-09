/**
 * @file CRenderer.hpp
 * @brief Basic renderer
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 12/31/15
 */
#ifndef __CRENDERER_HPP_
#define __CRENDERER_HPP_

extern "C"{
#include <windows.h>
#include <Gl/gl.h>
}
#include "LoadShader.hpp"
namespace Aeglir{
namespace LowLevRender{
	class IOpenGlRed;
	class CRenderer{
	private:
		bool _isInit;
		PIXELFORMATDESCRIPTOR _pfd;
		HDC _deviceContext;
		HGLRC _renderContext;
		IOpenGlRed &_openGlExample;

		//Constructor, destructor and copy and copy-assignement are defined private for singleton
		CRenderer(IOpenGlRed &example):_isInit(false),_deviceContext(NULL),_renderContext(NULL),_openGlExample(example)/*,_shaderInfo()*/{};
		~CRenderer(){};
		CRenderer(CRenderer const& renderer);
		CRenderer& operator=(CRenderer const& renderer);
	public:
		//Singleton instance returned by getInstance
		static CRenderer& getInstance(IOpenGlRed &example);
		/**
		 * @brief initializes the renderer
		 */
		void init(HWND hwnd);
		/**
		 * @brief renders the scene
		 */
		void render(void);
		/**
		 * @brief deinit the renderer
		 */
		void deinit(void);

	};
}

}

#endif
