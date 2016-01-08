/**
 * @file LoadShader.hpp
 * @brief loads and compiles a shader
 * @date 12/31/15
 */
#ifndef __LOAD_SHADER_HPP_
#define __LOAD_SHADER_HPP_

#include <Gl/gl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


namespace Aeglir{
namespace LowLevRender{
	struct SShaderInfo{

		GLenum vTarget;
		const char* vShaderFile;
		GLenum fTarget;
		const char* fShaderFile;
		SShaderInfo():vTarget(0),vShaderFile(NULL),fTarget(0),fShaderFile(NULL),_isinit(false){};
		GLuint LoadShader(SShaderInfo &shaderInfo);
		const char* getShaderProgram(const char *filePath,string &shaderProgramText);
		//void initShaderInfo(void);
	private:
		bool _isinit;
	};
}
}
#endif
