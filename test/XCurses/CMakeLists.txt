set(TEST_OUTPUT_DIR ${PROJECT_DIR}/test/bin/${SYSTEM_BIT_POSTFIX})
set(TEST_SRC_DIR ${PROJECT_DIR}/test/XCurses)

file(GLOB SRC_FILES ${TEST_SRC_DIR}/Test*.cpp)
foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(FILE_BASENAME ${SRC_FILE} NAME_WE)

	add_executable(${FILE_BASENAME}
		${SRC_FILE}
	)

	add_test(
		NAME ${FILE_BASENAME}
		COMMAND ${FILE_BASENAME}
	)

	set_target_properties(${FILE_BASENAME} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR}
	)

	target_link_libraries(${FILE_BASENAME} XCurses)

	target_include_directories(${FILE_BASENAME} 
		PRIVATE ${PROJECT_SRC_DIR}
		PUBLIC ${PROJECT_INC_DIR}
	)
endforeach()