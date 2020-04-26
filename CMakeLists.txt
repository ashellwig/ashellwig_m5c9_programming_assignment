cmake_minimum_required(VERSION 3.0.0)
project(ashellwig_m5c9_programming_assignment LANGUAGES CXX VERSION 0.0.1)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR "Ashton Hellwig <ahellwig@student.cccs.edu>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Programming assignment solution for Module 5 Chapter 9 in CSC160-C11 at FRCC/CCCO in SP2020.")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
include(CPack)


cmake_minimum_required(VERSION 3.5)

# -- Variables ---
# CMAKE
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/UninstallTarget")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Catch2")
# Compiler
set(CMAKE_CXX_FLAGS "-Wall -std=c++2a -Iinclude -isystem include/catch2")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -pedantic -std=c++2a -Iinclude -isystem include/catch2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -DNDEBUG")

# Assignment Solution Target
set(SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter9.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/src/general_functions.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cxx
  # ${CMAKE_CURRENT_SOURCE_DIR}/test/catch_main.cxx
  # ${CMAKE_CURRENT_SOURCE_DIR}/test/TestCase.cxx
)
set(TEST_SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter9.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/test/catch_main.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/test/TestCase.cxx
)
set(CATCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/catch2")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include" "${CATCH_INCLUDE_DIR}")
set(Catch2_DIR "/home/ahellwig/Documents/School/CSC160/Module-5/Programming-Assignments/ashellwig_m5c9_programming_assignment/cmake/Catch2")

# Testing
include(CTest)
enable_testing()
find_package(Catch2 REQUIRED)

add_executable(${PROJECT_NAME} ${SRC_FILES})

add_executable(ashwig_test ${TEST_SRC_FILES})
include(Catch)
catch_discover_tests(ashwig_test)



# --- Uninstall Target ---
if (NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/UninstallTarget/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

