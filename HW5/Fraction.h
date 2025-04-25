#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n, int d){
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        if(d < 0){
            n = -n;
            d = -d;
        }
        int c = gcd(abs(n), abs(d));
        numerator = n / c;
        denominator = d / c;
    }
    Fraction(const Fraction& f) : numerator(f.getnumerator()), denominator(f.getdenominator()) {}

    void add(const Fraction& f){
        int n = f.getnumerator() * denominator + f.getdenominator() * numerator;
        int d = f.getdenominator() * denominator;
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        if(d < 0){
            n = -n;
            d = -d;
        }
        int c = gcd(abs(n), abs(d));
        numerator = n / c;
        denominator = d / c;
    }
    void sub(const Fraction& f){
        int n = numerator * f.getdenominator() - f.getnumerator() * denominator;
        int d = denominator * f.getdenominator();
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        if(d < 0){
            n = -n;
            d = -d;
        }
        int c = gcd(abs(n), abs(d));
        numerator = n / c;
        denominator = d / c;
    }
    void mul(const Fraction& f){
        int n = f.getnumerator() * numerator;
        int d = f.getdenominator() * denominator;
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        if(d < 0){
            n = -n;
            d = -d;
        }
        int c = gcd(abs(n), abs(d));
        numerator = n / c;
        denominator = d / c;
    }
    void div(const Fraction& f){
        int n = numerator * f.getdenominator();
        int d = f.getnumerator() * denominator;
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        if(d < 0){
            n = -n;
            d = -d;
        }
        int c = gcd(abs(n), abs(d));
        numerator = n / c;
        denominator = d / c;
    }

    bool operator==(const Fraction& f) const {
        return numerator * f.getdenominator() == f.getnumerator() * denominator;
    }
    bool operator!=(const Fraction& f) const {
        return numerator * f.getdenominator() != f.getnumerator() * denominator;
    }
    bool operator<(const Fraction& f) const {
        if(numerator < 0 && f.getnumerator() >= 0){
            return true;
        }else if(numerator >= 0 && f.getnumerator() < 0){
            return false;
        }else if(numerator < 0 && f.getnumerator() < 0){
            return numerator * f.getdenominator() < f.getnumerator() * denominator;
        }else{
            return numerator * f.getdenominator() < f.getnumerator() * denominator;
        }
    }
    bool operator<=(const Fraction& f) const {
        if(numerator < 0 && f.getnumerator() >= 0){
            return true;
        }else if(numerator >= 0 && f.getnumerator() < 0){
            return false;
        }else if(numerator < 0 && f.getnumerator() < 0){
            return numerator * f.getdenominator() <= f.getnumerator() * denominator;
        }else{
            return numerator * f.getdenominator() <= f.getnumerator() * denominator;
        }
    }
    bool operator>(const Fraction& f) const {
        if(numerator < 0 && f.getnumerator() >= 0){
            return false;
        }else if(numerator >= 0 && f.getnumerator() < 0){
            return true;
        }else if(numerator < 0 && f.getnumerator() < 0){
            return numerator * f.getdenominator() > f.getnumerator() * denominator;
        }else{
            return numerator * f.getdenominator() > f.getnumerator() * denominator;
        }
    }
    bool operator>=(const Fraction& f) const {
        if(numerator < 0 && f.getnumerator() >= 0){
            return false;
        }else if(numerator >= 0 && f.getnumerator() < 0){
            return true;
        }else if(numerator < 0 && f.getnumerator() < 0){
            return numerator * f.getdenominator() >= f.getnumerator() * denominator;
        }else{
            return numerator * f.getdenominator() >= f.getnumerator() * denominator;
        }
    }
    
    int getnumerator() const { return numerator; }
    int getdenominator() const { return denominator; }
    double ToDouble() const { return (double)numerator / denominator; }
    string ToString() const {
        if(numerator == 0){
            string s = "0";
            return s;
        }
        if(denominator == 1){
            string s = to_string(numerator);
            return s;
        }
        string s = to_string(numerator) + "/" + to_string(denominator);
        return s;
    }

    void print() const {
        if(numerator == 0){
            cout << "0" << endl;
            return;
        }
        if(denominator == 1){
            cout << numerator << endl;
            return;
        }
        cout << numerator << "/" << denominator << endl;
    }
    void read(){
        string s;
        getline(cin, s);
        int n = 0;
        int num = 0;
        bool IsInteger = true;
        bool IsNumNegative = false;
        for(auto it = s.begin(); it != s.end(); ++it){
            if(*it == '/'){
                IsInteger = false;
                break;
            }
            if(*it == '-'){
                IsNumNegative = true;
                continue;
            }
            if(*it < '0' || *it > '9'){
                cout << "Invalid input." << endl;
                return;
            }
            num = num * 10 + (*it - '0');
            n++;
        }
        int denom = 0;
        bool IsDenomNegative = false;
        if(IsInteger){
            denom = 1;
        }else{
            for(auto it = s.begin() + n + 1; it != s.end(); ++it){
                if(*it == '-'){
                    IsDenomNegative = true;
                    continue;
                }
                if(*it < '0' || *it > '9'){
                    cout << "Invalid input." << endl;
                    return;
                }
                denom = denom * 10 + (*it - '0');
            }
        }
        if(IsNumNegative){
            num = -num;
        }
        if(IsDenomNegative){
            denom = -denom;
        }
        if(denom < 0){
            num = -num;
            denom = -denom;
        }
        int c = gcd(abs(num), abs(denom));
        numerator = num / c;
        denominator = denom / c;
    }

    void conversion(string s){
        int n = 0;
        int a = 0;
        bool IsInteger = true;
        bool IsNumNegative = false;
        for(auto it = s.begin(); it != s.end(); ++it){
            if(*it == '.'){
                IsInteger = false;
                break;
            }
            if(*it == '-'){
                IsNumNegative = true;
                continue;
            }
            if(*it < '0' || *it > '9'){
                cout << "Invalid input." << endl;
                return;
            }
            a = a * 10 + (*it - '0');
            n++;
        }
        int b = 0;
        if(IsInteger){
            b = 0;
        }else{
            for(auto it = s.begin() + n + 1; it != s.end(); ++it){
                if(*it < '0' || *it > '9'){
                    cout << "Invalid input." << endl;
                    return;
                }
                a = a * 10 + (*it - '0');
                b++;
            }
        }
        int c = pow(10, b);
        if(IsNumNegative){
            a = -a;
        }

        int e = gcd(abs(a), abs(c));
        numerator = a / e;
        denominator = c / e;
    }

private:
    int numerator = 0;
    int denominator = 1;
    int gcd(int a, int b){
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

#endif
