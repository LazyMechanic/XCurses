set(LIBS_DIR ${PROJECT_DIR}/lib/${SYSTEM_BIT_POSTFIX})
set(TEST_OUTPUT_DIR ${PROJECT_DIR}/test/bin/${SYSTEM_BIT_POSTFIX})

set(TEST_LIBS 
    ${LIBS_DIR}/pdcurses.lib
)

set(TEST_SRC_DIR ${PROJECT_DIR}/test/PDCurses)

set(TEST_SRCS
    ${TEST_SRC_DIR}/main.cpp
)

add_definitions(-DPDC_WIDE)

add_executable(TestPDCurses
    ${TEST_SRCS}
)

set_target_properties(TestPDCurses PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR}
)

target_link_libraries(TestPDCurses ${TEST_LIBS})

target_include_directories(TestPDCurses 
    PRIVATE ${PROJECT_SRC_DIR}
    PUBLIC ${PROJECT_INC_DIR}
)