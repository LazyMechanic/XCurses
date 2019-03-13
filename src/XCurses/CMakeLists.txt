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

set(XCURSES_GRAPHICS_SRCS
    ${XCURSES_INC_DIR}/Graphics/Behaviour.h
    ${XCURSES_INC_DIR}/Graphics/Border.h
    ${XCURSES_SRC_DIR}/Graphics/Border.cpp
    ${XCURSES_INC_DIR}/Graphics/Color.h
    ${XCURSES_SRC_DIR}/Graphics/Color.cpp
    ${XCURSES_INC_DIR}/Graphics/ColorPalette.h
    ${XCURSES_SRC_DIR}/Graphics/ColorPalette.cpp
    ${XCURSES_INC_DIR}/Graphics/ColorSystem.h
    ${XCURSES_SRC_DIR}/Graphics/ColorSystem.cpp
    ${XCURSES_INC_DIR}/Graphics/Container.h
    ${XCURSES_SRC_DIR}/Graphics/Container.cpp
    ${XCURSES_INC_DIR}/Graphics/Context.h
    ${XCURSES_SRC_DIR}/Graphics/Context.cpp
    ${XCURSES_INC_DIR}/Graphics/ContextSystem.h
    ${XCURSES_SRC_DIR}/Graphics/ContextSystem.cpp
    ${XCURSES_INC_DIR}/Graphics/Drawable.h
    ${XCURSES_INC_DIR}/Graphics/HasWindow.h
    ${XCURSES_SRC_DIR}/Graphics/HasWindow.cpp
    ${XCURSES_INC_DIR}/Graphics/Widget.h
    ${XCURSES_SRC_DIR}/Graphics/Widget.cpp
    ${XCURSES_INC_DIR}/Graphics/Window.h
    ${XCURSES_SRC_DIR}/Graphics/Window.cpp
    ${XCURSES_SRC_DIR}/Graphics/TreeNode.h
    ${XCURSES_SRC_DIR}/Graphics/TreeNode.cpp
    ${XCURSES_SRC_DIR}/Graphics/RootWindow.h
    ${XCURSES_SRC_DIR}/Graphics/RootWindow.cpp
)

set(XCURSES_SYSTEM_SRCS
    ${XCURSES_INC_DIR}/System/Object.h
    ${XCURSES_INC_DIR}/System/Object.inl
    ${XCURSES_SRC_DIR}/System/Object.cpp
    ${XCURSES_INC_DIR}/System/Core.h
    ${XCURSES_SRC_DIR}/System/Core.cpp
    ${XCURSES_INC_DIR}/System/CoreConfig.h
    ${XCURSES_SRC_DIR}/System/CoreConfig.cpp
    ${XCURSES_INC_DIR}/System/Input.h
    ${XCURSES_SRC_DIR}/System/Input.cpp
    ${XCURSES_INC_DIR}/System/Status.h
    ${XCURSES_SRC_DIR}/System/Status.cpp
    ${XCURSES_INC_DIR}/System/Vector.h
    ${XCURSES_INC_DIR}/System/Vector2.h
    ${XCURSES_INC_DIR}/System/Vector2.inl
    ${XCURSES_INC_DIR}/System/Vector3.h
    ${XCURSES_INC_DIR}/System/Vector3.inl
    ${XCURSES_INC_DIR}/System/Inputtable.h
    ${XCURSES_SRC_DIR}/System/Inputtable.cpp
    ${XCURSES_INC_DIR}/System/CursorState.h
)

set(XCURSES_TEXT_SRCS
    ${XCURSES_INC_DIR}/Text/Attribute.h
    ${XCURSES_SRC_DIR}/Text/Attribute.cpp
    ${XCURSES_INC_DIR}/Text/Char.h
    ${XCURSES_SRC_DIR}/Text/Char.cpp
    ${XCURSES_INC_DIR}/Text/String.h
    ${XCURSES_SRC_DIR}/Text/String.cpp
)

set(XCURSES_SRCS
    ${XCURSES_GRAPHICS_SRCS}
    ${XCURSES_SYSTEM_SRCS}
    ${XCURSES_TEXT_SRCS}
    ${XCURSES_INC_DIR}/XCurses.h
)

set(XCURSES_LIBS
    ${LIBS_DIR}/pdcurses.lib
)

add_library(XCurses STATIC 
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