#include <iostream>
#include <sstream>

include(`src/colors/colors.m4')

define(`p', `	std::string $1(void);')
define(`allP', `ifelse(`$#', `1', `p($1)', `p($1)
allP(shift($@))')')

namespace colors {
	std::string GENERIC(int color);

allP(colorList)
};
