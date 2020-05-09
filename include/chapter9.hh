/**
 * @file chapter9.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 *
 * @brief This file contains the function implementations used for
 * generating the student statistics based on input specified by the user.
 *
 * Assignment: Module 5 Chapter 9 Programming Assignment.
 * Description: This file contains the function implementations used for
 * generating the student statistics based on input specified by the user.
 * Instructor: Jeffrey Hemmes.
 * Course: [CSC 160] Introduction to Programming (C++).
 *
 * @date 2020-04-24
 */
#include "ashwig_exceptions.hh"
#include <fstream>
#include <iostream>
#include <string>

#ifndef _CHAPTER9_HH_INCLUDED
#  define _CHAPTER9_HH_INCLUDED

#  ifndef NDEBUG
#    define DEBUG 1
#    include "ashwig_debug.hh"
#  else
#    define DEBUG 0
#  endif

namespace chapter9 {
namespace students {
#  include "Student.hh"
#  include "Student.tcc"
} // namespace students
namespace options {
#  include "options.hh"
} // namespace options

} // namespace chapter9

#endif
