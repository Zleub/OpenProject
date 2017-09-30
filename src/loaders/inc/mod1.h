//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-29T00:24:16+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-08-09T01:14:05+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <Iloader.h>

#include <regex>
#include <iostream>
#include <fstream>

class mod1 : public loader<int> {
public:
	mod1(std::string filename);
	virtual ~mod1 ();

	int operator[](std::size_t pos);
};
