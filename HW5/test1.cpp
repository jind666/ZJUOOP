#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main(){
    Fraction f1;
    Fraction f2(2, 3);
    Fraction f3(f2);

    Fraction f4(-1, 2);
    Fraction f5(4, -5);
    Fraction f6(-12, -15);
    Fraction f7(9, 6);
    Fraction f8(4, 2);
    Fraction f9(3, 1);
    Fraction f10(f8);
    Fraction f11(f9);

    f1.print();
    f2.print();
    f3.print();
    f4.print();
    f5.print();
    f6.print(); 
    f7.print();
    f8.print();
    f9.print();
    f10.print();
    f11.print();

    return 0;
}
