//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-24T20:53:32+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-25T02:06:34+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>

namespace adebray {
	gl::gl(void) : current(NULL) {
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	gl::~gl(void) {
		std::for_each( windows.begin(), windows.end(), [&](struct window * _w){
			glfwDestroyWindow(_w->win);
		});
	}

	/**
	* return a string with OpenGL, GLSL and GLFW versions
	*/
	std::string gl::version(void) {
		const unsigned char *renderer;
		const unsigned char *version;
		const unsigned char *glslVersion;

		renderer = glGetString(GL_RENDERER);
		version = glGetString(GL_VERSION);
		glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

		std::stringstream s;

		s << "Compiled against GLFW " <<
		GLFW_VERSION_MAJOR << "." <<
		GLFW_VERSION_MINOR << "." <<
		GLFW_VERSION_REVISION << std::endl;

		s << "Renderer: " << renderer << std::endl;
		s << "OpenGL version supported: " << version << std::endl;
		s << "GLSL version supported: " << glslVersion;
		return s.str();
	}

	void gl::printVersion(void) {
		std::cout << gl::version() << std::endl;
	}

	struct gl::window * gl::createWindow(int w, int h, std::string title) {
		GLFWwindow * window = glfwCreateWindow(w, h, title.c_str(), NULL, NULL);
		struct window * _w = new struct window(w, h, window);
		current = _w;
		glfwMakeContextCurrent(window);

		windows.push_back(_w);
		return _w;
	}

	GLuint gl::createProgram(void) {
		current->program = glCreateProgram();
		glLinkProgram(current->program);
		return current->program;
	}

	GLuint gl::createProgram(shader *vertex, shader *fragment) {
		current->program = glCreateProgram();
		current->vertex_shader = vertex->id;
		current->fragment_shader = fragment->id;
		glAttachShader(current->program, vertex->id);
		glAttachShader(current->program, fragment->id);
		glLinkProgram(current->program);
		return current->program;
	}

	void gl::run(glRun run) {
		run( current );
	}

}