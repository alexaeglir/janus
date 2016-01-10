/**
 * @file COpenGlEx2.hpp
 * @brief code for chapter 2
 * @author Alexandre Meier
 * @copyright Aeglir Soft
 * @date 01/10/2016
 */
#ifndef __COPENGLEX2_HPP_
#define __COPENGLEX2_HPP_
#include "IOpenGlRed.hpp"
namespace Aeglir{
namespace LowLevRender{

	class COpenGlEx2: public IOpenGlRed{
	public:
		COpenGlEx2():IOpenGlRed(){};
		~COpenGlEx2(){};
		void init(void);
		void draw(void);
	};
}
}
#endif
