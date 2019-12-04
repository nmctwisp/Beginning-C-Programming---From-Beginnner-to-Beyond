// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	std::ifstream in_file{"../Challenge2/responses.txt"};
	std::string answer_key;
	in_file >> answer_key;

	std::vector<std::string> names;
	std::vector<int> grades;
	int sum_of_grades{ 0 };
	int num_of_students{ 0 };

	std::string student_name;
	std::string student_answer;

	const char border = '-';
	std::cout << std::setw(15) << std::left << "Student"
			  << std::setw(5) << std::right << "Score" << std::endl;
	std::cout << std::setw(20) << std::setfill(border) << border << std::endl;
	std::cout << std::setfill(' ');

	while (in_file >> student_name >> student_answer) {
		int grade{ 0 };
		for (size_t i = 0; i < student_answer.size(); i++) {
			if (student_answer.at(i) == answer_key.at(i)) {
				grade++;
			}
		}
		names.push_back(student_name);
		grades.push_back(grade);
		sum_of_grades += grade;
		num_of_students += 1;
		std::cout << std::setw(19) << std::left << student_name
			<< grade << std::endl;
	}
	in_file.close();
	
	std::cout << std::setw(20) << std::setfill(border) << border << std::endl;
	std::cout << std::setw(17) << std::setfill(' ') << "Average Score"
		<< std::setprecision(1) << std::fixed << (static_cast<double>(sum_of_grades) / num_of_students) 
		<< std::endl;
	
	return 0;
}

