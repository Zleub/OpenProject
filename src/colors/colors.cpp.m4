#include <colors.h>

include(`src/colors/colors.m4')

define(`f', `	std::string $1(void) {
		return "\033[$2m";
	}')

define(`allF', `ifelse(`$#', `1', `f($1)', `f($1)
allF(shift($@))')')

namespace colors {

	std::string GENERIC(int color) {
		std::stringstream ss("\033[38;5;");
		ss << color << "m";
		return ss.str();
	}
allF(colorList)

};
