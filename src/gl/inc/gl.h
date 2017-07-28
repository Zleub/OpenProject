//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-24T20:56:35+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-28T23:37:33+02:00
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
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>

namespace adebray {
	class gl {
	public:
		struct shader {
			static std::string shaderTypeToString(GLuint type);

			shader();
			shader(GLuint type, std::string path);
			GLuint load(void);
			int compile(void);

			GLuint id;
			GLuint type;
			std::string path;
			std::string text;
		};

		struct camera {
			camera(void);
			glm::mat4 mvp(void);

			glm::mat4 projection;
			glm::mat4 view;
			glm::mat4 model;
		};

		struct window {
			typedef glm::tvec3<float> verticesType;

			window(int, int, GLFWwindow *);
			void setVertices(GLuint, verticesType(*glVerticesConfig)(size_t));
			// void setVertices(GLuint, GLuint, verticesType(*glVerticesConfig)(size_t, size_t));
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

			struct camera camera;
		};

		static std::string version(void);
		static void printVersion(void);

		typedef void(*glRun)(unsigned int i , gl * _gl);

		gl(void);
		virtual ~gl(void);

		struct window * createWindow(int w, int h, std::string title);
		GLuint createProgram(void);
		GLuint createProgram(shader *vertex, shader *fragment);
		void run(glRun);
		struct window * getCurrentWindow(void);

	private:
		std::vector<struct window *> windows;
		struct window * current;
	};
} /* adebray */
