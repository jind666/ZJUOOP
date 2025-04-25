![题目要求](/img/HW5.png)

这里是我的第五次作业。作业要求如上图所示，下面再来展开说一些细节。

1. 作业要求：
   实现一个分数的类，并按题目要求实现一些函数

2. 各个函数介绍及原型：
   + Default ctor  
     默认构造函数，构造一个分数为0/1的分数对象  
     Fraction();  
   + Ctor takes two integers as parameters  
     构造函数，传入两个整数作为分子和分母，构造一个分数对象  
     Fraction(int numerator, int denominator);  
   + Copy ctor  
     拷贝构造函数，拷贝一个分数对象  
     Fraction(const Fraction& other);  
   + Arithmetical operators: `+ - * /`  
     四则运算符重载，实现分数的加减乘除运算  
     void add(const Fraction& other);  
     void sub(const Fraction& other);  
     void mul(const Fraction& other);  
     void div(const Fraction& other);  
   + Relational operators: `< <= == != >= >`  
     关系运算符重载，实现分数的大小比较  
     bool operator<(const Fraction& other) const;  
     bool operator<=(const Fraction& other) const;  
     bool operator==(const Fraction& other) const;  
     bool operator!=(const Fraction& other) const;  
     bool operator>=(const Fraction& other) const;  
     bool operator>(const Fraction& other) const;  
   + Typecast to double  
     类型转换函数，将分数转换为double类型  
     double ToDouble() const;  
   + To string  
     转换为字符串函数，将分数转换为字符串形式  
     string ToString() const;  
   + Inserter and extractor for streams  
     输入输出流插入和提取函数，实现分数的输入输出  
     void read();  
     void print() const;  
   + Conversion from a finite decimal string like: `1.414`  
     字符串转换函数，将字符串形式的小数转换为分数对象  
     void conversion(string s)；  

3. 文件介绍：  
   + Fraction.h：头文件，包含分数类定义  
   + test1.cpp：测试文件，主要测试构造函数  
   + test2.cpp：测试文件，主要测试分母为0的情况  
   + test3.cpp：测试文件，主要测试四则运算符  
   + test4.cpp：测试文件，主要测试关系运算符  
   + test5.cpp：测试文件，主要测试类型转换  
   + test6.cpp：测试文件，主要测试输入输出和字符串转换  
   + extra_test.cpp：空白文件，用于评测时写入额外的测试程序  

4. 编译运行说明：  
   因为我的源文件中使用了不少C++11的标准，所以命令行编译请使用：    
   `g++ -std=c++11 'Personal Diary.cpp'`     
   不加 `-std=c++11` 选项会出现警告。    
   你也可以用其他方式编译，但请不要忘记在C++11标准下。   