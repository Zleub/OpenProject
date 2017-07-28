//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-29T00:13:27+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-29T01:22:23+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <mod1.h>

mod1::mod1(std::string filename) {
	std::cout << "MOD1" << std::endl;

	std::ifstream t(filename, std::fstream::in);
	std::string text = std::string((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

	if (t.fail()) {
		std::cout << filename << " not a valid file." << std::endl;
		exit(EXIT_FAILURE);
	}
	else {
		// std::cout << text << std::endl;
		std::regex txt_regex("\(([0-9]+),([0-9]+),([0-9]+)\)");
	}
}

mod1::~mod1() {}

int mod1::operator[](std::size_t pos) {
	(void)pos;
	return (0);
}
