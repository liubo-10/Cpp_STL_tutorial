/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-16
 * ---------------------------------------
 * | @brief   : unordered_map 查找元素测试
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
using std::unordered_map;

void find_test();

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

    find_test();

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void find_test()
{
    cout << "find_test: " << endl;

    unordered_map<int, string> mp; // 构造一个空容器
    mp = {{1, "apple"}, {2, "banana"}, {3, "orange"}, {4, "pear"}};

    auto pos = mp.find(2);
    auto num = mp.count(2);
    
    if (pos != mp.end())
    {
        cout << pos->first << ":" << pos->second << " " << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    cout << "num: " << num << endl;

    pos = mp.find(5);
    num = mp.count(5);

    if (pos != mp.end())
    {
        cout << pos->first << ":" << pos->second << " " << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    cout << "num: " << num << endl;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
