/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-16
 * ---------------------------------------
 * | @brief   : unordered_map 删除元素测试
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

void erase_test();

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

    erase_test();
    
    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void erase_test()
{
    cout << "erase_test: " << endl;
    unordered_map<int, string> mp; // 构造一个空容器
    mp = {{1, "apple"}, {2, "banana"}, {3, "orange"}, {4, "pear"}};

    mp.erase(2); // 1：根据 key 删除
    print_unordered_map(mp);

    unordered_map<int, string>::iterator it;
    it = mp.begin();
    it++;
    cout << it->first << ":" << it->second << " " << endl;
    mp.erase(it); // 2：根据迭代器位置删除
    print_unordered_map(mp);
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
