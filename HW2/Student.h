#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Student {
friend ifstream &read(ifstream&, Student&);
public:
    string name;
    vector<string> courses;
    vector<int> scores;
};

ifstream &read(ifstream &is, Student &student)
{
    string information;
    getline(is, information);
    information += '\n';
    decltype(information.size()) i;
    for(i = 0; information[i] != ',' && information[i] != '\n'; i++){
        student.name += information[i];
    }

    int CoursenameOrScore = 0;
    while(information[i] != '\n'){
        i++;
        if(CoursenameOrScore%2 == 0){
            string TemCourseName;
            for(; information[i] != ',' && information[i] != '\n'; i++){
                TemCourseName += information[i];
            }
            student.courses.push_back(TemCourseName);
        }else{
            char TemScore = information[i];
            int Score = TemScore - '0';
            student.scores.push_back(Score);
            i++;
        }
        CoursenameOrScore++;
    }
    return is;
}

#endif
