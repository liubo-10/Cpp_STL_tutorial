/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-10-15
 * ---------------------------------------
 * | @brief   : main template
 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "--------------------begain-------------------" << endl;

    // 1.无参默认构造
    // 创建一个空的字符串
    // string();
    string s1;
    s1 = "123456789";
    cout << "s1:" << s1 << endl;

    // 2.拷贝构造
    // 使用一个string对象初始化另一个string对象
    // string(const string& str);
    string s2(s1);
    cout << "s2:" << s2 << endl;

    // 3.使用c字符串初始化
    // string(const char* s);
    const char* s = "Hello, world!";
    string      s3(s);
    cout << "s3:" << s3 << endl;

    // 4、通过字符串常量初始化
    // string(const char* s);
    string s4("hello world");
    cout << "s4:" << s4 << endl;

    // 5.使用n个字符c初始化
    // string(size_t n, char c);
    string s5(10, 'x');
    cout << "s5:" << s5 << endl;

    // 6.通过字符串前n个字符初始化
    // string(const char* s, size_t n);
    string s6("123456789", 6);
    cout << "s6:" << s6 << endl;

    // 7.通过string子串初始化
    // 将一个字符串对象的第pos位置之后的len个字符初始化给对应的字符串对象
    // string(const string& str, size_t pos, size_t len = npos);
    string s7(s1, 0, 3);
    cout << "s7:" << s7 << endl;

    string s8(s1, 1, 3);
    cout << "s8:" << s8 << endl;

    string s9(s1, 1, 3);
    cout << "s9:" << s9 << endl;

    cout << "--------------------end----------------------" << endl;

    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
