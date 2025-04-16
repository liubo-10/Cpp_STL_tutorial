/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-16
 * ---------------------------------------
 * | @brief   : unordered_map 访问元素测试
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件
#include <iostream> // 包含输入和输出操作
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::unordered_map;

void get_element_test();

// unordered_map 的遍历
void print_unordered_map(unordered_map<int, string> &mp)
{
    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    get_element_test();
    
    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void get_element_test()
{
    cout << "get_element_test: " << endl;

    unordered_map<int, string> mp;
    mp = {{1, "apple"}, {2, "banana"}, {3, "orange"}, {4, "pear"}};

    cout << 1 << ":" << mp[1] << " " << endl;
    cout << 2 << ":" << mp[2] << " " << endl;

    unordered_map<int, string>::iterator it;

    it = mp.begin();
    cout << it->first << ":" << it->second << " " << endl;
    it++;
    cout << it->first << ":" << it->second << " " << endl;
    it++;
    cout << it->first << ":" << it->second << " " << endl;

    // it = it - 1; // 报错没有减法
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
