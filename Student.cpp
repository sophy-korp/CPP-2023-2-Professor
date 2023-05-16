#include "Solver.cpp"
#include <ctime>

class Student : private Solver {
public:
    Student(std::string name_t) : name(name_t) {
        chance = double((time(NULL) + rand()) % 100) / 100;
    };

    void PrintStudent() {
        std::cout << name << " " << correct_solves << std::endl;
    };
    void PlusCorrectSolves() {
        correct_solves++;
    }
    std::string Solve(double A, double B, double C) {
         
         double chance_now = double((time(NULL) + rand()) % 100) / 100;
         if (chance_now <= chance) {
             return Solver::Solve(A, B, C);;
         }
         else {
             return "";
         }
    }
private:
    std::string name;
    int correct_solves = 0;
    double chance;

};