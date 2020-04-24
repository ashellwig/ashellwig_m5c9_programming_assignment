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
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/lib/Catch2")

# --- Project Executable Target ---
set(SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/chapter9.cxx
  ${PROJECT_SOURCE_DIR}/src/general_functions.cxx
  ${PROJECT_SOURCE_DIR}/src/main.cxx
  )
if("$BUILD_TESTING")
  list(APPEND ${SRC_FILES}
    ${PROJECT_SOURCE_DIR}/test/catch_main.cxx
    ${PROJECT_SOURCE_DIR}/test/TestCase.cxx)
endif("$BUILD_TESTING")

add_executable(ashellwig_m5c9_programming_assignment ${SRC_FILES})
target_include_directories(ashellwig_m5c9_programming_assignment
  PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(ashellwig_m5c9_programming_assignment SYSTEM
  PUBLIC "${CMAKE_SOURCE_DIR}/include/catch2")
find_package(Catch2 REQUIRED)
target_link_libraries(ashellwig_m5c9_programming_assignment Catch2::Catch2)
include(CTest)
enable_testing()



# --- Uninstall Target ---
if (NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/UninstallTarget/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)
  
  add_custom_target(uninstall
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

