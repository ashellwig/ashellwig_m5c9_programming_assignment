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

#include "../include/chapter9.hh"          // TBD
#include "../include/general_functions.hh" // pauseprompt
#include <fstream>
#include <iostream> // std::cout
#include <string>
/**
 * @brief Performs the steps to execute the main application.
 */
int main() {

  // Generate Student Data
  char fileName[] = "/home/ahellwig/Documents/School/CSC160/Module-5/"
                    "Programming-Assignments/"
                    "ashellwig_m5c9_programming_assignment/data/Ch9Ex2/"
                    "Ch9Ex2Data.txt";

  chapter9::StudentType student(fileName, 0);

  student.print();

  // "Press enter to continue..."
  general_functions::pauseprompt();

  // Return with exit code 0 if all goes well
  return 0;
}

// vim: set et ts=2 sw=2 ft=cpp:
