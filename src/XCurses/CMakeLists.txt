set(LIBS_DIR ${PROJECT_DIR}/lib/${SYSTEM_BIT_POSTFIX})
set(XCURSES_OUTPUT_DIR ${PROJECT_DIR}/bin/${SYSTEM_BIT_POSTFIX})

set(XCURSES_INC_DIR ${PROJECT_DIR}/include/XCurses)
set(XCURSES_SRC_DIR ${PROJECT_DIR}/src/XCurses)

set(XCURSES_INCS
    ${XCURSES_INC_DIR}/XCurses.h
    ${XCURSES_INC_DIR}/XCursesConfig.h
    ${XCURSES_INC_DIR}/XBorder.h
    ${XCURSES_INC_DIR}/XWindow.h
)

set(XCURSES_SRCS
    ${XCURSES_SRC_DIR}/XCurses.cpp
    ${XCURSES_SRC_DIR}/XWindow.cpp
)

set(XCURSES_LIBS
    ${LIBS_DIR}/pdcurses.lib
)

add_library(XCurses STATIC 
    ${XCURSES_INCS}
    ${XCURSES_SRCS}
)

# Set output path
set_target_properties(XCurses PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${XCURSES_OUTPUT_DIR}
)

# Set extension libs
target_link_libraries(XCurses ${XCURSES_LIBS})

# Set include paths
target_include_directories(XCurses 
	PRIVATE ${PROJECT_SRC_DIR}
	PUBLIC ${PROJECT_INC_DIR}
)