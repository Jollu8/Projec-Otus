cmake_minimum_required(VERSION 3.26)
project(Project_Otus)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(${PROJECT_SOURCE_DIR}/src/work_2_FilterIP)
add_executable(main_exec main.cpp)

target_link_libraries(main_exec ip_lib)


