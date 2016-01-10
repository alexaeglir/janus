/**
 * @file LoadShader.cpp
 * @brief loads and compiles a shader
 * @date 12/31/15
 */
#include "LoadShader.hpp"
#include "Extensions.h"
#include <windows.h>
#include <Gl/glext.h>



namespace Aeglir{
namespace LowLevRender{



	GLuint SShaderInfo::LoadShader(void)
	{
		GLuint program;
		GLuint vertexShader;
		GLuint fragmentShader;


		vertexShader   = glCreateShader( GL_VERTEX_SHADER);	// create a vertex shader object
		fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );	// create a fragment shader object

		// load and compile vertex shader
		string shaderProgramText;
		const char* text = getShaderProgram(vShaderFile, shaderProgramText );
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
		text = getShaderProgram(fShaderFile, shaderProgramText );
		glShaderSource( fragmentShader, 1, &text, NULL );
		glCompileShader( fragmentShader );

		glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &status );

		if ( !( status == GL_TRUE ) )
			cerr << "\nFragment Shader compilation failed..." << '\n';

		infoLog = new char[100];
		bufSize = 0;
		glGetShaderInfoLog( fragmentShader, bufSize, NULL, infoLog );
		//printf("info log: %s\n",infoLog);
		/*for ( int i = 0; i < bufSize; i++ )
			cout << infoLog[ i ] << endl;
		delete [] infoLog;*/

		// create the shader program
		program = glCreateProgram();

		// attach the vertex and fragment shaders to the program
		glAttachShader( program, vertexShader );
		glAttachShader( program, fragmentShader );

		// link the objects for an executable program
		glLinkProgram( program );

		glGetProgramiv( program, GL_LINK_STATUS, &status );
		glGetProgramInfoLog( program, bufSize, NULL, infoLog );
		printf("info log: %s\n",infoLog);
		for ( int i = 0; i < bufSize; i++ )
			cout << infoLog[ i ] << endl;
		delete [] infoLog;
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
