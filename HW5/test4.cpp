#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main(){
    Fraction f1(2, 3);
    Fraction f2(2, 3);
    Fraction f3(3, 4);
    Fraction f4(-3, 2);
    Fraction f5(9, -6);
    Fraction f6(-4, 3);

    bool eq1 = f1.operator==(f2);
    bool eq2 = f1.operator==(f3);
    bool eq3 = f4.operator==(f5);
    bool neq1 = f1.operator!=(f3);
    bool neq2 = f1.operator!=(f2);
    bool bigger1 = f1.operator>(f2);
    bool bigger2 = f1.operator>(f3);
    bool bigger3 = f3.operator>(f1);
    bool bigger4 = f4.operator>(f6);
    bool unsmaller1 = f1.operator>=(f2);
    bool unsmaller2 = f3.operator>=(f1);
    bool smaller1 = f1.operator<(f2);
    bool smaller2 = f1.operator<(f3);
    bool smaller3 = f3.operator<(f1);
    bool smaller4 = f4.operator<(f6);
    bool unbigger1 = f1.operator<=(f2);
    bool unbigger2 = f1.operator<=(f3);

    cout << "f1 == f2 ? " << eq1 << endl;
    cout << "f1 == f3 ? " << eq2 << endl;
    cout << "f4 == f5 ? " << eq3 << endl;
    cout << "f1 != f3 ? " << neq1 << endl;
    cout << "f1 != f2 ? " << neq2 << endl;
    cout << "f1 > f2  ? " << bigger1 << endl;
    cout << "f1 > f3  ? " << bigger2 << endl;
    cout << "f3 > f1  ? " << bigger3 << endl;
    cout << "f4 > f6  ? " << bigger4 << endl;
    cout << "f1 >= f2 ? " << unsmaller1 << endl;
    cout << "f3 >= f1 ? " << unsmaller2 << endl;
    cout << "f1 < f2  ? " << smaller1 << endl;
    cout << "f1 < f3  ? " << smaller2 << endl;
    cout << "f3 < f1  ? " << smaller3 << endl;
    cout << "f4 < f6  ? " << smaller4 << endl;
    cout << "f1 <= f2 ? " << unbigger1 << endl;
    cout << "f1 <= f3 ? " << unbigger2 << endl;

    return 0;
}