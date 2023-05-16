#include <iostream>

#include <cmath>
#include <vector>
#include <string>

class Solver {
public:

    std::string Solve(double A, double B, double C) {
        double D = Discriminant(A, B, C);
        std::string res = SpecialCases(A, B, C, D);

        if (res.empty()) {
            std::vector<double> result = Roots(A, B, C, D);
            for (auto u : result) {
                res += std::to_string(u) + " ";
            }
        }

        return res;
    }


private:
    
    double Discriminant(double A, double B, double C) {
        double D = pow(B, 2) - 4 * A * C;
        return D;
    }

    std::string SpecialCases(double A, double B, double C, double D) {
        if (A == 0 and B == 0 and C == 0) {
            return "All real numbers";
        }
        if (D < 0) {
            return "No real roots";
        }

        return "";
    }

    std::vector<double> Roots(double A, double B, double C, double D) {
        std::vector<double> result;
        if (A == 0) {
            double root = -C / B;
            result.push_back(root);
            return result;
        }
        if (D == 0) {
            double root = (-B) / (2 * A);
            result.push_back(root);
            return result;
        }

        double root1 = ((-B) + sqrt(D)) / 2 * A;
        double root2 = ((-B) - sqrt(D)) / 2 * A;
        result.push_back(root1);
        result.push_back(root2);

        return result;
    }
};