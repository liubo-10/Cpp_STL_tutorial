/*****************************************************************************
 * | @file    : 07_STL_string_compare.cpp
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-12-15
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

    // 1. 字符比较,根据ASCII码,逐字符表进行比较
    // >返回1，<返回-1，==返回0;
    // int compare(const string &s) const;

    string str11("hello,world!");
    string str12("helllo,World!");
    if (str11.compare(str12) == 0) {
        cout << "str11 等于 str12" << endl;
    }
    else if (str11.compare(str12) > 0) {
        cout << "str11 大于 str12" << endl;
    }
    else {
        cout << "str11 小于 str12" << endl;
    }

    // int compare(const char *s) const;

    if (str11.compare("hello,zorld!") == 0) {
        cout << "str11 等于 \"hello,zorld!\"" << endl;
    }
    else if (str11.compare("hello,zorld!") > 0) {
        cout << "str11 大于 \"hello,zorld!\" " << endl;
    }
    else {
        cout << "str11 小于 \"hello,zorld!\"" << endl;
    }

    cout << " -------------------- end -------------------- " << endl;

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
