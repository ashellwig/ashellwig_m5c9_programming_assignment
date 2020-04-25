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

struct StudentInterface {
  StudentInterface();                              //*< Constructor.
  StudentInterface(std::string, std::string, int); //*< Constructor.
  virtual ~StudentInterface() = 0;                 //*< Destructor.

  // Pure Virtual Functions
  virtual void print(std::ostream &) const = 0; //*< Print function.
  virtual void setLetterGrade() = 0;

  // Setters
  void setFirstName(std::string);
  void setLastName(std::string);
  void setTestScore(int);

  // Getters
  std::string getFirstName() const;
  std::string getLastName() const;
  int getTestScore() const;
  char getLetterGrade() const;

protected:
  std::string m_studentFName; //*< Student's first name.
  std::string m_studentLName; //*< Student's last Name.
  int m_testScore;            //*< Student's test score.
  char m_grade;               //*< Student's letter grade.
};

struct StudentType : public StudentInterface {
  StudentType(std::ifstream &&, int); //*< Constructor.
  void setLetterGrade();

protected:
  std::ifstream m_inputFile; //*< Input file.
  std::string m_inputString; //*< Extracted string from `inputFile`.
};
} // namespace chapter9

#endif
