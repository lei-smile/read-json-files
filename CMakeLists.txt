cmake_minimum_required(VERSION 2.4.6)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(read_json)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas -Wfatal-errors -fPIC -Ofast -DOPENCV -std=c++11 -Wall -Wextra -pedantic -O2 -Wno-long-long -fno-omit-frame-pointer")
include_directories (${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src /usr/include /usr/include/opencv /usr/local/include) 
link_directories (${PROJECT_SOURCE_DIR}/lib /usr/loacl/lib /usr/lib/x84_64-linux-gnu)
#add_library(json_lib ${PROJECT_SOURCE_DIR}/lib/lib_json/json_reader.cpp)


add_executable(main test/main.cpp)
target_link_libraries(main json)



add_executable(write_json test/write_json.cpp)
target_link_libraries(write_json libjsoncpp.a)

add_executable(read_json test/read_json.cpp)
target_link_libraries(read_json libjsoncpp.a)

add_executable(read_json_from_str test/read_json_from_str.cpp)
target_link_libraries(read_json_from_str libjsoncpp.a)

set(CMAKE_BUILD_TYPE Release)
