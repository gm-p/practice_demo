cmake_minimum_required(VERSION 3.5)

project(demo4)

set(CMAKE_CXX_STANDARD 11)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(
    ${PROJECT_SOURCE_DIR}/include/
)

add_library(${PROJECT_NAME} SHARED
        src/hello.cpp
) 

add_executable(test4 example/test.cpp)

target_link_libraries(test4
    ${PROJECT_NAME}
)