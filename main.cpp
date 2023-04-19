#include <iostream>
#include "Teacher.cpp"


int main() {
    Teacher Prof;
    char command;
    while(std::cin >> command && command != '0'){
        switch(command){
            case '!': {
                std::string file_name;
                std::cin >> file_name;
                Prof.InputTest(file_name);
                break;
            }
            case '+': {
                std::string student_name;
                std::cin >> student_name;
                Prof.AddStudent(student_name);
                break;
            }
            case '=': {
                Prof.HandOutTest();
                break;
            }
            case '?': {
                Prof.PrintJournal();
                break;
            }
        }
    }
    return 0;
}
