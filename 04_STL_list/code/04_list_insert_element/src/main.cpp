/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-17
 * ---------------------------------------
 * | @brief   : 插入 list 测试
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <iostream> // 包含输入和输出操作
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

void insert_element_test();

// list 的遍历
void print_list(list<int> &li)
{
    for (auto i : li)
    {
        std::cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    insert_element_test();

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void insert_element_test()
{
    cout << "get_element_test: " << endl;

    list<int> l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    l_test.push_back(10); // 尾部插入10
    cout << "在尾部插入10: " << endl;
    print_list(l_test);

    l_test.push_front(20); // 首部插入20
    cout << "在首部插入20: " << endl;
    print_list(l_test);

    l_test.insert(l_test.begin(), 30); // 在首位插入10
    cout << "在首部插入30: " << endl;
    print_list(l_test);

    l_test.insert(l_test.begin(), 2, 40); // 在首位插入2个40
    cout << "在首部插入2个40: " << endl;
    print_list(l_test);

    list<int>::iterator it;
    it = l_test.begin();
    // it = it + 3; // 报错 没有加法
    it++;
    it++;
    it++;
    l_test.insert(it, 50); // 在第3位后面插入30
    cout << "在第3位后面插入30: " << endl;
    print_list(l_test);

    it = l_test.end();
    // it = it - 3; //  报错 没有减法
    it--;
    it--;
    it--;

    l_test.insert(it, 2, 60); // 在倒数第3位前面插入2个60
    cout << "在倒数第3位前面插入2个60: " << endl;
    print_list(l_test);
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
