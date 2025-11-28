/*****************************************************************************
 * | @file    : 05_STL_string_find.cpp
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-01
 * ---------------------------------------
 * | @brief   : main template
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <iostream>  // 包含输入和输出操作
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件
#include <exception> // 引入 exception 头文件

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << " -------------------- begain -------------------- " << endl;

    // 查找方式1: find 函数

    // 1.查找字符串
    // int find(const string &str,int pos=0) const;
    //查找str第一次出现的位置，从第pos位置开始查找
    string str11("world,hello,world!");
    string str1_1("world");
    int find11=str11.find(str1_1);
    cout << "find11:" << find11 << endl;

    int find12=str11.find(str1_1,1);
    cout << "find12:" << find12 << endl;








    
    cout << " -------------------- end -------------------- " << endl;

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
