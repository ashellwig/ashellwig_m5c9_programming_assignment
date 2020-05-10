/**
 * @file Student.cxx
 * @author Ashton Hellwig <ahellwig@student.cccs.edu>
 * @brief Includes the headers required for interaction with StudentType
 * objects.
 * @version 0.1.0
 * @date 2020-05-08
 */

#include "../include/Student.hh"
#include "../include/Student.tcc"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// --- CONSTRUCTORS ---
student::StudentType::StudentType() {
  m_studentFName = "";
  m_studentLName = "";
  m_testScore = 0;
  m_grade = 'F';
}

student::StudentType::StudentType(std::string fName, std::string lName,
                                  int score) {
  m_studentFName = fName;
  m_studentLName = lName;
  m_testScore = score;
  m_grade = this->setLetterGrade(score);
}

void student::StudentType::setLetterGrade(int score) {
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

// Misc. Functions
int student::findHighestScore(const StudentType &students) {}

std::string student::generateStudentNameString(StudentType student) {
  return student.m_studentLName + ", " + student.m_studentLName;
}

std::vector<std::string>
student::getStudentsWithHighestScore(StudentType students[], int highScore) {
  int lcv = 0; //*< Loop control variable.
  std::vector<std::string> studentsWithHighScore;

  while (lcv < 20) {
    if (students[lcv].m_testScore == highScore) {

      studentsWithHighScore.push_back(
          student::generateStudentNameString(students[lcv]));
    }

    lcv++;
  }
}

void student::readIntoArray(std::ifstream &inputFile, StudentType students[]) {
  int lcv = 0; //*< Loop control variable.
  while (lcv < 20) {
    inputFile >> students[lcv].m_studentFName >> students[lcv].m_studentLName >>
        students[lcv].m_testScore;

    students[lcv].setLetterGrade(students[lcv].m_testScore);

    lcv++;
  }
}
