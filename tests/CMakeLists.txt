cmake_minimum_required(VERSION 3.5)

project(VniiraTest LANGUAGES CXX)

add_subdirectory(../lib ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS}  ${GMOCK_INCLUDE_DIRS})

set(CPP_LIST 
   ./src/main.cpp
   ./src/testfilereader.cpp 
   ./src/testactionsexecutor.cpp
   ./src/testsumaction.cpp
   ./src/testsubaction.cpp
   ./src/testxoraction.cpp
)
set(HPP_LIST
   ./src/testfilereader.hpp 
   ./src/testactionsexecutor.hpp
   ./src/testsumaction.hpp
   ./src/testsubaction.hpp
   ./src/testxoraction.hpp
)
set(RESOURCE_LIST ./resources/testdata.qrc)
add_executable(VniiraTest
 ${CPP_LIST} 
 ${HPP_LIST}
 ${RESOURCE_LIST}
)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
if (MSVC)
foreach (flag_var
             CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
             CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
             CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
             CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
  string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}")
endforeach()
endif()

target_link_libraries(VniiraTest
                      ${GTEST_BOTH_LIBRARIES}
                      Qt5::Core
                      VniiraLib
)
