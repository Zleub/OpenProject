//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-24T22:43:13+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-26T04:42:59+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>

namespace adebray {
	gl::window::window(int w, int h, GLFWwindow * _w) :
	width(w), height(h), win(_w) {}

	void gl::window::setVertices(GLuint count, glVerticesConfig f) {
		verticesNbr = count;

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		std::cout << "VAO: " << VAO << std::endl;

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		std::cout << "VBO: " << VBO << std::endl;

		verticesType * vertices = static_cast<verticesType *>(calloc(count, sizeof(verticesType)));
		for (size_t i = 0; i < count; i++) {
			vertices[i] = f(i);
		}

		glBufferData(GL_ARRAY_BUFFER, sizeof(verticesType) * verticesNbr, vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, sizeof(verticesType) / sizeof(float), GL_FLOAT, GL_FALSE, 0, (void*) 0);
	}

	std::string gl::window::drawing_mode(void) {
		switch (draw_mode) {
			case GL_POINTS : return "GL_POINTS" ;
			case GL_LINES : return "GL_LINES" ;
			case GL_LINE_STRIP : return "GL_LINE_STRIP" ;
			case GL_LINE_LOOP : return "GL_LINE_LOOP" ;
			case GL_TRIANGLES : return "GL_TRIANGLES" ;
			case GL_TRIANGLE_STRIP : return "GL_TRIANGLE_STRIP" ;
			case GL_TRIANGLE_FAN : return "GL_TRIANGLE_FAN" ;
			case GL_QUADS : return "GL_QUADS" ;
			default : return "NOT A DRAWING MODE" ;
		}
	}

	std::string gl::window::to_String(void) {
		std::stringstream ss;

		ss << "width: " << width << std::endl;
		ss << "height: " << height << std::endl;

		ss << "VAO: " << VAO << std::endl;
		ss << "VBO: " << VBO << std::endl;

		ss << "verticesNbr: " << verticesNbr << std::endl;
		ss << "verticesWeight: " << sizeof(verticesType) * verticesNbr << std::endl;

		ss << "vertex_shader: " << vertex_shader << std::endl;
		ss << "fragment_shader: " << fragment_shader << std::endl;
		ss << "program: " << program << std::endl;

		ss << drawing_mode();

		return ss.str();
	}
}
