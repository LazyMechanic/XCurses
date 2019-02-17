set(TEST_OUTPUT_DIR ${PROJECT_DIR}/test/bin/${SYSTEM_BIT_POSTFIX})
set(TEST_SRC_DIR ${PROJECT_DIR}/test/XCurses/ManualTests/HelloWorld)

set(TEST_SRCS
	${TEST_SRC_DIR}/HelloWorld.cpp
)

add_executable(HelloWorld
	${TEST_SRCS}
)

set_target_properties(HelloWorld PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR}
)

target_link_libraries(HelloWorld XCurses)

target_include_directories(HelloWorld 
	PRIVATE ${PROJECT_SRC_DIR}
	PUBLIC ${PROJECT_INC_DIR}
)