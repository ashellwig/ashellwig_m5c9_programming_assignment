cmake_minimum_required(VERSION 3.0.0)
project(ashellwig_m5c9_programming_assignment LANGUAGES CXX VERSION 0.0.1)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


cmake_minimum_required(VERSION 3.5)

# -- Variables ---
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/UninstallTarget")
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}:${CMAKE_CURRENT_SOURCE_DIR}/cmake/lib/Catch2")
set(CMAKE_CXX_FLAGS "-Wall -std=c++2a -Iinclude -isystem include/catch2")

# --- Project Executable Target ---
set(SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/chapter9.cxx
  ${PROJECT_SOURCE_DIR}/src/general_functions.cxx
  ${PROJECT_SOURCE_DIR}/src/main.cxx
  # ${PROJECT_SOURCE_DIR}/test/catch_main.cxx
  # ${PROJECT_SOURCE_DIR}/test/TestCase.cxx
)


# set(Catch2_DIR "/home/ahellwig/Documents/School/CSC160/Module-5/Programming-Assignments/ashellwig_m5c9_programming_assignment/cmake/Catch2")
# find_package(Catch2 REQUIRED)
# include(CTest)
# enable_testing()
# set(CATCH_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/catch2")
# find_path(CATCH_INCLUDE_DIR "catch.hpp")
include_directories( ${INCLUDE_DIRECTORIES} "${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/include/catch2")
add_executable(${PROJECT_NAME} ${SRC_FILES})
# include(ParseAndAddCatchTests)
# ParseAndAddCatchTests(${PROJECT_NAME})



# --- Uninstall Target ---
if (NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/UninstallTarget/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

