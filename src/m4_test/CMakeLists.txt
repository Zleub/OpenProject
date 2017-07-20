function(preprocess out_var)
	set(result)
	foreach(in_f ${ARGN})
		string(REGEX MATCH "^(.*)\\.[^.]*$" dummy ${in_f})
		set(striped ${CMAKE_MATCH_1})

		set(in "${CMAKE_CURRENT_BINARY_DIR}/${in_f}")
		set(out "${CMAKE_CURRENT_BINARY_DIR}/${striped}")
		add_custom_command(
			OUTPUT ${out}
			DEPENDS ${in}
			COMMAND m4
			ARGS ${in} > ${out}
			VERBATIM
		)
		list(APPEND result ${out})
	endforeach()
	set(${out_var} "${result}" PARENT_SCOPE)
endfunction()

preprocess(prep_files test.cpp.m4)
add_library(m4_test ${prep_files})
