/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-10-16
 * ---------------------------------------
 * | @brief   : main template
 ******************************************************************************/
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream> // 包含输入和输出操作
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << " -------------------- begain -------------------- " << endl;

    // 赋值方式一: 运算符 = 重载

    // 1. char*类型字符串 赋值给当前的字符串
    // string &operator=(const char *s)

    // 1.1 通过变量赋值
    const char *s1 = "Hello, world!";
    string s11;
    s11 = s1;
    cout << "s11:" << s11 << endl;

    // 1.2直接赋值
    string s12;
    s12 = "123456789";
    cout << "s12:" << s12 << endl;

    // 2. 把字符串s赋给当前的字符串
    // string &operator=(const string &s);
    string s21;
    s21 = s11;
    cout << "s21:" << s21 << endl;

    // 3. 字符赋值给当前的字符串
    // string &operator=(char c);

    string s31;
    s31 = 'A';
    cout << "s31:" << s31 << endl;

    cout << " ---------------------------------------- " << endl;

    // 赋值方式2: assign 函数
    // string &assign(const char *s);                     // 把字符串s赋给当前的字符串
    // string &assign(const char *s, int n);              // 把字符串s的前n个字符赋给当前的字符串
    // string &assign(const string &s);                   // 把字符串s赋给当前字符串
    // string &assign(int n, char c);                     // 用n个字符c赋给当前字符串
    // string &assign(const string &s, int start, int n); // 将s从start开始n个字符赋值给字符串








    cout << " -------------------- end -------------------- " << endl;

    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
