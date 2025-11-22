/*****************************************************************************
 * | @file    : 02_STL_string_set_value.c
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

    // 赋值方式1: 运算符 = 重载

    // 1. char*类型字符串 赋值给当前的字符串
    // string &operator=(const char *s)

    // 1.1 通过定义变量赋值
    const char *s1 = "Hello, world!";
    string s11;
    s11 = s1;
    cout << "s11:" << s11 << endl;

    // 1.2 字符串常量直接赋值
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

    // 4. assign 参数为 char*类型字符串
    // string &assign(const char *s);

    // 4.1 参数为字符串变量
    string s41;
    const char *s4 = "123456789";
    s41.assign(s4);
    cout << "s41:" << s41 << endl;

    // 4.2 参数为字符串常量
    string s42;
    s42.assign("Hello, world!");
    cout << "s42:" << s42 << endl;

    // 4.3 把字符串s的前n个字符赋给当前的字符串
    // string &assign(const char *s, int n);
    string s431;
    s431.assign(s4, 1);
    cout << "s431:" << s431 << endl;

    string s432;
    s432.assign(s4, 2);
    cout << "s432:" << s432 << endl;

    string s433;
    s433.assign(s4, 3);
    cout << "s433:" << s433 << endl;

    // 5. assign 参数为 string 类型字符串
    // string &assign(const string &s);

    // 5.1 把字符串s赋给当前字符串
    string s51;
    s51.assign(s42);
    cout << "s51:" << s51 << endl;

    // 5.2 将s从start开始n个字符赋值给字符串
    // string &assign(const string &s, int start, int n);
    string s521;
    s521.assign(s41, 0, 3);
    cout << "s521:" << s521 << endl;

    string s522;
    s522.assign(s41, 1, 3);
    cout << "s522:" << s522 << endl;

    string s523;
    s523.assign(s41, 2, 3);
    cout << "s523:" << s523 << endl;

    // 6. assign 参数为 n个字符c
    // string &assign(int n, char c);

    string s6;
    s6.assign(5, 'Z');
    cout << "s6:" << s6 << endl;

    cout << " -------------------- end -------------------- " << endl;

    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
