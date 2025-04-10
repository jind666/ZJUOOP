#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "DateDiary.h"

using namespace std;

int main()
{
    // Read personal diary from file
    ifstream infile("Diary.txt");
    unsigned int index = 0;
    string date;
    vector<DateDiary> personaldiary;
    while(getline(infile, date)) {
        DateDiary datediary;
        datediary.setIndex(index++);
        unsigned int year = (date[0] - 48) * 1000 + (date[1] - 48) * 100 + (date[2] - 48) * 10 + (date[3] - 48);
        unsigned int month = (date[5] - 48) * 10 + (date[6] - 48);
        unsigned int day = (date[8] - 48) * 10 + (date[9] - 48);
        datediary.setDate(year, month, day);
        string line;
        vector<string> lines;
        while(true){
            getline(infile, line);
            if(line == "."){
                break;
            }else{
                lines.push_back(line);
            }
        }
        datediary.setLines(lines);
        personaldiary.push_back(datediary);
    }
    infile.close();

    // Handle commands
    string command;
    while(true) {
        cout << "Enter a command from {'pdadd', 'pdlist', 'pdlist [YYYY-MM-DD, YYYY-MM-DD]', 'pdshow', 'pdremove', 'exit'}" << endl;
        if(getline(cin, command)) {
            if(command == "pdadd"){
                bool IsExist = false;
                string date2, line;
                vector<string> lines;
                cout << "Enter the date you want to add (YYYY-MM-DD): ";
                getline(cin, date2);
                unsigned int year = (date2[0] - 48) * 1000 + (date2[1] - 48) * 100 + (date2[2] - 48) * 10 + (date2[3] - 48);
                unsigned int month = (date2[5] - 48) * 10 + (date2[6] - 48);
                unsigned int day = (date2[8] - 48) * 10 + (date2[9] - 48);
                if(date2[4] != '-' || date2[7] != '-' || month < 1 || month > 12 || day < 1 || (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (year % 4 == 0 && month == 2 && day > 29) || (year % 4 != 0 && month == 2 && day > 28))) {
                    cout << "Invalid date format." << endl;
                    continue;
                }
                while(true){
                    cout << "------" << endl;
                    if(getline(cin, line)){
                        if(line == "."){
                            break;
                        }else{
                            lines.push_back(line);
                        }
                    }
                    else{
                        break;
                    }
                }
                for (auto it = personaldiary.begin(); it != personaldiary.end(); ++it) {
                    if(it->Year() == year && it->Month() == month && it->Day() == day) {
                        it->setLines(lines);
                        IsExist = true;
                        break;
                    }
                }
                if(IsExist){
                    ;
                }else{
                    DateDiary datediary;
                    datediary.setDate(year, month, day);
                    datediary.setLines(lines);
                    personaldiary.push_back(datediary);
                    if(personaldiary.size() == 1) {
                        personaldiary[0].setIndex(0);
                    }else{
                        int index2 = personaldiary.size() - 2;
                        for(; index2 >= 0; --index2) {
                            if(personaldiary[index2].Year() > year ? 1 : (personaldiary[index2].Year() < year ? 0 : (personaldiary[index2].Month() > month ? 1 : (personaldiary[index2].Month() < month ? 0 : (personaldiary[index2].Day() > day ? 1 : (personaldiary[index2].Day() < day ? 0 : 1)))))) {
                                personaldiary[index2 + 1] = personaldiary[index2];
                                personaldiary[index2 + 1].setIndex(index2 + 1);
                            }else{
                                personaldiary[index2 + 1] = datediary;
                                personaldiary[index2 + 1].setIndex(index2 + 1);
                                break;
                            }
                        }
                        if(index2 < 0) {
                            personaldiary[0] = datediary;
                            personaldiary[0].setIndex(0);
                        }
                    }
                }
            }
            else if(command == "pdshow"){
                string date2;
                cout << "Enter the date you want to show (YYYY-MM-DD): ";
                if(getline(cin, date2)) {
                    unsigned int year = (date2[0] - 48) * 1000 + (date2[1] - 48) * 100 + (date2[2] - 48) * 10 + (date2[3] - 48);
                    unsigned int month = (date2[5] - 48) * 10 + (date2[6] - 48);
                    unsigned int day = (date2[8] - 48) * 10 + (date2[9] - 48);
                    if(date2[4] != '-' || date2[7] != '-' || month < 1 || month > 12 || day < 1 || (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (year % 4 == 0 && month == 2 && day > 29) || (year % 4 != 0 && month == 2 && day > 28))) {
                        cout << "Invalid date format." << endl;
                        continue;
                    }
                    bool IsFound = false;
                    for(auto it = personaldiary.begin(); it != personaldiary.end(); ++it) {
                        if(it->Year() == year && it->Month() == month && it->Day() == day) {
                            IsFound = true;
                            print(cout, *it);
                            break;
                        }
                    }
                    if(!IsFound) {
                        cout << "No diary found for the date." << endl;
                    }
                }
                else{
                    cout << "Invalid date format." << endl;
                }
            }
            else if(command == "pdremove"){
                string date2;
                cout << "Enter the date you want to remove (YYYY-MM-DD): ";
                if(getline(cin, date2)) {
                    unsigned int year = (date2[0] - 48) * 1000 + (date2[1] - 48) * 100 + (date2[2] - 48) * 10 + (date2[3] - 48);
                    unsigned int month = (date2[5] - 48) * 10 + (date2[6] - 48);
                    unsigned int day = (date2[8] - 48) * 10 + (date2[9] - 48);
                    if(date2[4] != '-' || date2[7] != '-' || month < 1 || month > 12 || day < 1 || (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (year % 4 == 0 && month == 2 && day > 29) || (year % 4 != 0 && month == 2 && day > 28))) {
                        cout << "[-1] Invalid date format." << endl;
                        continue;
                    }
                    bool IsFound = false;
                    for(auto it = personaldiary.begin(); it != personaldiary.end(); ++it) {
                        if(it->Year() == year && it->Month() == month && it->Day() == day) {
                            IsFound = true;
                            for(decltype(personaldiary.size()) i = it->Index(); i != personaldiary.size() - 1; ++i) {
                                personaldiary[i] = personaldiary[i + 1];
                                personaldiary[i].setIndex(i);
                            }
                            personaldiary.pop_back();
                            break;
                        }
                    }
                    if(!IsFound) {
                        cout << "[-1] No diary found for the date." << endl;
                    }else{
                        cout << "[0] Remove successfully." << endl;
                    }
                }
                else{
                    cout << "[-1] Invalid date format." << endl;
                }
            }
            else if(command[0] == 'p' && command[1] == 'd' && command[2] == 'l' && command[3] == 'i' && command[4] == 's' && command[5] == 't') {
                if(command.size() == 6) {
                    for(auto it = personaldiary.begin(); it != personaldiary.end(); ++it) {
                        cout << setw(4) << setfill('0') << it->Year() << "-" << setw(2) << setfill('0') << it->Month() << "-" << setw(2) << setfill('0') << it->Day() << endl;
                    }
                }
                else {
                    unsigned int year1 = (command[8] - 48) * 1000 + (command[9] - 48) * 100 + (command[10] - 48) * 10 + (command[11] - 48);
                    unsigned int month1 = (command[13] - 48) * 10 + (command[14] - 48);
                    unsigned int day1 = (command[16] - 48) * 10 + (command[17] - 48);
                    unsigned int year2 = (command[20] - 48) * 1000 + (command[21] - 48) * 100 + (command[22] - 48) * 10 + (command[23] - 48);
                    unsigned int month2 = (command[25] - 48) * 10 + (command[26] - 48);
                    unsigned int day2 = (command[28] - 48) * 10 + (command[29] - 48);
                    if(command[12] != '-' || command[15] != '-' || month1 < 1 || month1 > 12 || day1 < 1 || (((month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12) && day1 > 31) || ((month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11) && day1 > 30) || (year1 % 4 == 0 && month1 == 2 && day1 > 29) || (year1 % 4 != 0 && month1 == 2 && day1 > 28))) {
                        cout << "Invalid date format." << endl;
                        continue;
                    }
                    if(command[24] != '-' || command[27] != '-' || month2 < 1 || month2 > 12 || day2 < 1 || (((month2 == 1 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 8 || month2 == 10 || month2 == 12) && day2 > 31) || ((month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) && day2 > 30) || (year2 % 4 == 0 && month2 == 2 && day2 > 29) || (year2 % 4 != 0 && month2 == 2 && day2 > 28))) {
                        cout << "Invalid date format." << endl;
                        continue;
                    }

                    decltype(personaldiary.size()) be = 0;
                    decltype(personaldiary.size()) en = personaldiary.size() - 1;
                    bool IsBigger = false;
                    bool IsSmaller = false;
                    for(decltype(personaldiary.size()) i = 0; i != personaldiary.size(); ++i) {
                        if(personaldiary[i].Year() >= year1 ? (personaldiary[i].Year() == year1 ? (personaldiary[i].Month() >= month1 ? (personaldiary[i].Month() == month1 ? (personaldiary[i].Day() >= day1 ? 1 : 0) : 1) : 0) : 1) : 0){
                            be = i;
                            IsBigger = true;
                            break;
                        }
                    }
                    for(decltype(personaldiary.size()) i = personaldiary.size() - 1; i != be - 1; --i) {
                        if(personaldiary[i].Year() <= year2 ? (personaldiary[i].Year() == year2 ? (personaldiary[i].Month() <= month2 ? (personaldiary[i].Month() == month2 ? (personaldiary[i].Day() <= day2 ? 1 : 0) : 1) : 0) : 1) : 0){
                            en = i;
                            IsSmaller = true;
                            break;
                        }
                    }
                    if(be <= en && IsBigger && IsSmaller) {
                        for(decltype(personaldiary.size()) i = be; i != en + 1; ++i) {
                            cout << setw(4) << setfill('0') << personaldiary[i].Year() << "-" << setw(2) << setfill('0') << personaldiary[i].Month() << "-" << setw(2) << setfill('0') << personaldiary[i].Day() << endl;
                        }
                    }else{
                        cout << "No diary found for the date range." << endl;
                    }
                }
            }
            else if(command == "exit") {
                break;
            }
            else{
                cout << "Invalid command." << endl;
            }
        }
        else {
            break;
        }
    }

    ofstream outfile("Diary.txt");
    printtofile(outfile, personaldiary);
    outfile.close();

    return 0;
}
