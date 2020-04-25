/**
 * @file ashwig_debug.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 *
 * @brief This file contains macros, definitions, and attribues when either
 * compiling with `-DDebug` or without `-DNDEBUG`. To utilize these functions,
 * the previously mentioned compiler flags must be used.
 *
 * @date 2020-04-22
 */

namespace ashwig_debug {
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
