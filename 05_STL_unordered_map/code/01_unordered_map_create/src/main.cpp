/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-12
 * ---------------------------------------
 * | @brief   : 创建 vector 测试
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

// unordered_map 的遍历
// void print_unordered_map(unordered_map<int, string> &mp)
// {
//     for (unordered_map<int, string>::iterator it = mp.begin(); it != mp.end(); ++it)
//     {
//         cout << it->first << ":" << it->second << " ";
//     }
//     cout << endl;
// }

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

    unordered_map<int, string> first; // 构造一个空容器

    first = {{1, "apple"}, {2, "banana"}, {3, "orange"}, {4, "pear"}};

    unordered_map<int, string> second(first);                     // 拷贝构造一个容器
    unordered_map<int, string> third(first.begin(), first.end()); // 使用迭代器区间构造一个容器

    cout << "first: " << endl;
    print_unordered_map(first);

    cout << "second: " << endl;
    print_unordered_map(second);

    cout << "third: " << endl;
    print_unordered_map(third);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
