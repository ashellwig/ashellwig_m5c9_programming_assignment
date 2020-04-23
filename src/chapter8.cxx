/**
 * @file chapter8.cxx
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the function implementations used for
 * calculating the vote statistics of data input by the user.
 * @date 2020-04-21
 *
 * Assignment: Module 4 Chapter 8 Programming Assignment.
 * Description: This file contains the function implementations used for
 * calculating the vote statistics of data input by the user.
 * Instructor: Jeffrey Hemmes.
 * Course: [CSC 160] Introduction to Programming (C++).
 * Date: 21 April 2020.
 */

#include "../include/chapter8.hh"
#include <iomanip>  //std::setw, std::setprecision
#include <iostream> // std::cin, std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string

/**
 * @brief Construct a new chapter8::Candidate::Candidate object
 */
chapter8::Candidate::Candidate() {
  // Prompt user for input to initialize our parallel arrays.
  getUserInput(m_names, m_votes);

  // Calculate number of total votes (sum of votes for all candidates).
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    m_totalVotes += m_votes[iter];
  }

  // Calculate the percentage of total votes received by each candidate and
  // store the value in a separate array.
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    m_percentOfVotes[iter] =
        100.00 * (m_votes[iter] / static_cast<double>(m_totalVotes));
  }
}

/**
 * @brief Construct a new chapter8::Candidate::Candidate object
 *
 * @param inputString The last names and number of votes for each candidates in
 * one string.
 */
chapter8::Candidate::Candidate(std::string inputString) {
  std::stringstream userInputStream(inputString);

  // Initialize Arrays
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    userInputStream >> m_names[iter] >> m_votes[iter];
  }

  // Calculate number of total votes (sum of votes for all candidates).
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    m_totalVotes += m_votes[iter];
  }

  // Calculate the percentage of total votes received by each candidate and
  // store the value in a separate array.
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    m_percentOfVotes[iter] = m_votes[iter] / static_cast<double>(m_totalVotes);
  }
}

/**
 * @brief Sets the Candidate class's private member variables using input
 * obtained via stdin.
 *
 * @param names The last names of the candidates in the election.
 * @param votes The number of votes received by the candidate.
 */
void chapter8::Candidate::getUserInput(std::string names[], int votes[]) {
  // Prompt User
  std::cout
      << "Enter candidate's last name and the votes received by the candidate."
      << std::endl;

  // Initialize our arrays
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    std::cin >> names[iter] >> votes[iter];
  }
}

/**
 * @brief Calculates the sum of votes received by all candidates.
 *
 * @return int The sum of votes received by all candidates.
 */
int chapter8::Candidate::getTotalVotes() const { return m_totalVotes; }

/**
 * @brief Returns the index of the candidate with the most votes.
 *
 * @return int The index of the candidate with the most votes.
 */
int chapter8::Candidate::getWinnerIndex() const {
  int mostVotes = 0; //*< The number of votes received by the winning candidate.
  int index = 0;     //*< Index of array.
  int lcv = sizeof(m_votes) / sizeof(m_votes[0]); //*< Loop Control Variable.

  for (int i = 0; i < lcv; i++) {
    if (m_votes[i] > mostVotes) {
      mostVotes = m_votes[i];
      index = i;
    }
  }

  return index;
}

/**
 * @brief Generates the desired output for the Chapter 8 Programming Assignment.
 */
void chapter8::Candidate::printResult() const {
  // Set local variables.
  int lcv = sizeof(m_votes) / sizeof(m_votes[0]); //*< Loop control variable.

  // Output formatted header
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << "Candidate" << std::setw(4) << " "
            << "Votes Received" << std::setw(4) << " "
            << "\% of Total Votes" << std::endl;

  // Loop which prints the election results based on our user's input.
  for (int i = 0; i < lcv; i++) {
    std::cout << std::fixed << std::setprecision(2) << std::left;
    std::cout << std::setw(16) << m_names[i] << std::setw(23) << m_votes[i]
              << m_percentOfVotes[i] << '\n';
  }

  // Find our election winner.
  int indexOfWinner = getWinnerIndex();

  // Output total number of votes received by ALL candidates.
  std::cout << "Total"
            << " " << std::setw(15) << m_totalVotes << std::endl;

  // Output winner of election.
  std::cout << "The winner of the election is " << m_names[indexOfWinner] << "."
            << std::endl;
}
