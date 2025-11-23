/*****************************************************************************
 * | @file    : 03_STL_string_set_element.cpp
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

    // 1. 重载[]运算符，n是下标
    // char &operator[](int n);
    string str1("hello, world");
    cout << "str1:" << str1 << endl;

    str1[0] = 'H'; //将字符串第1个元素改为H
    cout << "str1:" << str1 << endl;

    str1[7] = 'W'; //将字符串第8个元素改为H
    cout << "str1:" << str1 << endl;

    cout << " ---------------------------------------- " << endl;

    // 2. 通过at方法获取下标为n的元素
    // char &at(int n);
    string str2("hello, world");
    cout << "str2:" << str2 << endl;

    str2.at(0) = 'H'; //将字符串第1个元素改为H
    cout << "str2:" << str2 << endl;

    str2.at(7) = 'W'; //将字符串第8个元素改为H
    cout << "str2:" << str2 << endl;

    cout << " ---------------------------------------- " << endl;

    // 3. 字符串的取值和修改操作之at方法和重载operator[]方法的区别

    // 使用重载operator[]运算符方法，下标越界不会抛出异常
    try {
        str1[100] = 'H';                  // 数组下标访问越界，使用operator[]方法不会抛出异常
    } catch (std::exception &str) {       // 接收来自try的异常
        cout << "string [] test" << endl; // 不会打印
        cout << str.what() << endl;       // 不会打印
    }

    cout << " ---------------------------------------- " << endl;

    // 使用at方法，下标越界会抛出异常
    try {
        str2.at(100) = 'H';                 // 抛出异常，程序不会终止
    } catch (std::exception &str) {         // 接收来自try的异常
        cout << "string at() test" << endl; // 会打印
        cout << str.what() << endl;         // 会打印
    }

    cout << " -------------------- end -------------------- " << endl;

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
