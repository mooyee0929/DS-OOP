#include <iostream>
#include <fstream>
#include <vector>
#include<cmath>
using namespace std;

class PrimeFactorization {
private:
    int num1, num2;
    vector<int> num1_factor, num2_factor;

public:
    PrimeFactorization() {
        //TO_DO: initial constructor
        num1 = 1;
        num2 = 1;
    }
    PrimeFactorization(int _a, int _b) {
        //TO_DO: _a means the first integer and _b means the second integer
        num1 = _a;
        num2 = _b;
    }
    void Get_Prime_Factorization() {
        //TO_DO: Prime factorization num1 and num2, push result to the num1_factor and num2_factor.
        int tmp1 = num1;
        for (int i = 2; i < sqrt(num1); i++) {
            while ((tmp1 % i)==0) {
                tmp1 /= i;
                num1_factor.push_back(i);
            }
        }

        if (tmp1 != 1) {
            num1_factor.push_back(tmp1);
        }


        int tmp2 = num2;
        for (int i = 2; i < sqrt(num2); i++) {
            while ((tmp2 % i)==0) {
                tmp2 /= i;
                num2_factor.push_back(i);
            }
        }

        if (tmp2 != 1) {
            num2_factor.push_back(tmp2);
        }
    }

    void Print_Prime_Factorization() {
        //TO_DO: Print num1_factor and num2_factor.
        cout << "num1_Prime_factor : \"";
        for (int i = 0; i < num1_factor.size(); i++) {
            cout << " " << num1_factor[i] << " ";
        }
        cout << "\"" << endl;

        cout << "num2_Prime_factor : \"";
        for (int i = 0; i < num2_factor.size(); i++) {
            cout << " " << num2_factor[i] << " ";
        }
        cout <<"\""<<endl;
    }

    void Print_GCD() {
        //TO_DO: Use num1_factor and num2_factor to find GCD and print the result.
        int gcd = 1, i = 0, j = 0;
        while (i < num1_factor.size() && j < num2_factor.size()) {
            if (num1_factor[i] > num2_factor[j]) {
                j++;
            }
            else if (num1_factor[i] < num2_factor[j]) {
                i++;
            }
            else {
                gcd *= num1_factor[i];
                i++;
                j++;
            }
        }
        cout << "GCD : " << gcd << endl;
    }

};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        cout << "num1 = " << a << endl;
        cout << "num2 = " << b << endl;

        PrimeFactorization PF(a, b);

        PF.Get_Prime_Factorization();
        PF.Print_Prime_Factorization();
        PF.Print_GCD();

        cout << endl;

    }

    system("PAUSE");
    return 0;
}