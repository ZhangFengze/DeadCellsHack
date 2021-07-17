cmake_minimum_required (VERSION 3.13)
project (hack)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(3rd/Blackbone/src/Blackbone)
link_directories(3rd/Blackbone/src/3rd_party/DIA/lib/amd64)

add_executable(hack main.cpp)
target_include_directories(hack PRIVATE 3rd/Blackbone/src)
target_link_libraries(hack BlackBone diaguids.lib)