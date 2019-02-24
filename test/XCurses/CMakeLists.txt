set(TEST_OUTPUT_DIR ${PROJECT_DIR}/test/bin/${SYSTEM_BIT_POSTFIX})
set(TEST_SRC_DIR ${PROJECT_DIR}/test/XCurses)

file(GLOB files ${TEST_SRC_DIR}/Test*.cpp)
foreach(file ${files})
    get_filename_component(file_basename ${file} NAME_WE)

	add_executable(${file_basename}
		${file}
	)

	set_target_properties(${file_basename} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR}
	)

	target_link_libraries(${file_basename} XCurses)

	target_include_directories(${file_basename} 
		PRIVATE ${PROJECT_SRC_DIR}
		PUBLIC ${PROJECT_INC_DIR}
	)
endforeach()