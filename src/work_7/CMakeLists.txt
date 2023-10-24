# CMAKE Version
CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

# Project
SET(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
SET(PROJECT_VERSION 0.0.${PATCH_VERSION})
SET(PROJECT_NAME "bulk" CACHE STRING "Project name")
PROJECT(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Sources
SET ( SOURCES run.cpp  CommandHandler.cpp)

# Headers
SET ( HEADERS CommandHandler.h )

# Executable
add_executable(bulk ${SOURCES} ${HEADERS})

# Properties
SET_TARGET_PROPERTIES (
        bulk
        PROPERTIES
        CMAKE_CXX_STANDARD 17
        CMAKE_CXX_STANDARD_REQUIRED ON
)


if (MSVC)
    target_compile_options(cmd PRIVATE
            /W4
    )


else ()
    target_compile_options(bulk PRIVATE
            -Wall -Wextra -pedantic -Werror
    )

endif ()

install(
        TARGETS bulk
        DESTINATION bin
        EXPORT bulk
)