/*****************************************************************************
 * | @file    : 11_vector_push_back_size.cpp
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

    vector<int> vector_11;
    cout << "vector_11:" << endl;
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    cout << "push_back 10 elements:" << endl;
    int *pStart = &vector_11[0];
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        vector_11.push_back(i);
        cout << "push_back(" << i << ")" << endl;
        print_vector(vector_11);
        cout << "size = " << vector_11.size() << endl;
        cout << "capacity = " << vector_11.capacity() << endl << endl;

        if (pStart != &vector_11[0]) {
            pStart = &vector_11[0];
            count++;
        }
    }
    cout << "adress change count:" << count << endl << endl;

    cout << "Use up the capacity: " << endl;
    while (vector_11.size() != vector_11.capacity()) {
        vector_11.push_back(0);
    }
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    cout << "push_back 1 element: " << endl;
    vector_11.push_back(1);
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    vector_11.reserve(100);
    cout << "reserve capacity 100" << endl;
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    cout << "Use up the capacity: " << endl;
    while (vector_11.size() != vector_11.capacity()) {
        vector_11.push_back(2);
    }
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    // 再添加1个元素
    cout << "push_back 1 element" << endl;
    vector_11.push_back(3);
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    cout << "resize(50):" << endl;
    vector_11.resize(50);
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    vector<int> vector_12;
    // 预先开辟空间
    vector_12.reserve(100000);

    cout << "push_back 100000 elements:" << endl;
    pStart = &vector_12[0];
    count = 0;
    for (int i = 0; i < 100000; ++i) {
        vector_12.push_back(i);
        if (pStart != &vector_12[0]) {
            pStart = &vector_12[0];
            count++;
        }
    }
    cout << "adress change count:" << count << endl << endl;

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
 size = 0
 capacity = 0
 
 push_back 10 elements:
 push_back(0)
 0 
 size = 1
 capacity = 1
 
 push_back(1)
 0 1 
 size = 2
 capacity = 2
 
 push_back(2)
 0 1 2 
 size = 3
 capacity = 4
 
 push_back(3)
 0 1 2 3 
 size = 4
 capacity = 4
 
 push_back(4)
 0 1 2 3 4 
 size = 5
 capacity = 8
 
 push_back(5)
 0 1 2 3 4 5 
 size = 6
 capacity = 8
 
 push_back(6)
 0 1 2 3 4 5 6 
 size = 7
 capacity = 8
 
 push_back(7)
 0 1 2 3 4 5 6 7 
 size = 8
 capacity = 8
 
 push_back(8)
 0 1 2 3 4 5 6 7 8 
 size = 9
 capacity = 16
 
 push_back(9)
 0 1 2 3 4 5 6 7 8 9 
 size = 10
 capacity = 16
 
 adress change count:5
 
 Use up the capacity: 
 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 
 size = 16
 capacity = 16
 
 push_back 1 element: 
 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 
 size = 17
 capacity = 32
 
 reserve capacity 100
 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 
 size = 17
 capacity = 100
 
 Use up the capacity: 
 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
 size = 100
 capacity = 100
 
 push_back 1 element
 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 
 size = 101
 capacity = 200
 
 resize(50):
 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
 size = 50
 capacity = 200
 
 push_back 100000 elements:
 adress change count:0
 
 --------------------end----------------------
*/





