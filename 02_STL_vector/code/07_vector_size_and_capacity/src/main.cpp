/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-04
 * |  V1.0.1    2025-04-07
 * ---------------------------------------
 * | @brief   : vector 数据量和容量测试
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

void resize_test();
void reserve_test();
void clear_test();
void push_back_test();
void swap_test();

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

    resize_test();
    reserve_test();
    clear_test();
    push_back_test();
    swap_test();

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void resize_test()
{
    cout << "resize_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "max_size = " << v_test.max_size() << endl << endl;

    vector<int> v_test1 = v_test;
    v_test1.resize(5);
    cout << "resize 5: ";
    printVector(v_test1);
    cout << "size = " << v_test1.size() << endl;
    cout << "capacity = " << v_test1.capacity() << endl << endl;

    vector<int> v_test2 = v_test;
    v_test2.resize(20);
    cout << "resize 20: ";
    printVector(v_test2);
    cout << "size = " << v_test2.size() << endl;
    cout << "capacity = " << v_test2.capacity() << endl << endl;

    vector<int> v_test3 = v_test;
    v_test3.resize(20, 9);
    cout << "resize 20,9: ";
    printVector(v_test3);
    cout << "size = " << v_test3.size() << endl;
    cout << "capacity = " << v_test3.capacity() << endl << endl;
}

void reserve_test(){
    cout << "reserve_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    // reserve 是保留的意思，reserve的值小于size也不会使元素消失，此时的capacity==size
    vector<int> v_test1 = v_test;
    v_test1.reserve(5); // capacity == size == 10
    cout << "reserve 5: ";
    printVector(v_test1);
    cout << "size = " << v_test1.size() << endl;
    cout << "capacity = " << v_test1.capacity() << endl << endl;

    vector<int> v_test2 = v_test;
    v_test2.reserve(30); // 使得capacity=30，里面的元素不会改变
    cout << "reserve 30: ";
    printVector(v_test2);
    cout << "size = " << v_test2.size() << endl;
    cout << "capacity = " << v_test2.capacity() << endl << endl;

}

void clear_test()
{
    cout << "clear_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;

    // clear是清空，不是置零，清空所有元素，所以size为0，但是capacity不变，
    v_test.clear();
    cout << "clear: ";
    printVector(v_test);
    cout << "empty = " << v_test.empty() << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;
}

void push_back_test()
{
    cout << "push_back_test: " << endl;
    vector<int> v_test;
    cout << "未初始化vector: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;

    cout << "添加10个元素: " << endl;
    int *pStart = &v_test[0];
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        v_test.push_back(i);
        cout << "capacity: " << v_test.capacity() << "  size: " << v_test.size() << endl;
        if (pStart != &v_test[0])
        {
            pStart = &v_test[0];
            count++;
        }
    }
    cout << "count:" << count << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    cout << endl;

    // 添加1个元素
    cout << "size = capacity\n";
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl;

    cout << "insert one element\n";
    v_test.push_back(0);
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl
         << endl;

    v_test.reserve(100);
    cout << "reserve capacity 100\n";
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    cout << endl;

    // 添加1个元素
    cout << "size = capacity\n";
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl;

    cout << "insert one element\n";
    v_test.push_back(0);
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl
         << endl;

    v_test.resize(50);
    cout << "resize size 50\n";
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl
         << endl;

    vector<int> v1;
    // 预先开辟空间
    v1.reserve(100000);

    pStart = &v1[0];
    count = 0;
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
        if (pStart != &v1[0])
        {
            pStart = &v1[0];
            count++;
        }
    }
    cout << "count:" << count << endl
         << endl;
}

void swap_test()
{
    cout << "swap_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;

    v_test.reserve(30); // 使得capacity=30，里面的元素不会改变
    cout << "reserve 30: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;

    // vector<int>(v_test) 是创建一个匿名对象，并拷贝v_test的数据
    // 以此匿名对象与v_test交换，交换完后系统自动删除匿名对象
    vector<int>(v_test).swap(v_test);

    cout << "swap v_test: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
