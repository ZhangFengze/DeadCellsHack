cmake_minimum_required (VERSION 3.13)
project (hack)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(3rd/Blackbone/src/Blackbone)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    link_directories(3rd/Blackbone/src/3rd_party/DIA/lib/amd64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    link_directories(3rd/Blackbone/src/3rd_party/DIA/lib)
endif()

add_executable(hack main.cpp)
target_include_directories(hack PRIVATE 3rd/Blackbone/src)
target_link_libraries(hack BlackBone diaguids.lib)