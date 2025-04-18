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

void test1();
void test2();

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

    test1();
    test2();

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void test1()
{
    cout << "test1: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = v_test.begin();

    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl
         << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it1 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl
         << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it2 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl
         << endl;


    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it3 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl;
    cout << "addr of it3: " << &*it3 << endl
         << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it4 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl;
    cout << "addr of it3: " << &*it3 << endl;
    cout << "addr of it4: " << &*it4 << endl
         << endl;

    v_test.resize(10);
    vector<int>(v_test).swap(v_test);
    auto it5 = v_test.begin();

    cout << "swap v_test: ";
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it5: " << &*it5 << endl
         << endl;

    v_test.reserve(20);
    auto it6 = v_test.begin();

    cout << "addr of it6: " << &*it6 << endl
         << endl;

    v_test.reserve(30);
    auto it7 = v_test.begin();

    cout << "addr of it7: " << &*it7 << endl
         << endl;
}

void test2()
{
    cout << "test2: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it1 = v_test.begin() + 5; // 指向 5

    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "it1 = " << *it1 << endl;
    cout << "addr of it1: " << &*it1 << endl
         << endl;

    v_test.erase(v_test.begin() + 1); // 删除 1
    auto it2 = v_test.begin() + 5;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "it1 = " << *it1 << endl;
    cout << "it2 = " << *it2 << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl
         << endl;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
