/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-04
 * ---------------------------------------
 * | @brief   : vector 删除元素测试
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

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void resize_test(){
    cout << "resize_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    // resize改变大小，不改变容量
    v_test.resize(5);
    cout << "resize 5: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.resize(20);
    cout << "resize 20: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;
}



void reserve_test(){
    cout << "reserve_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    // reserve 是保留的意思，reserve的值小于size也不会使元素消失，此时的capacity==size
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.reserve(6); // capacity == size == 20
    cout << "reserve 6: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.reserve(30); // 使得capacity=30，里面的元素不会改变
    cout << "reserve 30: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    // clear是清空，不是置零，清空所有元素，所以size为0，但是capacity不变，
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.clear();
    cout << "clear: ";
    printVector(v_test);

    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;




}







/*****************************************************************************
 * end of file
 ******************************************************************************/
