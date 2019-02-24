set(LIBS_DIR ${PROJECT_DIR}/lib/${SYSTEM_BIT_POSTFIX})
set(XCURSES_OUTPUT_DIR ${PROJECT_DIR}/bin/${SYSTEM_BIT_POSTFIX})

set(XCURSES_INC_DIR ${PROJECT_DIR}/include/XCurses)
set(XCURSES_SRC_DIR ${PROJECT_DIR}/src/XCurses)

if (WIN32)
	add_definitions(-DXCURSES_SYSTEM_WINDOWS)
endif (WIN32)
if (UNIX)
	add_definitions(-DXCURSES_SYSTEM_UNIX)
endif (UNIX)

set(XCURSES_INCS
    ${XCURSES_INC_DIR}/XCurses.h
    ${XCURSES_INC_DIR}/Core.h
    ${XCURSES_INC_DIR}/CoreConfig.h
    ${XCURSES_INC_DIR}/Border.h
    ${XCURSES_INC_DIR}/Window.h
    ${XCURSES_INC_DIR}/Status.h
    ${XCURSES_INC_DIR}/Char.h
    ${XCURSES_INC_DIR}/Attribute.h
    ${XCURSES_INC_DIR}/Color.h
    ${XCURSES_INC_DIR}/ColorSystem.h
    ${XCURSES_INC_DIR}/ColorPalette.h
    ${XCURSES_INC_DIR}/Widget.h
    ${XCURSES_INC_DIR}/Input.h
    ${XCURSES_INC_DIR}/Context.h
    ${XCURSES_INC_DIR}/ContextComponent.h
    ${XCURSES_INC_DIR}/Object.h
    ${XCURSES_INC_DIR}/Behaviour.h
    ${XCURSES_INC_DIR}/Drawable.h
    ${XCURSES_INC_DIR}/Container.h
    ${XCURSES_INC_DIR}/HasWindow.h
    ${XCURSES_SRC_DIR}/TreeNode.h
)

set(XCURSES_SRCS
    ${XCURSES_SRC_DIR}/Core.cpp
    ${XCURSES_SRC_DIR}/CoreConfig.cpp
    ${XCURSES_SRC_DIR}/Window.cpp
    ${XCURSES_SRC_DIR}/Border.cpp
    ${XCURSES_SRC_DIR}/Status.cpp
    ${XCURSES_SRC_DIR}/Char.cpp
    ${XCURSES_SRC_DIR}/Attribute.cpp
    ${XCURSES_SRC_DIR}/Color.cpp
    ${XCURSES_SRC_DIR}/ColorSystem.cpp
    ${XCURSES_SRC_DIR}/ColorPalette.cpp
    ${XCURSES_SRC_DIR}/Widget.cpp
    ${XCURSES_SRC_DIR}/Input.cpp
    ${XCURSES_SRC_DIR}/Context.cpp
    ${XCURSES_SRC_DIR}/ContextComponent.cpp
    ${XCURSES_SRC_DIR}/Object.cpp
    ${XCURSES_SRC_DIR}/Container.cpp
    ${XCURSES_SRC_DIR}/HasWindow.cpp
    ${XCURSES_SRC_DIR}/TreeNode.cpp
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