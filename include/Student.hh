#include <fstream>
#include <string>
#include <vector>

namespace student {
struct StudentType {
public:
  StudentType();
  StudentType(std::string, std::string, int); //*< Constructor.
  void setLetterGrade(int);

  // Variables
  std::string m_studentFName; //*< Student's first name.
  std::string m_studentLName; //*< Student's last Name.
  int m_testScore;            //*< Student's test score.
  char m_grade;               //*< Student's letter grade.
};
std::string generateStudentNameString(StudentType);
int findHighestScore(const StudentType &);
std::vector<std::string> getStudentsWithHighestScore(StudentType[], int);
void readIntoArray(std::ifstream &, StudentType[]);
void assignGrades(StudentType[]);
} // namespace student
