#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>

class Solver{
public:
    Solver(std::string type){
        if(type == "Teacher"){
            chance = 1;
        }
        else{
            chance = float((time(NULL) + rand()) % 100) / 100;
            
        }
    }

    std::string Solve(float A, float B, float C){
        std::string res = SpecialCases(A, B, C);

        if(res.empty()){
            std::vector<double> result = Roots(A, B, C);
            for (auto u: result){
                res += std::to_string(u) + " ";
            }
        }

        if (CheckChance()) {
            return res;
        }
        else{
            return "";
        }
    }


private:
    float chance;
    double Discriminant(double A, double B, double C){
        double D = pow(B,2) - 4 * A * C;
        return D;
    }

    std::string SpecialCases(double A, double B, double C){
        std::string result;
        if(A == 0){
            if(B == 0){
                if(C == 0){
                    result = "All real numbers";
                }
                else{
                    result = "No real roots";
                }
            }
        }
        else{
            if(B == 0 and C != 0 and -C/A < 0){
                result = "No real roots";
            }
            if(B != 0 and C != 0 and Discriminant(A, B, C) < 0){
                result = "No real roots";
            }
        }
        return result;
    }

    std::vector<double> Roots(double A, double B, double C) {
        std::vector<double> result;
        double D = Discriminant(A, B, C);
        if(A == 0){
            if(B != 0){
                double root = -C/B;
                result.push_back(root);

            }
        }
        else if(B == 0){
            if (-C/A >= 0){
                double root = sqrt(-C/A);
                result.push_back(root);
                result.push_back(-root);

            }
        }
        else if(C == 0){
            double root1 = 0;
            double root2 = -B/A;
            result.push_back(root1);
            result.push_back(root2);

        }
        else if(D > 0 ){
            double root1 = ((-B) + sqrt(D)) / 2 * A;
            double root2 = ((-B) - sqrt(D)) / 2 * A;
            result.push_back(root1);
            result.push_back(root2);

        }
        else if(D == 0){
            double root = (-B) / (2 * A);
            result.push_back(root);

        }

        return result;
    }


    bool CheckChance(){
        float chance_now = float((time(NULL) + rand()) % 100) / 100;
        if (chance_now <= chance) {            
            return true;
        }
        else{
            return false;
        }
    }
};
