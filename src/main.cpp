//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-20T00:11:14+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-25T02:11:26+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>

int main() {
	adebray::gl _gl;

	struct adebray::gl::window * w = _gl.createWindow(800, 600, "Default Window");
	_gl.printVersion();

	// w->setVertices(100, [](size_t x) -> t_vec3f{
	// 	return (t_vec3f) {
	// 		static_cast<float>(x / 100.),
	// 		static_cast<float>(x % 100 / 100.),
	// 		0.
	// 	};
	// });
	w->setVertices(3, [](size_t x) -> t_vec3f{
		if (x == 0)
			return (t_vec3f) {-1.0f, -1.0f, 0.0f};
		if (x == 1)
			return (t_vec3f) {1.0f, -1.0f, 0.0f};
		return (t_vec3f){0.0f,  1.0f, 0.0f};

	});

	adebray::gl::shader * _v = new adebray::gl::shader(GL_VERTEX_SHADER, "src/vertex.glsl");
	adebray::gl::shader * _f = new adebray::gl::shader(GL_FRAGMENT_SHADER, "src/fragment.glsl");
	_gl.createProgram(_v, _f);

	std::cout << w->to_String() << std::endl;

	_gl.run( [](struct adebray::gl::window * window){
		while (!glfwWindowShouldClose(window->win))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			// glUseProgram(window->program);
			// glDrawArrays(GL_TRIANGLE_FAN, 0, window->verticesNbr);

			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 1);
			glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);

			// Draw the triangle !
			glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

			glDisableVertexAttribArray(0);

			glfwSwapBuffers(window->win);
			glfwPollEvents();
		}
		glfwTerminate();
	});

	return (0);
}
