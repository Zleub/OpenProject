//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-24T22:43:13+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-24T22:46:15+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>

namespace adebray {
	gl::window::window(int w, int h, GLFWwindow * _w) :
	width(w), height(h), win(_w) {}

	void gl::window::setVertices(GLuint count, glVerticesConfig f) {
		vertices.resize(count);
		for (size_t i = 0; i < count; i++) {
			vertices[i] = f(i);
		}
	}
}
