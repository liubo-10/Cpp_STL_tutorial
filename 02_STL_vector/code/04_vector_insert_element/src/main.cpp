/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-04
 * ---------------------------------------
 * | @brief   : vector 插入元素测试
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
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> v_test(a, a + 10);

    for (int i = 0; i < 3; ++i)
    {
        v_test.push_back(10);//尾部插入3个10
    }
    cout << "在尾部插入3个10，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.begin(), 10); //在首位插入10
    cout << "在第首位插入10，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.begin(), 2, 20);//在首位插入2个20
    cout << "在首位插入2个20，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.begin() + 3,30); //在第3位后面插入30
    cout << "在第3位后面插入20，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.begin() + 4, 2, 40); //在第4位后面插入2个40
    cout << "在第4位后面插入2个40，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.end() - 2, 2, 50);//在倒数第二位前面插入2个50
    cout << "在最后一位前面插入2个30，打印 v_test: ";
    printVector(v_test);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
