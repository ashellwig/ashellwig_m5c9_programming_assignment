/**
 * @file ashwig_exceptions.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the definitions of exceptions classes to be used
 * in the programming assignments for FRCC's CSC160 at CCCOnline.
 * @date 2020-04-22
 *
 * Assignment: Module 5 Chapter 9 Programming Assignment
 * Description: This file contains the definitions of exceptions classes to be
 * used in the programming assignments for FRCC's CSC160 at CCCOnline.
 * functions, the previously mentioned compiler flags must be used.
 * Instructor: Jeffrey Hemmes Course: [CSC 160] Introduction to
 * Programming (C++) Date: 14 April 2020
 */

#ifndef ASHWIG_EXCEPTIONS_HH
#define ASHWIG_EXCEPTIONS_HH

#include <exception>

namespace ashwig_exceptions {
/**
 * @brief Provides exception types for additional debugging information.
 */
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
} // namespace ashwig_exceptions

#endif // !ASHWIG_EXCEPTIONS_HH
