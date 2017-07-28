//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-28T23:20:54+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-29T01:14:38+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <gl.h>
#include <mod1.h>

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;

	if (argc != 2) {
		std::cout << "Usage: ./mod1 mapFile" << std::endl;
		return EXIT_FAILURE;
	}
	mod1 _(argv[1]);

	// adebray::gl _gl;
	//
	// struct adebray::gl::window * w = _gl.createWindow(800, 600, "Default Window");
	//
	// w->setVertices();
	//
	// _gl.createProgram(
	// 	new adebray::gl::shader(GL_VERTEX_SHADER, "src/vertex.glsl"),
	// 	new adebray::gl::shader(GL_FRAGMENT_SHADER, "src/fragment.glsl")
	// );
	// _gl.run([](unsigned int i, adebray::gl * gl){
	// 	(void)i;
	// 	(void)gl;
	// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// });

	return 0;
}
