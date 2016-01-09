/**
 * @file IOpenGlRed.hpp
 * @brief defines an interface for various opengl test programs to run in the renderer
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 01/9/2016
 */
#ifndef __IOPENGL_RED_HPP_
#define __IOPENGL_RED_HPP_
#include "LoadShader.hpp"
using namespace Aeglir::LowLevRender;

namespace Aeglir{
namespace LowLevRender{

	class IOpenGlRed{
	protected:
	SShaderInfo _shaderInfo;
	public:
		IOpenGlRed():_shaderInfo(){};
		virtual  ~IOpenGlRed(){};
		virtual void init(void) = 0;
		virtual void draw(void) = 0;

	};
}
}
#endif
