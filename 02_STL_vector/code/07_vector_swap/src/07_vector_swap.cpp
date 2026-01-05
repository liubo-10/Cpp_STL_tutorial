/*****************************************************************************
 * | @file    : 07_vector_swap.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |    V1     2025-04-07
 * |    V2     2025-12-30
 * ---------------------------------------
 * | @brief   : vector 交换测试
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <iostream>  // 包含输入和输出操作
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// vector的遍历
void print_vector(vector<int> &v)
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
    vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vector_12{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "交换前：" << endl;
    print_vector(vector_11);
    print_vector(vector_12);

    //调用互换函数
    vector_11.swap(vector_12);

    cout << "交换后：" << endl;
    print_vector(vector_11);
    print_vector(vector_12);

    printf("--------------------end----------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
