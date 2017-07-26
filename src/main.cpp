//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-20T00:11:14+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-26T04:43:14+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>

int main() {
	adebray::gl _gl;

	struct adebray::gl::window * w = _gl.createWindow(800, 600, "Default Window");
	_gl.printVersion();

	w->setVertices(100, [](size_t i) -> adebray::gl::window::verticesType {
		float x = static_cast<float>(i / 10 / 10. - 0.5);
		float y = static_cast<float>(i % 10 / 10. - 0.5);

		return (adebray::gl::window::verticesType){ x, y, 0. };
	});

	// w->setVertices(100, [](size_t i) -> adebray::gl::window::verticesType {
	// 	float x = static_cast<float>(i / 10 / 10. - 0.5);
	// 	float y = static_cast<float>(i % 10 / 10. - 0.5);
	//
	// 	return (adebray::gl::window::verticesType){ x, y, 0. };
	// });

	// w->setVertices(3, [](size_t x) -> t_vec3f{
	// 	if (x == 0)
	// 		return (t_vec3f) {-0.9f, -0.9f, 0.0f};
	// 	if (x == 1)
	// 		return (t_vec3f) {0.9f, -0.9f, 0.0f};
	// 	return (t_vec3f){0.0f,  0.9f, 0.0f};
	//
	// });

	adebray::gl::shader * _v = new adebray::gl::shader(GL_VERTEX_SHADER, "src/vertex.glsl");
	adebray::gl::shader * _f = new adebray::gl::shader(GL_FRAGMENT_SHADER, "src/fragment.glsl");
	_gl.createProgram(_v, _f);

	std::cout << w->to_String() << std::endl;

	_gl.run( [](unsigned int i, struct adebray::gl::window * window) -> void {
		glm::mat4 Projection = glm::perspective(glm::radians(45.0f), static_cast<float>(800. / 600.), 0.1f, 100.0f);
		// glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f);

		glm::mat4 View = glm::lookAt(
			glm::vec3(4 * cos(i * 2 * glm::pi<float>() / 360.), 3, 3 * sin(i * 2 * glm::pi<float>() / 360.)), // Camera is at (4,3,3), in World Space
			glm::vec3(0,0,0), // and looks at the origin
			glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
		);
		glm::mat4 Model = glm::mat4(1.0f);
		glm::mat4 mvp = Projection * View * Model;
		GLuint MatrixID = glGetUniformLocation(3, "MVP");
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(window->program);

		glEnableVertexAttribArray(0);
		glDrawArrays(GL_POINTS, 0, window->verticesNbr);
		glDisableVertexAttribArray(0);

		glfwSwapBuffers(window->win);
		glfwPollEvents();
	});

	return (0);
}
