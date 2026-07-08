/*****************************************************************************
 * | @file    : 12_vector_swap_size.cpp
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |    V1     2026-01-15
 * ---------------------------------------
 * | @brief   : vector 数据量和容量测试
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <iostream> // 包含输入和输出操作
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// vector的遍历
void print_vector(vector<int> &v)
{
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "vector_11: " << endl;
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    vector_11.reserve(30); // 使得capacity=30，里面的元素不会改变
    cout << "reserve 30: ";
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    vector<int> vector_12;
    vector_12.swap(vector_11);

    cout << "swap vector_12: ";
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    vector<int> vector_13{9,8,7,6};
    vector_11.swap(vector_13);

    cout << "swap vector_11: ";
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    printf("--------------------end----------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/

 //result:
/* 
--------------------begain-------------------
vector_11: 
0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10

reserve 30: 0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 30

swap vector_12: 
size = 0
capacity = 0

swap vector_11: 9 8 7 6 
size = 4
capacity = 4

--------------------end----------------------
*/
