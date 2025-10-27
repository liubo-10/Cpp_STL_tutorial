/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-10-15
 * ---------------------------------------
 * | @brief   : main template
 ******************************************************************************/
#include <iostream> // 包含输入和输出操作
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件
#include <cstdlib>

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << " -------------------- begain -------------------- " << endl;

    // 1.无参默认构造 string
    // 创建一个空的字符串
    // string();
    string s11;
    s11 = "123456789";
    cout << "s11 :" << s11 << endl;

    cout << " ---------------------------------------- " << endl;

    // 2.拷贝构造 string
    // 2.1使用一个string对象初始化另一个string对象
    // string(const string& str);
    string s21(s11);
    cout << "s21 :" << s21 << endl;

    // 2.2选取 string 字符的拷贝构造
    // 将一个字符串对象的第pos位置之后的len个字符初始化给对应的字符串对象
    // string(const string& str, size_t pos, size_t len = npos);
    string s22_1(s11, 0, 3);
    cout << "s22_1:" << s22_1 << endl;

    string s22_2(s11, 1, 3);
    cout << "s22_2:" << s22_2 << endl;

    string s22_3(s11, 2, 3);
    cout << "s22_3:" << s22_3 << endl;

    cout << " ---------------------------------------- " << endl;

    // 3.使用c类型字符串构造 string
    // 3.1使用长变量构造
    // string(const char* s);
    const char *s3 = "Hello, world!";
    string s31(s3);
    cout << "s31:" << s31 << endl;

    // 3.2通过字符串常量构造
    // string(const char* s);
    string s32("hello, world");
    cout << "s32:" << s32 << endl;

    // 3.3通过字符串前n个字符构造
    // string(const char* s, size_t n);
    string s33("123456789", 6);
    cout << "s33:" << s33 << endl;

    cout << " ---------------------------------------- " << endl;

    // 4.使用n个字符c构造 string
    // string(size_t n, char c);
    string s41_1(10, 'A');
    cout << "s41_1:" << s41_1 << endl;

    string s41_2(10, 'Z');
    cout << "s41_2:" << s41_2 << endl;

    cout << " -------------------- end -------------------- " << endl;

    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
