//           `--::-.`
//       ./shddddddddhs+.
//     :yddddddddddddddddy:
//   `sdddddddddddddddddddds`
//  /ddddy:oddddddddds:sddddd/   @By: Debray Arnaud <adebray> - adebray@student.42.fr
//  sdddddddddddddddddddddddds   @Last modified by: adebray
//  sdddddddddddddddddddddddds
//  :ddddddddddhyyddddddddddd:   @Created: 2017-07-28T02:01:19+02:00
//   odddddddd/`:-`sdddddddds    @Modified: 2017-07-28T02:10:19+02:00
//    +ddddddh`+dh +dddddddo
//     -sdddddh///sdddddds-
//       .+ydddddddddhs/.
//           .-::::-`

#include <iostream>
#include <vector>
#include <glm/vec3.hpp>

struct opt {
	struct op {
		struct returnValue {
			enum { MOD1 } type;
			union {
				std::vector<glm::tvec3<double>> mod1;
			};
		};
		std::string arg_name;
		returnValue (*f_ptr)(char *arg);
	};
	opt(int, char **, std::vector<struct op>);
};

opt::op::returnValue get_mod1(char *filename) {
	(void)filename;
	return {
		.type = opt::op::returnValue::MOD1,
		.mod1 = {(glm::tvec3<float>){0., 0., 0.}}
	};
}

opt::opt(int argc, char **argv, std::vector<struct op> opt) {
	std::cout << "OPT start" << std::endl;
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
		std::for_each(opt.begin(), opt.end(), [&](struct op op) {
			std::cout << op.arg_name << std::endl;
			// if (op.f_ptr) {
			// 	op.f_ptr(argv[i + 1]);
			// 	i += 1;
			// }
		});
	}
}

int main(int argc, char ** argv) {
	opt _opt(argc, argv, {
		{ "--debug", 0 },
		{ "--mod1", get_mod1 }
	});
	return (0);
}
