cmake_minimum_required(VERSION 3.26)
project(Project_Otus)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.4
)

FetchContent_MakeAvailable(json)

#add_subdirectory(${PROJECT_SOURCE_DIR}/src/work_2_FilterIP)
#add_subdirectory(${PROJECT_SOURCE_DIR}/src/work_3_allocator)
#add_subdirectory(${PROJECT_SOURCE_DIR}/src/work_4_SFINAE)
#add_subdirectory(${PROJECT_SOURCE_DIR}/src/work_5)
#add_subdirectory(${PROJECT_SOURCE_DIR}/src/work_6)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/work_7)
#add_subdirectory(${PROJECT_SOURCE_DIR}/src/work_8)
add_executable(main_exec main.cpp)

target_link_libraries(main_exec PRIVATE nlohmann_json::nlohmann_json)

