/**
 * @file options.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 *
 * @brief This file contains the arg/opt parser for the program.
 *
 * @date 2020-05-08
 */
#include <string>

namespace options {
extern bool verbose;
extern std::string INPUT_FILE;
extern std::string OUTPUT_FILE;

void ashwig_parse(int, char *[]);
} // namespace options
