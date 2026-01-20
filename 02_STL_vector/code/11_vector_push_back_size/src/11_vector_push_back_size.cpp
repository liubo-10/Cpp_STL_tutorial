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

    cout << __FUNCTION__ << endl;

    vector<int> v_test;
    cout << "未初始化的 v_test: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    cout << "添加10个元素: " << endl;
    int *pStart = &v_test[0];
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        v_test.push_back(i);
        cout << "push_back(" << i << ")" << endl;
        print_vector(v_test);
        cout << "size = " << v_test.size() << endl;
        cout << "capacity = " << v_test.capacity() << endl;

        if (pStart != &v_test[0]) {
            pStart = &v_test[0];
            count++;
        }
    }
    cout << "adress change count:" << count << endl << endl;

    cout << "将容量用完: " << endl;
    while (v_test.size() != v_test.capacity()) {
        v_test.push_back(0);
    }
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    cout << "在添加1个元素: " << endl;
    v_test.push_back(0);
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    v_test.reserve(100);
    cout << "reserve capacity 100" << endl;
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    cout << "再将容量用完: " << endl;
    while (v_test.size() != v_test.capacity()) {
        v_test.push_back(1);
    }
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    // 再添加1个元素
    cout << "再添加1个元素" << endl;
    v_test.push_back(2);
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    cout << "resize(50):" << endl;
    v_test.resize(50);
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    vector<int> v_test2;
    // 预先开辟空间
    v_test2.reserve(100000);

    cout << "添加100000个元素: " << endl;
    pStart = &v_test2[0];
    count = 0;
    for (int i = 0; i < 100000; ++i) {
        v_test2.push_back(i);
        if (pStart != &v_test2[0]) {
            pStart = &v_test2[0];
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
