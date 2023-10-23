cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(editor VERSION ${PROJECT_VERSION})


configure_file(version.h.in version.h)

add_executable(editor run.cpp)
add_library(print_ver lib.cpp)

set_target_properties(editor PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(print_ver
        PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(editor PRIVATE
        print_ver
)


if (MSVC)
    target_compile_options(editor PRIVATE
            /W4
    )
    target_compile_options(print_ver PRIVATE
            /W4
    )

else ()
    target_compile_options(editor PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(print_ver PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
endif ()

install(
        TARGETS editor
        DESTINATION bin
        EXPORT editor
)