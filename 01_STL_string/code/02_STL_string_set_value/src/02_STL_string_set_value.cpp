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
    string str11;
    str11 = s1;
    cout << "str11:" << str11 << endl;

    // 1.2 字符串常量直接赋值
    string str12;
    str12 = "123456789";
    cout << "str12:" << str12 << endl;

    // 2. 把字符串s赋给当前的字符串
    // string &operator=(const string &s);
    string str21;
    str21 = str11;
    cout << "str21:" << str21 << endl;

    // 3. 字符赋值给当前的字符串
    // string &operator=(char c);
    string str31;
    str31 = 'A';
    cout << "str31:" << str31 << endl;

    cout << " ---------------------------------------- " << endl;

    // 赋值方式2: assign 函数

    // 4. assign 参数为 char*类型字符串
    // string &assign(const char *s);

    // 4.1 参数为字符串变量
    string str41;
    const char *s4 = "123456789";
    str41.assign(s4);
    cout << "str41:" << str41 << endl;

    // 4.2 参数为字符串常量
    string str42;
    str42.assign("Hello, world!");
    cout << "str42:" << str42 << endl;

    // 4.3 把字符串s的前n个字符赋给当前的字符串
    // string &assign(const char *s, int n);
    string str43_1;
    str43_1.assign(s4, 1);
    cout << "str43_1:" << str43_1 << endl;

    string str43_2;
    str43_2.assign(s4, 2);
    cout << "str43_2:" << str43_2 << endl;

    string str43_3;
    str43_3.assign(s4, 3);
    cout << "str43_3:" << str43_3 << endl;

    // 5. assign 参数为 string 类型字符串
    // string &assign(const string &s);

    // 5.1 把string字符串s赋给当前字符串
    string str51;
    str51.assign(str42);
    cout << "str51:" << str51 << endl;

    // 5.2 将string字符串s从start开始n个字符赋值给字符串
    // string &assign(const string &s, int start, int n);
    string str52_1;
    str52_1.assign(str41, 0, 3);
    cout << "str52_1:" << str52_1 << endl;

    string str52_2;
    str52_2.assign(str41, 1, 3);
    cout << "str52_2:" << str52_2 << endl;

    string str52_3;
    str52_3.assign(str41, 2, 3);
    cout << "str52_3:" << str52_3 << endl;

    // 6. assign 参数为 n个字符c
    // string &assign(int n, char c);

    string str6;
    str6.assign(5, 'Z');
    cout << "str6 :" << str6 << endl;

    cout << " -------------------- end -------------------- " << endl;

    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
