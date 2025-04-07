/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-07
 * ---------------------------------------
 * | @brief   : vector 迭代起失效测试
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
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = v_test.begin();

    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "it = " << *it << endl;
    cout << "addr of iter: " << &*it << endl
         << endl;

    v_test.push_back(0); // 可能导致容量不足，触发内存重新分配
    cout << "push_back 0: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "it = " << *it << endl;
    cout << "addr of iter: " << &*it << endl
         << endl;
         
    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
