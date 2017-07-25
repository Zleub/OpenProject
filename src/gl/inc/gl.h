//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-24T20:56:35+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-25T02:08:33+02:00
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

typedef int		t_vec2i __attribute__((ext_vector_type(2)));
typedef float	t_vec2f __attribute__((ext_vector_type(2)));
typedef double	t_vec2d __attribute__((ext_vector_type(2)));

typedef int		t_vec3i __attribute__((ext_vector_type(3)));
typedef float	t_vec3f __attribute__((ext_vector_type(3)));
typedef double	t_vec3d __attribute__((ext_vector_type(3)));

typedef int		t_vec4i __attribute__((ext_vector_type(4)));
typedef float	t_vec4f __attribute__((ext_vector_type(4)));
typedef double	t_vec4d __attribute__((ext_vector_type(4)));

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
			typedef t_vec3f(*glVerticesConfig)(size_t);

			window(int, int, GLFWwindow *);
			void setVertices(GLuint, glVerticesConfig);
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
		};

		static std::string version(void);
		static void printVersion(void);

		typedef void(*glRun)(struct window * window);

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
