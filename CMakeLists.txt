cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(XCurses)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

# Make x64
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(LIBS_DIR ${PROJECT_DIR}/lib/x64)
    set(XCURSES_OUTPUT_DIR ${PROJECT_DIR}/bin/x64)
# Make x86
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(LIBS_DIR ${PROJECT_DIR}/lib/x86)
    set(XCURSES_OUTPUT_DIR ${PROJECT_DIR}/bin/x86)
endif()

set(PROJECT_INC_DIR ${PROJECT_DIR}/include)
set(PROJECT_SRC_DIR ${PROJECT_DIR}/src)
set(XCURSES_INC_DIR ${PROJECT_DIR}/src/XCurses)
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
    #${XCURSES_INCS}
    ${XCURSES_SRCS}
)

set_target_properties(XCurses PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${XCURSES_OUTPUT_DIR}
)

target_link_libraries(XCurses ${XCURSES_LIBS})

target_include_directories(XCurses 
	PRIVATE ${PROJECT_SRC_DIR}
	PUBLIC ${PROJECT_INC_DIR}
)

install(FILES ${XCURSES_INCS}
	DESTINATION ${PROJECT_INC_DIR}
)