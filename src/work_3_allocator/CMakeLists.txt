cmake_minimum_required(VERSION 3.23)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(allocator VERSION ${PROJECT_VERSION})

configure_file(
        versiondef.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/versiondef.h
)

add_executable(allocator run.cpp)
add_library(allocator_lib version.cpp)

set_target_properties(allocator allocator_lib PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        allocator_lib
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(allocator PRIVATE
        allocator_lib
)

if (MSVC)
    target_compile_options(allocator PRIVATE
            /W4
    )
    target_compile_options(allocator_lib PRIVATE
            /W4
    )
else ()
    target_compile_options(allocator PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(allocator_lib PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
endif()

install(
        TARGETS allocator
        DESTINATION bin
        EXPORT allocator
)