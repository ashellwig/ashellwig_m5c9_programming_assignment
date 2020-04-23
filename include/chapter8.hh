/**
 * @file chapter8.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the prototypes used for
 * calculating the vote statistics of data input by the user.
 * @date 2020-04-16
 *
 * Assignment: Module 4 Chapter 8 Programming Assignment.
 * Description: This file contains the prototypes used for
 * calculating the vote statistics of data input by the user.
 * Instructor: Jeffrey Hemmes.
 * Course: [CSC 160] Introduction to Programming (C++).
 * Date: 16 April 2020.
 */

#ifndef _CHAPTER8_HH_INCLUDED
#define _CHAPTER8_HH_INCLUDED
#include <string>

#ifndef NDEBUG
#  define DEBUG 1
#  include "ashwig_debug.hh"
#else
#  define DEBUG 0
#endif

#include "ashwig_exceptions.hh"

namespace chapter8 {

class Candidate {
public:
  // Static constants
  static const int m_numberOfCandidates =
      5; //*< Number of candidates in election.

  // Constructors
  Candidate(); //*< Construct class with user input via std::cin.
  explicit Candidate(
      std::string); //*< Construct class with one string(for testing).

  // Setters
  void setTotalVotes(int[]);
  int calculatePercentOfVotes();
  // Getters
  int getTotalVotes() const;
  int getWinnerIndex() const;
  void getUserInput(std::string[], int[]);
  // Printers
  void printResult() const;

protected:
  std::string m_names[m_numberOfCandidates]; //*< Last names of candidates.
  int m_votes[m_numberOfCandidates]; //*< Number of votes for each candidate.
  double m_percentOfVotes[m_numberOfCandidates]; //*< Percentage of total votes
                                                 //*< for each candidate.
  int m_totalVotes; //*< Total votes across all candidates.
  // clang-format disable
}; // class Candidate
// clang-format enable
} // namespace chapter8
#endif // !CHAPTER8_HH_INCLUDED
