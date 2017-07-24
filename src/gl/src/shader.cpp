//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-24T22:01:13+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-24T22:27:19+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>

namespace adebray {
	gl::shader::shader() {}
	gl::shader::shader(GLuint type, std::string path) :
	type(type), path(path) {
		load();
		compile();
	}
	GLuint gl::shader::load(void) {
		std::ifstream t(path, std::fstream::in);
		text = std::string((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
		id = glCreateShader(type);
		return id;
	}
	int gl::shader::compile(void) {
		const char * str = text.c_str();
		glShaderSource(id, 1, &str, NULL);
		glCompileShader(id);

		GLint success = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);

		std::string strtype;
		if (type == GL_VERTEX_SHADER)
		strtype = "Vertex";
		if (type == GL_FRAGMENT_SHADER)
		strtype = "Fragment";

		std::cout << strtype << " id: " << (success == GL_FALSE ? "Nop" : "Ok") << std::endl;
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
}
