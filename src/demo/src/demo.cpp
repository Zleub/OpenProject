//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-19T23:45:13+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-20T18:23:03+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <stdio.h>
#include <demo.h>

/*
** Dump the OpenGL and GLFW versions
*/
void	gl_version(void)
{
	const unsigned char *renderer;
	const unsigned char *version;

	renderer = glGetString(GL_RENDERER);
	version = glGetString(GL_VERSION);

	printf("Compiled against GLFW %i.%i.%i\n",
		GLFW_VERSION_MAJOR,
		GLFW_VERSION_MINOR,
		GLFW_VERSION_REVISION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported: %s\n", version);
}
