#ifndef DATEDIARY_H
#define DATEDIARY_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class DateDiary {
    friend ostream &print(ostream&, const DateDiary&);
    friend ofstream &fprint(ofstream&, const DateDiary&);
public:
    DateDiary() = default;
    DateDiary(vector<string> &in_lines, unsigned int in_year, unsigned int in_month, unsigned int in_day, unsigned int in_index) : lines(in_lines), year(in_year), month(in_month), day(in_day), index(in_index) {}
    DateDiary(vector<string> &in_lines) : lines(in_lines) {}
    void setDate(unsigned int in_year, unsigned int in_month, unsigned int in_day) {
        year = in_year;
        month = in_month;
        day = in_day;
    }
    void setLines(vector<string> &in_lines) {lines = in_lines;}
    void setIndex(unsigned int in_index) {index = in_index;}
    unsigned int Year() const {return year;}
    unsigned int Month() const {return month;}
    unsigned int Day() const {return day;}
    unsigned int Index() const {return index;}
    vector<string> Lines() const {return lines;}
private:
    vector<string> lines;
    unsigned int year = 0;
    unsigned int month = 0;
    unsigned int day = 0;
    unsigned int index = 0;
};

ostream &print(ostream &os, const DateDiary &datediary) {
    vector<string> diary = datediary.Lines();

    for (auto it = diary.begin(); it != diary.end(); ++it) {
        os << *it << endl;
    }

    return os;
}

ofstream &fprint(ofstream &of, const DateDiary &datediary) {
    vector<string> diary = datediary.Lines();

    for (auto it = diary.begin(); it != diary.end(); ++it) {
        of << *it << endl;
    }

    return of;
}

ofstream &printtofile(ofstream &of, const vector<DateDiary> &datediaries) {
    for (auto it = datediaries.begin(); it != datediaries.end(); ++it) {
        of << setw(4) << setfill('0') << it->Year() << "-" << setw(2) << setfill('0') << it->Month() << "-" << setw(2) << setfill('0') << it->Day() << endl;
        fprint(of, *it);
        of << "." << endl;
    }

    return of;
}

#endif
