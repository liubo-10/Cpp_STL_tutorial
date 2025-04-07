/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-03
 * ---------------------------------------
 * | @brief   : 赋值 vector 测试
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <iostream>  // 包含输入和输出操作
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// vector的遍历
void printVector(vector<int> &v)
{
    for (auto n : v)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    vector<int> first = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "first: ";
    printVector(first);

    //操作符 = 赋值
    vector<int> second;
    second = first;
    cout << "second: ";
    printVector(second);

    // assign 函数赋值，使用迭代器
    vector<int> third(10, 1);
    cout << "third1: ";
    printVector(third);

    third.assign(first.begin(), first.end() - 5); // 把first除后五个值之外值赋给third，其余值删除
    cout << "third2: ";
    printVector(third);

    // assign 函数赋值，使用数值
    vector<int> forth(10, 1);
    cout << "forth1: ";
    printVector(forth);

    forth.assign(5, 9); // 把5个9赋给 forth，其余值删除
    cout << "forth2: ";
    printVector(forth);

    // assign 函数赋值，使用数组
    vector<int> fifth(10, 1);
    cout << "fifth1: ";
    printVector(fifth);

    int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fifth.assign(myints, myints + 4);
    cout << "fifth2: ";
    printVector(fifth);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
