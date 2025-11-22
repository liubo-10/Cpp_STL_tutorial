/*****************************************************************************
 * | @file    : 04_STL_string_splice.cpp
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-01
 * ---------------------------------------
 * | @brief   : main template
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <iostream> // 包含输入和输出操作
#include <unistd.h> // pause()头文件
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << " -------------------- begain -------------------- " << endl;

    // 拼接方式1: 重载 += 运算符

    // 1.参数是 string 类型
    // string &operator+=(const string &str);
    string str11("hello,");
    string str1_1("world!");
    str11 += str1_1; //两个对象相加赋值给str111对象
    cout << "str11:" << str11 << endl;

    // 2 参数是 const char * 类型
    // string &operator +=(const char *str);//c风格

    // 2.1 通过定义变量拼接
    const char *str2_1 = "67890";
    string str21("12345");
    str21 += str2_1;
    cout << "str21:" << str21 << endl;

    // 2.2 字符串常量直接拼接
    string str22("abcde");
    str22 += "fghij";
    cout << "str22:" << str22 << endl;

    // 3.参数是 const char 类型
    // string &operator +=(const char c);
    string str31("abcde");
    str31 += "f";
    const char c3_1 = 'g';
    str31 += c3_1;
    cout << "str31:" << str31 << endl;

    cout << " ---------------------------------------- " << endl;

    // 拼接方式2: append 函数

    // 4.参数是 string 类型

    // 4.1 把字符串s拼接在当前字符串后面
    // string &append(const string &s);
    string str41("hello,");
    string str4_1("world!");
    str41.append(str4_1);
    cout << "str41:" << str41 << endl;

    // 4.2 将s从 start 开始n个字符赋值给字符串
    // string &append(const string &s, int start, int n);
    string str4_2("1234567890");

    string str420("hello");
    str420.append(str4_2, 0, 3);
    cout << "str420:" << str420 << endl;

    string str421("hello");
    str421.append(str4_2, 1, 3);
    cout << "str421:" << str421 << endl;

    string str422("hello");
    str422.append(str4_2, 2, 3);
    cout << "str422:" << str422 << endl;

    // 5.参数是 const char *s 类型
    // string &append(const char *s);//append追加方法

    // 5.1 通过定义变量拼接
    const char *str5_1 = "12345";
    string str51("god");
    str51.append(str5_1);
    cout << "str51:" << str51 << endl;

    // 5.2 字符串常量直接拼接
    string str52("god");
    str52.append("67890");
    cout << "str52:" << str52 << endl;

    // 5.3 把字符串 const char *s 的前n个字符追加到当前的字符串之后
    // string &append(const char *s, int n);
    const char *str5_3 = "1234567890";

    string str530("study");
    str530.append(str5_3, 0); //前0个追加给str6对象
    cout << "str530:" << str530 << endl;

    string str531("study");
    str531.append(str5_3, 2); //前2个追加给str6对象
    cout << "str531:" << str531 << endl;

    string str532("study");
    str532.append(str5_3, 4); //前4个追加给str6对象
    cout << "str532:" << str532 << endl;

    // 6.参数是 const char c 类型
    // string &append(int n,char c);

    string str6("AAA");
    str6.append(3, 'B');
    cout << "str6:" << str6 << endl;

    cout << " -------------------- end -------------------- " << endl;
    // cin.get();
    // getchar();
    // pause();

    // 20
    // --------------------

    // 40
    // ----------------------------------------

    // 80
    // --------------------------------------------------------------------------------

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
