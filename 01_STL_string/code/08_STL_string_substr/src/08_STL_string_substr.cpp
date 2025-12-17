/*****************************************************************************
 * | @file    : 08_STL_string_substr.cpp
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

    // 1. 返回由pos开始的到n组成的字符串
    // string substr(int pos=0,int n=npos) const;
    string str1_1("hello,world!");
    string str11 = str1_1.substr(6, 5);
    cout << "str11:" << str11 << endl;

    string str1_2{"http://www.hhh.key.123.key.hhh.999.key.com.cn"};

    int front = 0;
    while (1) {
        int end = str1_2.find(".", front); //find方法如果查找到了，返回下标位置，查找不到返回-1
        if (end == -1) {
            cout << str1_2.substr(front, str1_2.size() - front) << endl;
            break;
        }
        cout << str1_2.substr(front, end - front) << endl;
        front = end + 1;
    }

    // 2. 在pos位置前插入 string &str
    // string &insert(int pos,const string &str);
    string str21("helloworld!");
    str21.insert(5, str1_1);
    cout << "str21:" << str21 << endl;

    // 3. 在pos位置前插入 const char *s
    // string &insert(int pos,const char *s);
    string str31("helloworld!");
    str31.insert(5, ",,,");
    cout << "str31:" << str31 << endl;

    // 4. 指定的位置pos前插入n个c
    // string &insert(int pos,int n,char c);
    string str41("helloworld!");
    str41.insert(5, 10, ',');
    cout << "str41:" << str41 << endl;

    // 5. 删除从pos开始的n个元素
    // string &erase(int pos,int n=npos);

    string str51("hello,,,,,world!");
    str51.erase(5, 5); //删除3到4位置的元素
    cout << "str51:" << str51 << endl;

    cout << " -------------------- end -------------------- " << endl;

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
