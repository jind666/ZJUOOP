#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main(){
    Fraction f1(2, 3);
    Fraction f2(0, 1);
    Fraction f3(-1, 2);
    Fraction f4(3, -2);
    Fraction f5(-3, -4);
    Fraction f6(1, 2);
    
    f1.add(f2);
    f3.sub(f4);
    f4.mul(f5);
    f5.div(f6);

    f1.print();
    f3.print();
    f4.print();
    f5.print();

    return 0;
}