set(EXAMPLE_INC_DIR ${PROJECT_DIR}/example/HelloWorld)
set(EXAMPLE_SRC_DIR ${PROJECT_DIR}/example/HelloWorld)

set(EXAMPLE_SRCS
	${EXAMPLE_SRC_DIR}/HelloWorld.cpp
)

set(EXAMPLE_NAME HelloWorld)

add_executable(${EXAMPLE_NAME}
    ${EXAMPLE_SRCS}
)

set_target_properties(${EXAMPLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${EXAMPLE_OUTPUT_DIR}
)

target_link_libraries(${EXAMPLE_NAME} 
    XCurses
)

target_include_directories(${EXAMPLE_NAME} 
    PRIVATE ${EXAMPLE_INC_DIR}
    PUBLIC ${EXAMPLE_SRC_DIR}
)