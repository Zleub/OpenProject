function(preprocess out_var)
  set(result)
  foreach(in_f ${ARGN})
	set(out_f "${CMAKE_CURRENT_BINARY_DIR}/${in_f}")
	set(out "${CMAKE_CURRENT_BINARY_DIR}/${in_f}.cpp")
    add_custom_command(
      OUTPUT ${out}
	  DEPENDS ${out_f}
      COMMAND m4
      ARGS ${out_f} > ${out}
      VERBATIM
    )
    list(APPEND result ${out})
  endforeach()
  set(${out_var} "${result}" PARENT_SCOPE)
endfunction()

preprocess(prep_files test.m4)
add_library(m4_test ${prep_files})
