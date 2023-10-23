cmake_minimum_required(VERSION 3.23)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(print_ip_address VERSION ${PROJECT_VERSION})

configure_file(
        versiondef.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/versiondef.h
)

add_executable(print_ip run.cpp)
add_library(print_ip_lib version.cpp)

set_target_properties(print_ip print_ip_lib PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        print_ip_lib
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        .
)

target_link_libraries(print_ip PRIVATE
        print_ip_lib
)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(print_ip PRIVATE
            /W4
    )
    target_compile_options(print_ip_lib PRIVATE
            /W4
    )
else ()
    target_compile_options(print_ip PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(print_ip_lib PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
endif()

install(
        TARGETS print_ip
        DESTINATION bin
        EXPORT print_ip
)