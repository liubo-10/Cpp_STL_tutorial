/*****************************************************************************
 * | @file    : 10_vector_clear.cpp
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |    V1     2026-01-14
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

    cout << "before clear: " << endl;
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "empty = " << vector_11.empty() << endl;
    cout << "capacity = " << vector_11.capacity() << endl;
    cout << "max_size = " << vector_11.max_size() << endl << endl;

    vector_11.clear();
    cout << "after clear: " << endl;
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "empty = " << vector_11.empty() << endl;
    cout << "capacity = " << vector_11.capacity() << endl;
    cout << "max_size = " << vector_11.max_size() << endl << endl;

    printf("--------------------end----------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/

//result:
/* 
--------------------begain-------------------
before clear: 
0 1 2 3 4 5 6 7 8 9 
size = 10
empty = 0
capacity = 10
max_size = 2305843009213693951

after clear: 

size = 0
empty = 1
capacity = 10
max_size = 2305843009213693951

--------------------end----------------------
*/
