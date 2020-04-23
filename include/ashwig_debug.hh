/**
 * @file ashwig_debug.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains macros, definitions, and attribues when either
 * compiling with `-DDebug` or without `-DNDEBUG`. To utilize these functions,
 * the previously mentioned compiler flags must be used.
 * @date 2020-04-14
 *
 * Assignment: Module 4 Chapter 8 Programming Assignment
 * Description: This file contains macros, definitions, and attribues when
 * either compiling with `-DDebug` or without `-DNDEBUG`. To utilize these
 * functions, the previously mentioned compiler flags must be used.
 * Instructor: Jeffrey Hemmes Course: [CSC 160] Introduction to
 * Programming (C++) Date: 02 April 2020
 */

inline namespace ashwig_debug {
/**
 * @brief Prints the output of a function call when it is sent to stderr rather
 * than stdout. Use for debugging assistance.
 */
#define verbose_print(message, ...)                                            \
  std::cerr << "[" << __FILE__ << "]: "                                        \
            << "[" << __PRETTY_FUNCTION__ << "]: "                             \
            << "[line:" << __LINE__ << "] >> " << message << __VA_ARGS__       \
            << std::endl;
} // namespace ashwig_debug
