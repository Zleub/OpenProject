//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-26T21:08:26+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-26T21:13:54+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>

namespace adebray {
	gl::camera::camera(void) :
		projection(glm::perspective(glm::radians(45.0f), static_cast<float>(800. / 600.), 0.1f, 100.0f)),
		view(glm::lookAt(
			glm::vec3(3, 3, 3), /* position */
			glm::vec3(0,0,0), /* direction */
			glm::vec3(0,1,0) /* head */
		)),
		model(glm::mat4(1))
	{}

	glm::mat4 gl::camera::mvp(void) {
		return projection * view * model;
	}
}
