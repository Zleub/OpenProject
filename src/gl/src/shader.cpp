//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-24T22:01:13+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-27T22:11:09+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>
#include <colors.h>

namespace adebray {
	/**
	 * The standard do nothing shader constructor.
	 */
	gl::shader::shader() {}

	/**
	 * Construct a shader based upon a shaderType and a path to the shader file.
	 */
	gl::shader::shader(GLuint type, std::string path) :
	type(type), path(path) {
		load();
		compile();
	}

	/**
	 * Read a shader file.
	 */
	GLuint gl::shader::load(void) {
		std::ifstream t(path, std::fstream::in);
		text = std::string((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
		id = glCreateShader(type);
		return id;
	}

	/**
	 * Compile a shader. Require a call shader::load before.
	 */
	int gl::shader::compile(void) {
		const char * str = text.c_str();
		glShaderSource(id, 1, &str, NULL);
		glCompileShader(id);

		GLint success = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);

		std::string strtype = shaderTypeToString(type);
		std::cout << strtype << ": " << (success == GL_FALSE ? colors::F_RED() + "Nop" + colors::RESET() : colors::F_GREEN() + "Ok" + colors::RESET()) << std::endl;
		if (success == GL_FALSE) {
			GLint logSize = 0;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logSize);

			char str[logSize + 1];
			bzero(str, logSize + 1);
			glGetShaderInfoLog(id, logSize, &logSize, &str[0]);

			std::cout << str << std::endl;
			exit(EXIT_FAILURE);
		}
		return success;
	}

	std::string gl::shader::shaderTypeToString(GLuint type) {
		switch (type) {
			case GL_VERTEX_SHADER : return "GL_VERTEX_SHADER";
			case GL_FRAGMENT_SHADER : return "GL_FRAGMENT_SHADER";
			default : return "Not a GL shaderType";
		}
	}
}
