cmake_minimum_required(VERSION 3.23)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
set(MY_PROJECT_NAME bayan)
project(${MY_PROJECT_NAME} VERSION ${PROJECT_VERSION})

option(WITH_BOOST "Add boost libraries" ON)

add_executable(${MY_PROJECT_NAME}
        run.cpp
        identical.cpp
)

set_target_properties(${MY_PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

if(WITH_BOOST)
    find_package(Boost COMPONENTS program_options filesystem REQUIRED)
    if(Boost_FOUND)

        include_directories(${Boost_INCLUDE_DIR})
        link_directories(${Boost_LYBRARY_DIR})

        target_link_libraries(${MY_PROJECT_NAME} ${Boost_LIBRARIES})
    endif()
endif()

if (MSVC)
    target_compile_options(${MY_PROJECT_NAME} PRIVATE
            /W4
    )

else ()
    target_compile_options(${MY_PROJECT_NAME} PRIVATE
            -Wall -Wextra -pedantic -Werror
    )

endif()

install(
        TARGETS ${MY_PROJECT_NAME}
        DESTINATION bin
        EXPORT ${MY_PROJECT_NAME}
)