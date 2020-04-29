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

void chapter9::StudentType::setFirstName(std::string firstName) {
  m_studentFName = firstName;
}

void chapter9::StudentType::setLastName(std::string lastName) {
  m_studentLName = lastName;
}

void chapter9::StudentType::setTestScore(int testScore) {
  m_testScore = testScore;
}

std::string chapter9::StudentType::getFirstName() const {
  return m_studentFName;
}

std::string chapter9::StudentType::getLastName() const {
  return m_studentLName;
}

int chapter9::StudentType::getTestScore() const { return m_testScore; }

char chapter9::StudentType::getLetterGrade() const { return m_grade; }

chapter9::StudentType::StudentType() {
  m_studentFName = "";
  m_studentLName = "";
  m_testScore = 0;
  m_grade = 'F';
}

chapter9::StudentType::StudentType(const char *fileName, int lineNo = 0)
    : m_file(fileName) {
  int totalLines;
  std::string line;

  while (!m_file.eof()) {
    std::getline(m_file, line);
    totalLines++;
  }

  std::istringstream input;

  std::string inputLine;
  std::string firstName;
  std::string lastName;
  int testScore;
  int currentLine = 0;

  while (!m_file.eof()) {
    std::getline(m_file, inputLine);
    if (currentLine == lineNo) {
      m_file >> firstName >> lastName >> testScore;
    }
    currentLine++;
  }

  m_file.close();

  m_studentFName = firstName;
  m_studentLName = lastName;
  m_testScore = testScore;
  setLetterGrade(testScore);
}

void chapter9::StudentType::setLetterGrade(int score) {
  if (score > 89)
    m_grade = 'A';

  if ((score <= 89) && (score > 79)) {
    m_grade = 'B';
  }

  if ((score <= 79) && (score > 69)) {
    m_grade = 'C';
  }

  if ((score <= 69) && (score > 59)) {
    m_grade = 'D';
  }

  if (score <= 59) {
    m_grade = 'F';
  }
}

void chapter9::StudentType::print() const {

  std::cout << m_studentFName << ", " << m_studentLName << " " << m_testScore
            << " " << m_grade << std::endl;
}