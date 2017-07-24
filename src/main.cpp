//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-20T00:11:14+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-24T22:45:57+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>

int main() {
	adebray::gl _gl;

	struct adebray::gl::window * w = _gl.createWindow(800, 600, "Default Window");
	_gl.printVersion();

	w->setVertices(1000, [](size_t x){
		return (t_vec3i){static_cast<int>(x / 10), static_cast<int>(x % 10), 0};
	});

	adebray::gl::shader * _v = new adebray::gl::shader(GL_VERTEX_SHADER, "src/vertex.glsl");
	_gl.createProgram(_v);

	_gl.run( [](struct adebray::gl::window * window){
		while (!glfwWindowShouldClose(window->win))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glUseProgram(window->program);
			glDrawArrays(GL_TRIANGLE_FAN, 0, window->verticesNbr);

			glfwSwapBuffers(window->win);
			glfwPollEvents();
		}
		glfwTerminate();
	});

	return (0);
}
