![题目要求](img/HW1.png)

这里是我的第一次作业，作业题面如上图，本次作业支持终端输入和文件输入两种方式，具体要求如下：

1. 输入方式：
   + 直接在终端输入
   + 将你的输入写入该目录下的文件：input.txt
2. 输入格式：
   每个学生的信息独占一行，每一行中首先输入学生的姓名，接着输入学生三门课程的成绩，其间以**逗号**隔开
3. 运行程序：（这里默认你使用的是g++编译器）
   如果你要在终端输入：
   + Windows下：
     ```bash
     g++ -std=c++11 HW1.cpp
     .\a.exe
     ```
   + MacOS/Linux下：
     ```bash
     g++ -std=c++11 HW1.cpp
     ./a.out
     ```
   如果你要从文件中读取输入：
   + Windows下：
     ```bash
     g++ -std=c++11 HW1.cpp
     Get-Content input.txt | .\a.exe
     ```
   + MacOS/Linux下：
     ```bash
     g++ -std=c++11 HW1.cpp
     ./a.out < input.txt
     ```
4. 文件介绍：
   + HW1.cpp：程序源代码
   + input.txt：测试用例文件，每行输入一个学生的信息，要求如上
