/**
 * @file ashwig_exceptions.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the definitions of exceptions classes to be used
 * in the programming assignments for FRCC's CSC160 at CCCOnline.
 * @date 2020-04-14
 *
 * Assignment: Module 4 Chapter 8 Programming Assignment
 * Description: This file contains the definitions of exceptions classes to be
 * used in the programming assignments for FRCC's CSC160 at CCCOnline.
 * functions, the previously mentioned compiler flags must be used.
 * Instructor: Jeffrey Hemmes Course: [CSC 160] Introduction to
 * Programming (C++) Date: 14 April 2020
 */

#ifndef ASHWIG_EXCEPTIONS_HH
#define ASHWIG_EXCEPTIONS_HH

#include <exception>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wc++17-extensions"
inline namespace ashwig_exceptions {
/**
 * @brief Provides exception types for additional debugging information.
 */
inline namespace exceptions {
class Chapter6InputException : public std::exception {
public:
  virtual const char *what() const throw() {
    return "Cannot have first input higher than the second.";
  }
};

class Chapter7InputException : public std::exception {
public:
  virtual const char *what() const throw() {
    return "Invalid string. Ensure it is in the format of:\n[FirstName] "
           "[LastName] [000-00-000] [S0000000] [password]";
  }
};
} // namespace exceptions
} // namespace ashwig_exceptions
#pragma GCC diagnostic pop

#endif // !ASHWIG_EXCEPTIONS_HH
