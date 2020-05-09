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

StudentType::StudentType() {
  m_studentFName = "";
  m_studentLName = "";
  m_testScore = 0;
  m_grade = 'F';
}

StudentType::StudentType(std::string firstName, std::string lastName,
                         int testScore) {
  m_studentFName = firstName;
  m_studentLName = lastName;
  m_testScore = testScore;
  setLetterGrade(m_testScore);
}
