set(LIBS_DIR ${PROJECT_DIR}/bin/${SYSTEM_BIT_POSTFIX})
set(TEST_OUTPUT_DIR ${PROJECT_DIR}/bin/${SYSTEM_BIT_POSTFIX})

set(TEST_LIBS 
	${LIBS_DIR}/xcurses.lib
)

set(TEST_SRC_DIR ${PROJECT_DIR}/tests/XCurses)

set(TEST_SRCS
	${TEST_SRC_DIR}/main.cpp
)

add_executable(TestXCurses
	${TEST_SRCS}
)

set_target_properties(TestXCurses PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR}
)

target_link_libraries(TestXCurses ${TEST_LIBS})

target_include_directories(TestXCurses 
	PRIVATE ${PROJECT_SRC_DIR}
	PUBLIC ${PROJECT_INC_DIR}
)