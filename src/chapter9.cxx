/**
 * @file chapter9.cxx
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

#include "../include/chapter9.hh"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// BASE CLASS
chapter9::StudentInterface::StudentInterface(std::string firstName,
                                             std::string lastName,
                                             int testScore) {
  setFirstName(firstName);
  setLastName(lastName);
  setTestScore(testScore);
}

void chapter9::StudentInterface::setFirstName(std::string firstName) {
  m_studentFName = firstName;
}

void chapter9::StudentInterface::setLastName(std::string lastName) {
  m_studentLName = lastName;
}

void chapter9::StudentInterface::setTestScore(int testScore) {
  m_testScore = testScore;
}

std::string chapter9::StudentInterface::getFirstName() const {
  return m_studentFName;
}

std::string chapter9::StudentInterface::getLastName() const {
  return m_studentLName;
}

int chapter9::StudentInterface::getTestScore() const { return m_testScore; }

// END BASE CLASS

chapter9::StudentType::StudentType(std::ifstream &&file, int lineNo = 0)
    : m_inputFile(std::move(file)) {
  int totalLines;
  std::string line;

  while (!file.eof()) {
    std::getline(file, line);
    totalLines++;
  }

  std::istringstream input;

  std::string inputLine;
  std::string firstName;
  std::string lastName;
  int testScore;
  int currentLine = 0;

  while (!file.eof()) {
    std::getline(file, inputLine);
    if (currentLine == lineNo) {
      file >> firstName >> lastName >> testScore;
    }
    currentLine++;
  }

  file.close();

  m_studentFName = firstName;
  m_studentLName = lastName;
  m_testScore = testScore;
  setLetterGrade();
}

void chapter9::StudentType::setLetterGrade() {
  if (m_testScore > 89)
    m_grade = 'A';

  if ((m_testScore <= 89) && (m_testScore > 79)) {
    m_grade = 'B';
  }

  if ((m_testScore <= 79) && (m_testScore > 69)) {
    m_grade = 'C';
  }

  if ((m_testScore <= 69) && (m_testScore > 59)) {
    m_grade = 'D';
  }

  if (m_testScore <= 59) {
    m_grade = 'F';
  }
}

void chapter9::StudentType::print(std::ostream &output) const {
  output << std::left << getLastName() << ", " << getFirstName() << " "
         << getTestScore() << " " << getLetterGrade();
}