#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Student.h"

using namespace std;

int AllScore(const Student& s);

int main(){
    ifstream file("infile.txt");

    Student s1;
    read(file, s1);
    vector<Student> students;
    students.push_back(s1);
    Student s2;
    while(read(file, s2)){
        students.push_back(s2);
        Student s3;
        s2 = s3;
    }
    // 统计学生人数
    decltype(students.size()) numberofstudents = students.size();
    vector<string> coursenames;
    coursenames.push_back((s1.courses)[0]);
    int a = 1;
    for(decltype(students.size()) i = 0; i < numberofstudents; i++){
        for(decltype((students[i].courses).size()) j = 0; j < (students[i].courses).size(); j++){
            for(decltype(coursenames.size()) k = 0; k < coursenames.size(); k++){
                if(students[i].courses[j] == coursenames[k]){
                    a = 0;
                    break;
                }
            }
            if(a == 1){
                coursenames.push_back(students[i].courses[j]);
            }
            a = 1;
        }
    }
    // 输出学生信息

    string::size_type MaxLengthOfCourseName = 0;
    for(decltype(coursenames.size()) i = 0; i < coursenames.size(); i++){
        if(MaxLengthOfCourseName < coursenames[i].size()){
            MaxLengthOfCourseName = coursenames[i].size();
        }
    }
    string::size_type MaxLengthOfStudentName = 0;
    for(decltype(students.size()) i = 0; i < students.size(); i++){
        if(MaxLengthOfStudentName < students[i].name.size()){
            MaxLengthOfStudentName = students[i].name.size();
        }
    }
    int MaxLen = 0;
    if(MaxLengthOfCourseName > MaxLengthOfStudentName){
        if(MaxLengthOfCourseName > 7){
            MaxLen = (int)MaxLengthOfCourseName;
        }else{
            MaxLen = 7;
        }
    }else{
        if(MaxLengthOfStudentName > 7){
            MaxLen = (int)MaxLengthOfStudentName;
        }else{
            MaxLen = 7;
        }
    }

    cout << left << setw(MaxLen + 2) << "no" << setw(MaxLen + 2) << "name";
    for(decltype(coursenames.size()) i = 0; i < coursenames.size(); i++){
        cout << left << setw(MaxLen + 2) << coursenames[i];
    }
    cout << left << setw(MaxLen + 2) << "average" << endl;

    for(decltype(students.size()) i = 0; i < students.size(); i++){
        cout << left << setw(MaxLen + 2) << i + 1;
        cout << left << setw(MaxLen + 2) << students[i].name;
        for(decltype(coursenames.size()) j = 0; j < coursenames.size(); j++){
            int IsCourseExist = 0;
            for(decltype((students[i].courses).size()) k = 0; k < (students[i].courses).size(); k++){
                if(students[i].courses[k] == coursenames[j]){
                    cout << left << setw(MaxLen + 2) << (students[i].scores)[k];
                    IsCourseExist = 1;
                    break;
                }
            }
            if(IsCourseExist == 0){
                cout << left << setw(MaxLen + 2) << "N/A";
            }
        }
        cout << left << setw(MaxLen + 2) << (double)AllScore(students[i]) / (students[i].courses).size() << endl;
    }

    cout << left << setw(MaxLen + 2) << " ";
    cout << left << setw(MaxLen + 2) << "average";
    for(decltype(coursenames.size()) j = 0; j < coursenames.size(); j++){
        int SumOfCourse = 0;
        int Number = 0;
        for(decltype(students.size()) i = 0; i < students.size(); i++){
            for(decltype((students[i].courses).size()) k = 0; k < (students[i].courses).size(); k++){
                if(students[i].courses[k] == coursenames[j]){
                    SumOfCourse += (students[i].scores)[k];
                    Number++;
                    break;
                }
            }
        }
        cout << left << setw(MaxLen + 2) << (double)SumOfCourse / Number;
    }
    cout << endl;

    cout << left << setw(MaxLen + 2) << " ";
    cout << left << setw(MaxLen + 2) << "min";
    for(decltype(coursenames.size()) j = 0; j < coursenames.size(); j++){
        int MinOfCourse = 100;
        for(decltype(students.size()) i = 0; i < students.size(); i++){
            for(decltype((students[i].courses).size()) k = 0; k < (students[i].courses).size(); k++){
                if(students[i].courses[k] == coursenames[j] && (students[i].scores)[k] < MinOfCourse){
                    MinOfCourse = (students[i].scores)[k];
                    break;
                }
            }
        }
        cout << left << setw(MaxLen + 2) << MinOfCourse;
    }
    cout << endl;

    cout << left << setw(MaxLen + 2) << " ";
    cout << left << setw(MaxLen + 2) << "max";
    for(decltype(coursenames.size()) j = 0; j < coursenames.size(); j++){
        int MaxOfCourse = 0;
        for(decltype(students.size()) i = 0; i < students.size(); i++){
            for(decltype((students[i].courses).size()) k = 0; k < (students[i].courses).size(); k++){
                if(students[i].courses[k] == coursenames[j] && (students[i].scores)[k] > MaxOfCourse){
                    MaxOfCourse = (students[i].scores)[k];
                    break;
                }
            }
        }
        cout << left << setw(MaxLen + 2) << MaxOfCourse;
    }
    cout << endl;

    file.close();
    return 0;
}

int AllScore(const Student& s){
    int sum = 0;
    for(decltype((s.scores).size()) i = 0; i < (s.scores).size(); i++){
        sum += (s.scores)[i];
    }
    return sum;
}
