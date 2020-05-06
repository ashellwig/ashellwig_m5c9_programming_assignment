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

#include "../include/chapter9.hh"               // TBD
#include "../include/general_functions.hh"      // pauseprompt
#include "../share/include/cxxopts/cxxopts.hpp" // Argument parsing
#include <fstream>                              // std::fstream
#include <iostream>                             // std::cout
#include <string>                               // std::string

/**
 * @brief Performs the steps to execute the main application.
 */
int main(int argc, char **argv) {
  // Command-line-options
  cxxopts::Options options("ashellwig_m5c9_programming_assignment",
                           "Ashton Hellwig's solution to Module 5 Chapter 9's "
                           "programming assignment for SP2020.");

  // clang-format off
  options.add_options()
    // Debugging
    ("d,debug", "Enable debugging",
      cxxopts::value<bool>()->default_value("false"))
    // Input File
    ("f,input_file", "File used for obtaining the student's data.",
      cxxopts::value<std::string>()->default_value(
        "/home/ahellwig/Documents/School/CSC160/Module-5/"
        "Programming-Assignments/ashellwig_m5c9_programming_assignment/data/"
        "Ch9Ex2/Ch9Ex2Data.txt"
    ))
    ("o,output_file", "File used for outputting the student's data.",
      cxxopts::value<std::string>()->default_value(
        "/home/ahellwig/Documents/School/CSC160/Module-5/"
        "Programming-Assignments/ashellwig_m5c9_programming_assignment/data/"
        "OUT_Ch9Ex2Data.txt"
    ))
    ("h,help", "Print usage.")
    ;
  // Parse options
  auto result = options.parse(argc, argv);
  std::string inputFileName = result["input_file"].as<std::string>();
  std::string outputFileName = result["output_file"].as<std::string>();
  bool debugPrinting = result["debug"].as<bool>();
  // clang-format on

  if (debugPrinting) {
    std::cout << "-------------------------------------------------\n";
    std::cout << "Here is the info we are using:\n";
    std::cout << "inputFileName = " << inputFileName << std::endl;
    std::cout << "outputFileName = " << outputFileName << std::endl;
    std::cout << "debug = " << debugPrinting << std::endl;
    std::cout << "-------------------------------------------------"
              << std::endl;
  }

  // Declare object
  chapter9::StudentType students[20];

  // Use file to initialize each student
  std::ifstream inputFile;
  inputFile.open(inputFileName);
  if (inputFile.is_open()) {
    for (int iter = 0; iter < 20; iter++) {
      inputFile >> students[iter].m_studentFName >>
          students[iter].m_studentLName >> students[iter].m_testScore;
      students[iter].setLetterGrade(students[iter].getTestScore());
    }
  }

  // Check our work...
  if (debugPrinting) {
    for (int i = 0; i < 20; i++) {
      std::cout << students[i].getFirstName() << students[i].getLastName()
                << students[i].getTestScore() << students[i].getLetterGrade()
                << std::endl;
    }
  }

  // "Press enter to continue..."
  general_functions::pauseprompt();

  // Return with exit code 0 if all goes well
  return 0;
}

// vim: set et ts=2 sw=2 ft=cpp:
