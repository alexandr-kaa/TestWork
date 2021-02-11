cmake_minimum_required(VERSION 3.5)

project(VniiraApp LANGUAGES CXX)

add_subdirectory(../lib ${CMAKE_BINARY_DIRECTORY}/lib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)
set(CPP_LIST 
   ./src/main.cpp
)
add_executable(VniiraApp
 ${CPP_LIST} 
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
target_link_libraries(VniiraApp Qt5::Core
                      VniiraLib)
