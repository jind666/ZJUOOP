#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    // 测试默认构造函数
    Vector<int> v1;
    cout << "v1 size: " << v1.size() << ". Is empty?: " << v1.empty() << "." << endl;
    cout << endl;

    // 测试带size参数的构造函数以及测试push_back函数
    Vector<int> v2(10);
    cout << "v2 size: " << v2.size() << ". Is empty?: " << v2.empty() << "." << endl;
    for(int i = 0; i < 10; i++){
        v2.push_back(i);
    }
    cout << "v2 size: " << v2.size() << ". Is empty?: " << v2.empty() << "." << endl;
    cout << "The 2nd and 7th elements of v2 are: " << v2.operator[](2) << " and " << v2.operator[](7) << "." << endl;
    int x = 10;
    v2.push_back(x);
    cout << "v2 size: " << v2.size() << ". Is empty?: " << v2.empty() << "." << endl;
    cout << "The 10th element of v2 is: " << v2.operator[](10) << "." << endl;
    cout << endl;

    // 测试拷贝构造函数
    Vector<int> v3(v2);
    cout << "v3 size: " << v3.size() << ".Is empty?: " << v3.empty() << "." << endl;
    cout << "The 3nd and 8th elements of v3 are: " << v3.operator[](3) << " and " << v3.operator[](8) << "." << endl;
    // cout << "If the 12th element of v3 is accessed?" << endl;
    // v3.at(12);
    cout << endl;

    // 测试clear函数
    v2.clear();
    cout << "v2 size: " << v2.size() << ".Is empty?: " << v2.empty() << "." << endl;
    cout << endl;

    // 测试at函数
    cout << "If the 12th element of v3 is accessed?" << endl;
    v3.at(12);

    return 0;
}
