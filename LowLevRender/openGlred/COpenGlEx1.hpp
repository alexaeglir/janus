/**
 * @file COpenGlEx1.hpp
 * @brief example 1 from opengl red book
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 01/09/2016
 */
#include "IOpenGlRed.hpp"
#ifndef __COPENGLEX1_HPP_
#define __COPENGLEX1_HPP_
namespace Aeglir{
namespace LowLevRender{
	class COpenGlEx1: public IOpenGlRed{
	public:
		COpenGlEx1():IOpenGlRed(){};
		~COpenGlEx1(){};
		void init(void);
		void draw(void);
	};
}
}
#endif
