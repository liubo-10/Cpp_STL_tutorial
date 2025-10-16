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
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 使用 pop_back 删除最后一个元素
    v_test.pop_back();
    cout << "使用 pop_back 删除最后一个元素后，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除首个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin());
    cout << "使用 erase 删除首个元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除第二个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin() + 1);
    cout << "使用 erase 删除第二个元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除全部元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin(), v_test.end());
    cout << "使用 erase 删除全部元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除前三个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin(), v_test.begin() + 3);
    cout << "使用 erase 删除前三个元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除后三个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.end() - 3, v_test.end());
    cout << "使用 erase 删除后三个元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除前三个后三个之外的元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin() + 3, v_test.end() - 3);
    cout << "使用 erase 删除前三个后三个之外的元素，打印v_test: ";
    printVector(v_test);

    // 使用 clear 删除全部元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.clear(); // 调用7，清空所有元素
    cout << "使用 clear 删除全部元素，打印v_test: ";
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
