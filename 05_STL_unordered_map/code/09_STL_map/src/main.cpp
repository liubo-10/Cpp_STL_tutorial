/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2024-09-01
 * ---------------------------------------
 * | @brief   : main template
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <iostream>  // 包含输入和输出操作
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    printf("--------------------begain-------------------\n");
    /**
     * write your code here 
     **/

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/






 /***********************************************************
 * @file name: Hello_World.cpp
 * @author: liubo
 * @date: 2024.04.19
 * @describe:
 * 
 * 
 **********************************************************/
#include<iostream>
#include<string>
#include<utility>
#include<unordered_map>

using std::cin;
using std::cout;
using std::endl;

using std::pair;
using std::make_pair;
using std::string;
using std::unordered_map;

int main()
{
    cout << "----------------begain------------------" << endl;

    unordered_map<int, string> mp;

    cout << "----------------插入------------------" << endl;
    //1：借助pair构造对象
    pair<int, string> kv(1, "one");
    mp.insert(kv);

    //2：借助pair构造匿名对象插入
    mp.insert(pair<int, string>(2, "two"));

    //3：调用make_pair函数模板插入
    mp.insert(make_pair(3, "three"));

    //4：使用[]运算符重载函数进行插入
    mp[4] = "four";

    //5：使用{}
    mp.insert({ 5, "five" });

    cout << "----------------遍历------------------" << endl;
    //1：迭代器遍历
    unordered_map<int, string>::iterator it = mp.begin();
    cout << "iterator:";
    while (it != mp.end())
    {
        cout << it->first << ":" << it->second << " ";
        it++;
    }
    cout << endl;

    //2：范围for
    cout << "for:";
    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;

    cout << "----------------删除------------------" << endl;
    //1：根据key删除
    mp.erase(4);

    //2：根据迭代器位置删除
    unordered_map<int, string>::iterator pos = mp.find(2);
    if (pos != mp.end())
    {
        mp.erase(pos);
    }

    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;

    cout << "----------------修改------------------" << endl;
    //1：通过迭代器位置修改
    pos = mp.find(5);
    if (pos != mp.end())
    {
        pos->second = "Ⅴ";
    }

    //2：通过[]修改
    mp[3] = "Ⅲ";

    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;

    cout << "----------------交换------------------" << endl;
    unordered_map<int, string> tmp{{7, "日"}, {5, "月"}, {2003, "年"}};
    mp.swap(tmp);
    for (auto e : mp)
    {
        cout << e.first << e.second << " ";
    }
    cout << endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
----------------插入------------------
----------------遍历------------------
iterator:5:five 4:four 3:three 2:two 1:one 
for:5:five 4:four 3:three 2:two 1:one 
----------------删除------------------
5:five 3:three 1:one 
----------------修改------------------
5:Ⅴ 3:Ⅲ 1:one 
----------------交换------------------
2003年 5月 7日 
----------------end------------------
 */
