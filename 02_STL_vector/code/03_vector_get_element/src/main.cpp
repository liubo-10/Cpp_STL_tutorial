/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-04
 * ---------------------------------------
 * | @brief   : vector 获取元素测试
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

int main()
{
    printf("--------------------begain-------------------\n");
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> v_test(a, a + 10);

    cout << "调用at，打印 v_test: ";
    for (int i = 0; i < v_test.size(); i++)
    {
        cout << v_test.at(i) << " ";
    }
    cout << endl;

    cout << "调用[]，打印 v_test: ";
    for (int i = 0; i < v_test.size(); ++i)
    {
        cout << v_test[i] << " "; // 调用2
    }
    cout << endl;

    cout << "容器中第一个元素是：" << v_test.front() << endl;
    cout << "容器中最后一个元素是：" << v_test.back() << endl;

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
