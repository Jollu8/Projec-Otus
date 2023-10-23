cmake_minimum_required(VERSION 3.23)

set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(matrix VERSION ${PROJECT_VERSION})


configure_file(version.h.in version.h)

add_executable(${PROJECT_NAME} "run.cpp" "infinite_matrix.h")
#add_library(CustomAllocator_lib "CustomAllocator.h")

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(matrix PRIVATE
            /W4
    )


else ()
    target_compile_options(matrix PRIVATE
            -Wall -Wextra -pedantic -Werror
    )

endif ()


install(
        TARGETS matrix
        DESTINATION bin
        EXPORT matrix
)