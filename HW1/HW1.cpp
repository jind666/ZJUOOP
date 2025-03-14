// 请先阅读README，再检查程序，谢谢！
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    string Name[10]; // 字符串数组用来保存学生的名字
    char Score[10][3]; // 用一个二维数组来保存学生的成绩，因为成绩只在1-5之间，为了方便读取输入，所以用了char类型

    string input; // 读取输入的字符串
    for(int i = 0; i < 10; i++){
        getline(cin, input); // 这里使用getline函数来读取一整行输入
        unsigned int j;
        for(j = 0; input[j] != ',' && input[j] != '\n'; j++){
            Name[i] += input[j]; // 这里用字符串拼接的方式来读取学生的名字
        }
        j++; // 跳过逗号
        for(; input[j] != ',' && input[j] != '\n'; j++){
            Score[i][0] = input[j];
        }
        j++; // 跳过逗号
        for(; input[j] != ',' && input[j] != '\n'; j++){
            Score[i][1] = input[j];
        }
        j++; // 跳过逗号
        for(; input[j] != ',' && input[j] != '\n'; j++){
            Score[i][2] = input[j];
            break; // 跳过换行符
        }
    }

    cout << "no      name    score1  score2  score3  average" << endl;
    for(int j = 0; j < 9; j++){
        cout << j + 1 << "       " << Name[j];
        int k = 8 - Name[j].length();
        for(; k > 0; k--){
            cout << " ";
        }
        cout << Score[j][0] << "       " << Score[j][1] << "       "
             << Score[j][2] << "       " << (float)((Score[j][0] - 48) + (Score[j][1] - 48) + (Score[j][2] - 48))/3 << endl; // 根据要求这里用的是float类型
    }
    cout << "10" << "      " << Name[9]; // 第10个学生的空格数与前面稍有不同，所以分开来写
    int k = 8 - Name[9].length();
    for(; k > 0; k--){
        cout << " ";
    }
    cout << Score[9][0] << "       " << Score[9][1] << "       "
         << Score[9][2] << "       " << (float)((Score[9][0] - 48) + (Score[9][1] - 48) + (Score[9][2] - 48))/3 << endl; // 这里也是用float类型

    double AverageOfScore1 = (double)((Score[0][0] - 48) + (Score[1][0] - 48) + (Score[2][0] - 48) + (Score[3][0] - 48) + (Score[4][0] - 48) + (Score[5][0] - 48) + (Score[6][0] - 48) + (Score[7][0] - 48) + (Score[8][0] - 48) + (Score[9][0] - 48))/10;
    double AverageOfScore2 = (double)((Score[0][1] - 48) + (Score[1][1] - 48) + (Score[2][1] - 48) + (Score[3][1] - 48) + (Score[4][1] - 48) + (Score[5][1] - 48) + (Score[6][1] - 48) + (Score[7][1] - 48) + (Score[8][1] - 48) + (Score[9][1] - 48))/10;
    double AverageOfScore3 = (double)((Score[0][2] - 48) + (Score[1][2] - 48) + (Score[2][2] - 48) + (Score[3][2] - 48) + (Score[4][2] - 48) + (Score[5][2] - 48) + (Score[6][2] - 48) + (Score[7][2] - 48) + (Score[8][2] - 48) + (Score[9][2] - 48))/10;
    cout << "        " << "average" << " " << fixed << setprecision(1) << AverageOfScore1 << "     "
         << fixed << setprecision(1) << AverageOfScore2 << "     "
         << fixed << setprecision(1) << AverageOfScore3 << endl; // 这里限定输出的位数为固定的1位，因为总共10个学生，整数除以10用一位小数是足够的

    int MinOfScore1 = Score[0][0];
    int MaxOfScore1 = Score[0][0];
    int MinOfScore2 = Score[0][1];
    int MaxOfScore2 = Score[0][1];
    int MinOfScore3 = Score[0][2];
    int MaxOfScore3 = Score[0][2];
    for(int i = 0; i < 10; i++){
        if(Score[i][0] < MinOfScore1) MinOfScore1 = Score[i][0];
        if(Score[i][0] > MaxOfScore1) MaxOfScore1 = Score[i][0];
        if(Score[i][1] < MinOfScore2) MinOfScore2 = Score[i][1];
        if(Score[i][1] > MaxOfScore2) MaxOfScore2 = Score[i][1];
        if(Score[i][2] < MinOfScore3) MinOfScore3 = Score[i][2];
        if(Score[i][2] > MaxOfScore3) MaxOfScore3 = Score[i][2];
    }
    cout << "        min     " << MinOfScore1 - 48 << "       " << MinOfScore2 - 48 << "       " << MinOfScore3 - 48 << endl;
    cout << "        max     " << MaxOfScore1 - 48 << "       " << MaxOfScore2 - 48 << "       " << MaxOfScore3 - 48 << endl;

    return 0;
}
