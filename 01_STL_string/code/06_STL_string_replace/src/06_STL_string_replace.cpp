/*****************************************************************************
 * | @file    : 06_STL_string_replace.cpp
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

    // replace替换方法，从pos开始到n的位置的元素替换为str
    // string &replace(int pos,int n,const string &str);
    string str("http://www.hhh.key.123.key.hhh.999.key.com.cn");
    string str11("###");
    while (1) {
        int ret1 = str.find("hhh");
        if (ret1 == -1) {
            break;
        }
        str.replace(ret1, 3, str11);
        cout << "str:" << str << endl;
    }

    cout << " ---------------------------------------- " << endl;

    // string &replace(int pos,int n,const char *s);
    const char *str21 = "***";
    while (1) {
        int ret2 = str.find("key");
        if (ret2 == -1) {
            break;
        }
        str.replace(ret2, 3, str21);
        cout << "str:" << str << endl;
    }

    cout << " -------------------- end -------------------- " << endl;

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
