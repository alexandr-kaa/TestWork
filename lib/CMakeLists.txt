cmake_minimum_required(VERSION 3.5)

project(VniiraLib LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)
set(CPP_LIST 
   ./src/action.cpp 
   ./src/filereader.cpp
   ./src/sumaction.cpp
   ./src/subaction.cpp
   ./src/xoraction.cpp
   ./src/actionsexecutor.cpp
)
set(HPP_LIST
   ./src/action.hpp
   ./src/filereader.hpp
   ./src/sumaction.hpp
   ./src/subaction.hpp
   ./src/xoraction.hpp
   ./src/actionsexecutor.hpp
)
if (MSVC)
foreach (flag_var
             CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
             CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
             CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
             CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
  string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}")
endforeach()
endif()

add_library(VniiraLib
 ${CPP_LIST}
 ${HPP_LIST} 
)
target_include_directories(VniiraLib INTERFACE ./src)
target_link_libraries(VniiraLib Qt5::Core)

