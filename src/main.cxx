/**
 * @file main.cxx
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the main function to run the program.
 * @date 2020-04-22
 *
 * Assignment: Module 5 Chapter 9 Programming Assignment
 * Description: This file contains the main function to run the program.
 * Instructor: Jeffrey Hemmes
 * Course:
 *   [CSC 160] Introduction to Programming (C++)
 * Date: 22 April 2020
 */

#include "../include/Student.hh"           // TBD
#include "../include/general_functions.hh" // pauseprompt
#include "../include/options.hh"
#include <fstream>  // std::fstream
#include <iomanip>  // std::setw & std::setfill
#include <iostream> // std::cout
#include <string>   // std::string

/**
 * @brief Performs the steps to execute the main application.
 */
int main(int argc, char *argv[]) {
  // Parse opts & args
  options::ashwig_parse(argc, argv);

  // Define input/output file
  std::string inputFileName = options::INPUT_FILE;
  std::ifstream inputFile(inputFileName);
  std::string outputFileName = options::OUTPUT_FILE;
  std::ofstream outputFile(outputFileName);

  // Declare the array of our data
  student::StudentType students[20];

  student::readIntoArray(inputFile, students)

      // Check our work...
      if (outputFile.is_open()) {
    // All test scores
    outputFile << "Student Name"
               << "\t\t\t"
               << "Test Score"
               << "\t\t\t"
               << "Grade" << std::endl;
    for (int i = 0; i < 20; i++) {
      outputFile << students[i].m_studentLName() << ", "
                 << students[i].m_studentFName() << "\t\t\t\t"
                 << students[i].m_testScore() << "\t\t\t"
                 << students[i].m_grade() << std::endl;
    }
    outputFile << std::endl;

    int highestScore = 0;
    for (int i = 0; i < 20; i++) {
      if (students[i].m_testScore > highestScore) {
        highestScore = students[i].m_testScore;
      }
    }

    // Highest test score
    outputFile << "Highest test score: " << highestScore << std::endl;

    // Students having highest score
    outputFile << "Students having the highest test score:" << std::endl;
    for (int i = 0; i < 20; i++) {
      if (students[i].m_testScore == highestScore) {
        outputFile << students[i].getLastName() << ", "
                   << students[i].getFirstName() << std::endl;
      }
    }
  }

  inputFile.close();
  outputFile.close();

  // "Press enter to continue..."
  general_functions::pauseprompt();

  // Return with exit code 0 if all goes well
  return 0;
}

// vim: set et ts=2 sw=2 ft=cpp:
