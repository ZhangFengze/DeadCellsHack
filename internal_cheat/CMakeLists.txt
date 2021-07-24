cmake_minimum_required (VERSION 3.13)
project (internal_cheat)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(../3rd/Blackbone/src/Blackbone ${CMAKE_CURRENT_BINARY_DIR}/Blackbone)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    link_directories(../3rd/Blackbone/src/3rd_party/DIA/lib/amd64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    link_directories(../3rd/Blackbone/src/3rd_party/DIA/lib)
endif()


aux_source_directory(. sources)
add_library(internal_cheat SHARED ${sources})

target_include_directories(internal_cheat PRIVATE ../3rd/Blackbone/src)
target_link_libraries(internal_cheat BlackBone diaguids.lib)