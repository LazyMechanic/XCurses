set(TEST_OUTPUT_DIR ${PROJECT_DIR}/test/bin/${SYSTEM_BIT_POSTFIX})
set(TEST_SRC_DIR ${PROJECT_DIR}/test/XCurses/UnitTests)

set(TEST_SRCS
	${TEST_SRC_DIR}/TestColorSystem.cpp
)

add_executable(TestXCurses
	${TEST_SRCS}
)

set_target_properties(TestXCurses PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR}
)

target_link_libraries(TestXCurses XCurses)

target_include_directories(TestXCurses 
	PRIVATE ${PROJECT_SRC_DIR}
	PUBLIC ${PROJECT_INC_DIR}
)