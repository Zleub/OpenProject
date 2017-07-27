#include <colors.h>








namespace colors {

	std::string GENERIC(int color) {
		std::stringstream ss("\033[38;5;");
		ss << color << "m";
		return ss.str();
	}
	std::string RESET(void) {
		return "\033[0m";
	}
	std::string BOLD(void) {
		return "\033[1m";
	}
	std::string DIM(void) {
		return "\033[2m";
	}
	std::string UNDERLINE(void) {
		return "\033[4m";
	}
	std::string BLINK(void) {
		return "\033[5m";
	}
	std::string REVERSE(void) {
		return "\033[7m";
	}
	std::string HIDDEN(void) {
		return "\033[8m";
	}
	std::string NO_BOLD(void) {
		return "\033[21m";
	}
	std::string NO_DIM(void) {
		return "\033[22m";
	}
	std::string NO_UNDERLINE(void) {
		return "\033[24m";
	}
	std::string NO_BLINK(void) {
		return "\033[25m";
	}
	std::string NO_REVERSE(void) {
		return "\033[27m";
	}
	std::string NO_HIDDEN(void) {
		return "\033[28m";
	}
	std::string F_DEFAULT(void) {
		return "\033[39m";
	}
	std::string F_BLACK(void) {
		return "\033[30m";
	}
	std::string F_RED(void) {
		return "\033[31m";
	}
	std::string F_GREEN(void) {
		return "\033[32m";
	}
	std::string F_YELLOW(void) {
		return "\033[33m";
	}
	std::string F_BLUE(void) {
		return "\033[34m";
	}
	std::string F_MAGENTA(void) {
		return "\033[35m";
	}
	std::string F_CYAN(void) {
		return "\033[36m";
	}
	std::string F_LIGHT_GRAY(void) {
		return "\033[37m";
	}
	std::string F_DARK_GRAY(void) {
		return "\033[90m";
	}
	std::string F_LIGHT_RED(void) {
		return "\033[91m";
	}
	std::string F_LIGHT_GREEN(void) {
		return "\033[92m";
	}
	std::string F_LIGHT_YELLOW(void) {
		return "\033[93m";
	}
	std::string F_LIGHT_BLUE(void) {
		return "\033[94m";
	}
	std::string F_LIGHT_MAGENTA(void) {
		return "\033[95m";
	}
	std::string F_LIGHT_CYAN(void) {
		return "\033[96m";
	}
	std::string F_WHITE(void) {
		return "\033[97m";
	}
	std::string B_DEFAULT(void) {
		return "\033[49m";
	}
	std::string B_BLACK(void) {
		return "\033[40m";
	}
	std::string B_RED(void) {
		return "\033[41m";
	}
	std::string B_GREEN(void) {
		return "\033[42m";
	}
	std::string B_YELLOW(void) {
		return "\033[43m";
	}
	std::string B_BLUE(void) {
		return "\033[44m";
	}
	std::string B_MAGENTA(void) {
		return "\033[45m";
	}
	std::string B_CYAN(void) {
		return "\033[46m";
	}
	std::string B_LIGHT_GRAY(void) {
		return "\033[47m";
	}
	std::string B_DARK_GRAY(void) {
		return "\033[100m";
	}
	std::string B_LIGHT_RED(void) {
		return "\033[101m";
	}
	std::string B_LIGHT_GREEN(void) {
		return "\033[102m";
	}
	std::string B_LIGHT_YELLOW(void) {
		return "\033[103m";
	}
	std::string B_LIGHT_BLUE(void) {
		return "\033[104m";
	}
	std::string B_LIGHT_MAGENTA(void) {
		return "\033[105m";
	}
	std::string B_LIGHT_CYAN(void) {
		return "\033[106m";
	}
	std::string B_WHITE(void) {
		return "\033[107m";
	}

};
