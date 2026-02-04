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

    vector<int> v_test{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "初始数据: " << endl;
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "empty = " << v_test.empty() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    v_test.clear();
    cout << "clear: " << endl;
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "empty = " << v_test.empty() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    printf("--------------------end----------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
