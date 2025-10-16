/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-17
 * ---------------------------------------
 * | @brief   : 赋值 list 测试
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

void set_value_test();

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

    set_value_test();

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void set_value_test()
{
    cout << "set_value_test: " << endl;

    list<int> first = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "first: ";
    print_list(first);

    // 操作符 = 赋值
    list<int> second;
    second = first;
    cout << "second: ";
    print_list(second);

    // assign 函数赋值，使用迭代器
    list<int> third(10, 1);
    cout << "third1: ";
    print_list(third);

    third.assign(first.begin(), first.end()); // 把first赋给third，其余值删除,左闭右开
    cout << "third2: ";
    print_list(third);

    // assign 函数赋值，使用数值
    list<int> forth(10, 1);
    cout << "forth1: ";
    print_list(forth);

    forth.assign(5, 9); // 把5个9赋给 forth，其余值删除
    cout << "forth2: ";
    print_list(forth);

    // assign 函数赋值，使用数组
    list<int> fifth(10, 1);
    cout << "fifth1: ";
    print_list(fifth);

    int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fifth.assign(myints, myints + 5); // 把 myints 前五个值赋给fifth，fifth左闭右开
    cout << "fifth2: ";
    print_list(fifth);
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
