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

struct StudentType {
  StudentType(const char *, int); //*< Constructor.
  // Print Functions
  void print() const; //*< Print function.

  // Setters
  void setFirstName(std::string);
  void setLastName(std::string);
  void setTestScore(int);
  void setLetterGrade(int);

  // Getters
  std::string getFirstName() const;
  std::string getLastName() const;
  int getTestScore() const;
  char getLetterGrade() const;

private:
  std::ifstream m_file;       //*< User's input file.
  std::string m_studentFName; //*< Student's first name.
  std::string m_studentLName; //*< Student's last Name.
  int m_testScore;            //*< Student's test score.
  char m_grade;               //*< Student's letter grade.
};                            // namespace StudentType
} // namespace chapter9

#endif
