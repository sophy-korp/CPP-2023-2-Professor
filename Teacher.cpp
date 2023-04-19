#include "Student.cpp"
#include <vector>
#include <fstream>

struct test{
    float A, B, C;
};

class Teacher : public Solver{
public:
    Teacher() : Solver("Teacher"){};
    ~Teacher(){
        journal.clear();
        tests.clear();
    }
    void PrintJournal(){
        for(auto u: journal){
            u.PrintStudent();
        }
    }
    void InputTest(std::string Input){
        tests.clear();
        std::ifstream input_file (Input);
        if(!input_file.is_open()){
            std::cout << "input file error" << std::endl;
            return;
        }
        float A, B, C;
        while (input_file >> A && input_file >> B && input_file >> C){
            tests.push_back({A, B, C});
        }
        input_file.close();
    }

    void HandOutTest(){
        for(auto t: tests){
            std::string solution = Solver::Solve(t.A, t.B, t.C);
            for(auto& s: journal){
                std::string studsolution = s.Solve(t.A, t.B, t.C);
                if(solution == studsolution){
                    s.PlusCorrectSolves();
                }
            }
        }
    }
    void AddStudent(std::string name){
        journal.push_back(Student(name));
    }
private:
    std::vector<Student>journal;
    std::vector<test>tests;
};
