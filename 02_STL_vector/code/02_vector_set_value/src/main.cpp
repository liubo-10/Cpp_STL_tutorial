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
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> first(a, a + 10);
    
    cout << "first: ";
    printVector(first);

    vector<int> second;
    second = first;

    cout << "second: ";
    printVector(second);

    vector<int> third(10, 1);

    cout << "third: ";
    printVector(third);

    third.assign(first.begin(), first.end() - 5);

    cout << "third: ";
    printVector(third);

    vector<int> forth(10, 1);

    cout << "forth: ";
    printVector(forth);

    forth.assign(5, 9);

    cout << "forth: ";
    printVector(forth);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
