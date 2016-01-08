/**
 * @file LoadShader.cpp
 * @brief loads and compiles a shader
 * @date 12/31/15
 */
#include "LoadShader.hpp"
#include "Extensions.h"
#include <windows.h>
#include <Gl/glext.h>

/*static PFNGLCREATESHADERPROC glCreateShader;
static PFNGLSHADERSOURCEPROC glShaderSource;
static PFNGLCOMPILESHADERPROC glCompileShader;
static PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
static PFNGLGETSHADERIVPROC glGetShaderiv;
static PFNGLCREATEPROGRAMPROC glCreateProgram;
static PFNGLGETPROGRAMIVPROC glGetProgramiv;
static PFNGLLINKPROGRAMPROC glLinkProgram;
static PFNGLATTACHSHADERPROC glAttachShader;*/

namespace Aeglir{
namespace LowLevRender{


	/*void SShaderInfo::initShaderInfo(void)
	{
		glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
		if(!glCreateShader)
			return;
		glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
		if(!glShaderSource)
			return;
		glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
		if(!glCompileShader)
			return;
		glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
		if(!glGetShaderInfoLog)
			return;
		glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
		if(!glGetShaderiv)
			return;
		glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
		if(!glCreateProgram)
			return;
		glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
		if(!glGetProgramiv)
			return;
		glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
		if(!glLinkProgram)
			return;
		glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
		if(!glAttachShader)
			return;
		_isinit = true;
	}*/
	GLuint SShaderInfo::LoadShader(SShaderInfo &shaderInfo)
	{
		GLuint program;
		GLuint vertexShader;
		GLuint fragmentShader;

		vertexShader   = glCreateShader( GL_VERTEX_SHADER);	// create a vertex shader object
		fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );	// create a fragment shader object

		// load and compile vertex shader
		string shaderProgramText;
		const char* text = getShaderProgram( shaderInfo.vShaderFile, shaderProgramText );
		GLint length = shaderProgramText.size();

		glShaderSource( vertexShader, 1,&text, NULL );
		glCompileShader( vertexShader );

		for ( int i = 0; i < length; i++ )
		{
			cout << text[ i ];
		}

		GLint status;
		glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &status );

		if ( !( status == GL_TRUE ) )
			cerr << "\nVertex Shader compilation failed..." << '\n';

		char *infoLog = new char[ 100 ];
		GLsizei bufSize = 100;
		glGetShaderInfoLog( vertexShader, bufSize, NULL, infoLog );
		for ( int i = 0; i < bufSize; i++ )
			cout << infoLog[ i ];
		delete [] infoLog;

		// load and compile fragment shader
		shaderProgramText = "";
		text = getShaderProgram( shaderInfo.fShaderFile, shaderProgramText );
		glShaderSource( fragmentShader, 1, &text, NULL );
		glCompileShader( fragmentShader );

		glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &status );

		if ( !( status == GL_TRUE ) )
			cerr << "\nFragment Shader compilation failed..." << '\n';

		infoLog = new char[100];
		bufSize = 0;
		glGetShaderInfoLog( fragmentShader, bufSize, NULL, infoLog );
		for ( int i = 0; i < bufSize; i++ )
			cout << infoLog[ i ] << endl;
		delete [] infoLog;

		// create the shader program
		program = glCreateProgram();

		// attach the vertex and fragment shaders to the program
		glAttachShader( program, vertexShader );
		glAttachShader( program, fragmentShader );

		// link the objects for an executable program
		glLinkProgram( program );

		glGetProgramiv( program, GL_LINK_STATUS, &status );
		if ( !( status == GL_TRUE ) )
			cout << "Link failed..." << endl;

		// return the program
		return program;
	}
	const char* SShaderInfo::getShaderProgram(const char *filePath,string &shaderProgramText)
	{
		fstream shaderFile(filePath,ios::in);
		string shader;
		string line;
		if(shaderFile.is_open()){
			while(getline(shaderFile,line)){
				shader += line + '\n';
			}
		}
		shaderFile.close();

		return shader.c_str();
	}
}
}
