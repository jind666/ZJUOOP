#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main(){
    string s1 = "1.414";
    string s2 = "1.125";

    Fraction f1, f2;
    f1.conversion(s1);
    f2.conversion(s2);

    f1.print();
    f2.print();

    Fraction f3, f4;
    f3.read();
    f4.read();

    f3.print();
    f4.print();

    return 0;
}