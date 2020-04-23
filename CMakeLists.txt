cmake_minimum_required(VERSION 3.5)

project(ashellwig_m4c8_programming_assignment LANGUAGES CXX VERSION 0.0.1)

# -- Variables ---
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# --- Project Setup ---
set(SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/chapter8.cxx
  ${PROJECT_SOURCE_DIR}/src/general_functions.cxx
  ${PROJECT_SOURCE_DIR}/src/main.cxx
  )
add_executable(ashellwig_m4c8_programming_assignment ${SRC_FILES})


# --- Test Target ---
find_package(Catch2 REQUIRED)
set(TEST_SOURCE_FILES
  "${CMAKE_SOURCE_DIR}/src/chapter8.cxx"
  "${CMAKE_SOURCE_DIR}/test/catch_main.cxx"
  "${CMAKE_SOURCE_DIR}/test/TestCase.cxx")

add_executable(test_ashm4c8pa ${TEST_SOURCE_FILES})
target_link_libraries(test_ashm4c8pa Catch2::Catch2)
target_include_directories(test_ashm4c8pa
  "${CMAKE_SOURCE_DIR}/test/include"
  "${CMAKE_SOURCE_DIR}/include")

include(CTest)
catch_discover_tests(test_ashm4c8pa,
  EXTRA_ARGS --success --reporter console --use-colour yes --filenames-as-tags)



# --- Uninstall Target ---
if (NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/config/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)
  
  add_custom_target(uninstall
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

