cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(XCurses)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

# Make x64
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(EXTLIBS_DIR ${PROJECT_DIR}/extlibs/x64)
    set(OUTPUT_DIR ${PROJECT_DIR}/lib/x64)
# Make x86
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(EXTLIBS_DIR ${PROJECT_DIR}/extlibs/x86)
    set(OUTPUT_DIR ${PROJECT_DIR}/lib/x86)
endif()

set(PROJECT_INC_DIR ${PROJECT_DIR}/include)
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

set(XCURSES_EXTLIBS
    ${EXTLIBS_DIR}/pdcurses.lib
)

include_directories(${PROJECT_INC_DIR})

add_library(XCurses STATIC 
    ${XCURSES_INCS}
    ${XCURSES_SRCS}
)

set_target_properties(XCurses PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}
)

#install(FILES ${XCURSES_INC_DIR} 
#	DESTINATION ${PROJECT_INC_DIR}
#)

target_link_libraries(XCurses ${XCURSES_EXTLIBS})