//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-24T22:43:13+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-25T02:13:54+02:00
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
		// GLuint vpos_location = glGetAttribLocation(program, "vPos");
		// std::cout << "vpos: " << vpos_location << std::endl;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		std::cout << "VAO: " << VAO << std::endl;

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		std::cout << "VBO: " << VBO << std::endl;

		t_vec3f * vertices = static_cast<t_vec3f *>(calloc(count, sizeof(t_vec3f)));
		for (size_t i = 0; i < count; i++) {
			vertices[i] = f(i);
			printf("%zu: %16f %16f %16f\n", i, vertices[i].x, vertices[i].y, vertices[i].z);
		}

		glBufferData(GL_ARRAY_BUFFER, sizeof(t_vec3f) * verticesNbr, vertices, GL_STATIC_DRAW);
		// glEnableVertexAttribArray(vpos_location);
		// glVertexAttribPointer(vpos_location, sizeof(t_vec3f) / sizeof(float), GL_FLOAT, GL_FALSE, 0, (void*) 0);
	}

	std::string gl::window::to_String(void) {
		std::stringstream ss;

		ss << "width: " << width << std::endl;
		ss << "height: " << height << std::endl;

		ss << "VAO: " << VAO << std::endl;
		ss << "VBO: " << VBO << std::endl;

		ss << "verticesNbr: " << verticesNbr << std::endl;

		ss << "vertex_shader: " << vertex_shader << std::endl;
		ss << "fragment_shader: " << fragment_shader << std::endl;
		ss << "program: " << program;

		return ss.str();
	}
}
