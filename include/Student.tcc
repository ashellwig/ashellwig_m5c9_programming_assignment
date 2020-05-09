/**
 * @file Student.cxx
 * @author Ashton Hellwig <ahellwig@student.cccs.edu>
 * @brief Function template definitions for use with the Student type.
 * @version 0.1.0
 * @date 2020-05-08
 */

#include "Student.hh"
#include <fstream>  // std::fstream
#include <iomanip>  // std::setw & std::setfill
#include <iostream> // std::cout
#include <string>   // std::string

template <class StudentType> class ClassRoom : public StudentType {
public:
  void insert(const StudentType &newStudent);
  // Constructor
  ClassRoom(std::string inputFileName, std::string outputFileName) {
    std::ifstream inputFile;
    inputFile.open(inputFileName.c_str());
    std::ofstream outputFile;
    inputFile.open(outputFileName.c_str());

    if (inputFile.is_open()) {
      for (int iter = 0; iter < 20; iter++) {
        inputFile >> this->m_students[iter].m_studentFName >>
            this->students[iter].m_studentLName >>
            this->students[iter].m_testScore;
        this->students[iter].setLetterGrade(
            this->students[iter].getTestScore());
      }
    }
  }
  // Descructor
  ~ClassRoom() { delete this->m_students; }

protected:
  StudentType m_students[20];
  int length;
};
