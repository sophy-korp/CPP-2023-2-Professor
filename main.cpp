#include <iostream>
#include <map>
#include "Teacher.cpp"

enum class commands{TakeTest, AddStudent, HandOutTest, ShowJournal};
int main() {
    Teacher Prof;
    std::string command;

    std::map<std::string, commands> mapping;
    mapping["taketest"]  = commands::TakeTest;
    mapping["addstudent"]  = commands::AddStudent;
    mapping["test"]  = commands::HandOutTest;
    mapping["show"]  = commands::ShowJournal;

    while(std::cin >> command && command != "0"){
        switch(mapping[command]){
            case commands::TakeTest: {
                std::string file_name;
                std::cin >> file_name;
                Prof.InputTest(file_name);
                break;
            }
            case commands::AddStudent: {
                std::string student_name;
                std::cin >> student_name;
                Prof.AddStudent(student_name);
                break;
            }
            case commands::HandOutTest: {
                Prof.HandOutTest();
                break;
            }
            case commands::ShowJournal: {
                Prof.PrintJournal();
                break;
            }
        }
    }
    return 0;
}
