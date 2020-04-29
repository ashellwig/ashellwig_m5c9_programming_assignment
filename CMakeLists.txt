cmake_minimum_required(VERSION 3.17.0)
project(ashellwig_m5c9_programming_assignment LANGUAGES CXX VERSION 0.0.1)

# -- Config ---
## CPACK SETTINGS
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR "Ashton Hellwig <ahellwig@student.cccs.edu>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Programming assignment solution for Module 5 Chapter 9 in CSC160-C11 at FRCC/CCCO in SP2020.")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
include(CPack)
## CMAKE SETTINGS
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/out/cmake")
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}:${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/UninstallTarget:${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/UseLatexMk")
## COMPILER SETTINGS
set(CMAKE_CXX_FLAGS "-Wall -std=c++2a -Iinclude -isystem /usr/local/include/catch2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -DNDEBUG")
set(SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter9.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/src/general_functions.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cxx
)
set(TEST_SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter9.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/test/catch_main.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/test/TestCase.cxx
)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

# --- Dependencies ---
## Catch2
## https://github.com/catchorg/catch2.git (./share/catch2)
## Utilized for unit testing
find_package(Catch2 REQUIRED)


# --- Assignment Solution Target---
## Executable
enable_testing()
add_executable(${PROJECT_NAME} ${SRC_FILES})
add_executable(ashwig_test ${TEST_SRC_FILES})
target_link_libraries(ashwig_test Catch2::Catch2)


# --- Testing Target ---
include(CTest)
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(ashwig_test)


# --- Uninstall Target ---
if (NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/UninstallTarget/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

