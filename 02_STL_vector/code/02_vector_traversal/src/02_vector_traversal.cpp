/*****************************************************************************
 * | @file    : 02_vector_traversal.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-12-20
 * ---------------------------------------
 * | @brief   : vector 遍历
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件
#include <iostream> // 包含输入和输出操作

#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// vector的遍历
void print_vector_1(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " "; // 利用迭代器打印 v
    }
    cout << endl;
}

void print_vector_2(vector<int> &v)
{
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    // 1.构造一个空容器，没有元素。
    // vector<T> vectorname;
    vector<int> vector_1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "vector_1: ";
    print_vector_1(vector_1);
    cout << "vector_1: ";
    print_vector_2(vector_1);

    printf("--------------------end----------------------\n");

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/

/* 
--------------------begain-------------------
vector_1: 0 1 2 3 4 5 6 7 8 9 
vector_1: 0 1 2 3 4 5 6 7 8 9 
--------------------end----------------------
*/