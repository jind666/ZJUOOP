#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main(){
    Fraction f1(2, 3);
    Fraction f2(1, 2);
    Fraction f3(3, 1);
    Fraction f4(0, 2);

    double d1 = f1.ToDouble();
    double d2 = f2.ToDouble();
    double d3 = f3.ToDouble();
    double d4 = f4.ToDouble();

    string s1 = f1.ToString();
    string s2 = f2.ToString();
    string s3 = f3.ToString();
    string s4 = f4.ToString();

    cout << "f1 = " << s1 << " = " << d1 << endl;
    cout << "f2 = " << s2 << " = " << d2 << endl;
    cout << "f3 = " << s3 << " = " << d3 << endl;
    cout << "f4 = " << s4 << " = " << d4 << endl;

    return 0;
}