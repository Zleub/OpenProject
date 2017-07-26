//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-24T20:56:35+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-26T04:42:37+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#define GLFW_INCLUDE_GLCOREARB
#define GLFW_INCLUDE_GLEXT
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>

#include <glm/vec3.hpp>

namespace adebray {
	class gl {
	public:
		struct shader {
			shader();
			shader(GLuint type, std::string path);
			GLuint load(void);
			int compile(void);

			GLuint id;
			GLuint type;
			std::string path;
			std::string text;
		};

		struct window {
			typedef glm::tvec3<float> verticesType;
			typedef verticesType(*glVerticesConfig)(size_t);

			window(int, int, GLFWwindow *);
			void setVertices(GLuint, glVerticesConfig);
			std::string drawing_mode(void);
			std::string to_String(void);

			int width;
			int height;
			GLFWwindow *win;

			GLuint VAO;
			GLuint VBO;

			GLuint verticesNbr;

			GLuint vertex_shader;
			GLuint fragment_shader;
			GLuint program;

			int draw_mode;
		};

		static std::string version(void);
		static void printVersion(void);

		typedef void(*glRun)(unsigned int i , struct window * window);

		gl(void);
		virtual ~gl(void);

		struct window * createWindow(int w, int h, std::string title);
		GLuint createProgram(void);
		GLuint createProgram(shader *vertex, shader *fragment);
		void run(glRun);

	private:
		std::vector<struct window *> windows;
		struct window * current;
	};
} /* adebray */
