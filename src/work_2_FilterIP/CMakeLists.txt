cmake_minimum_required(VERSION 3.23)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION})


configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(ipfilter main.cpp)
add_library(version_lib lib.cpp)
add_library(ip_lib ip.cpp ip.h)


set_target_properties(ipfilter version_lib ip_lib  PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)
target_include_directories(version_lib
        PRIVATE "${CMAKE_BINARY_DIR}"
)
target_include_directories(ip_lib
        PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(ipfilter PRIVATE
        version_lib
        ip_lib
)

install(
        TARGETS ipfilter
        DESTINATION bin
        EXPORT ipfilter
)






#
#if (MSVC)
#    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#    target_compile_options(ipfilter PRIVATE
#            /W4
#    )
#    target_compile_options(version_lib PRIVATE
#            /W4
#    )
#    target_compile_options(ip_lib PRIVATE
#            /W4
#    )
#
#else ()
#    target_compile_options(ipfilter PRIVATE
#            -Wall -Wextra -pedantic -Werror
#    )
#    target_compile_options(version_lib PRIVATE
#            -Wall -Wextra -pedantic -Werror
#    )
#    target_compile_options(ip_lib PRIVATE
#            -Wall -Wextra -pedantic -Werror
#    )
#
#endif()


