#include <fstream>
#include <string>

struct StudentType {
public:
  StudentType();
  StudentType(std::string, std::string, int); //*< Constructor.
  // Print Functions
  void print() const; //*< Print function.

  // Setters
  void setFirstName(std::string);
  void setLastName(std::string);
  void setTestScore(int);
  void setLetterGrade(int);

  // Getters
  std::string getFirstName() const;
  std::string getLastName() const;
  int getTestScore() const;
  char getLetterGrade() const;

  // Variables
  std::ifstream m_file;       //*< User's input file.
  std::string m_studentFName; //*< Student's first name.
  std::string m_studentLName; //*< Student's last Name.
  int m_testScore;            //*< Student's test score.
  char m_grade;               //*< Student's letter grade.
};                            // namespace StudentType