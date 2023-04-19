#include "Solver.cpp"
class Student : public Solver{
public:
    Student(std::string name_t) : Solver("Student"), name(name_t){};
    void PrintStudent(){
        std::cout << name << " " << correct_solves << std::endl;
    };
    void PlusCorrectSolves(){
        correct_solves++;
    }
private:
    std::string name;
    int correct_solves = 0;

};
