/*****************************************************************************
 * | @file    : 08_vector_resize.cpp
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |    V1     2025-04-04
 * |    V2     2025-04-07
 * |    V3     2025-12-30
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

    cout << "初始数据: " << endl;
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl;
    cout << "max_size = " << vector_11.max_size() << endl << endl;

    vector<int> vector_12 = vector_11;
    vector_12.resize(5);
    cout << "resize(5): " << endl;
    print_vector(vector_12);
    cout << "size = " << vector_12.size() << endl;
    cout << "capacity = " << vector_12.capacity() << endl;
    cout << "max_size = " << vector_12.max_size() << endl << endl;

    vector<int> vector_13 = vector_11;
    vector_13.resize(20);
    cout << "resize(20): " << endl;
    print_vector(vector_13);
    cout << "size = " << vector_13.size() << endl;
    cout << "capacity = " << vector_13.capacity() << endl;
    cout << "max_size = " << vector_13.max_size() << endl << endl;

    vector<int> vector_14 = vector_11;
    vector_14.resize(20, 9);
    cout << "resize(20,9): " << endl;
    print_vector(vector_14);
    cout << "size = " << vector_14.size() << endl;
    cout << "capacity = " << vector_14.capacity() << endl;
    cout << "max_size = " << vector_14.max_size() << endl << endl;

    printf("--------------------end----------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
