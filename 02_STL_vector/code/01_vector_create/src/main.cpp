/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-03-31
 * ---------------------------------------
 * | @brief   : 创建 vector 测试
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件
#include <iostream>  // 包含输入和输出操作

#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// vector的遍历
void printVector(vector<int> &v)
{ // 利用迭代器打印 v
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> first;                                 // 创建一个值类型为int的空vector
    vector<int> second(10);                            // 创建一个10个int的vector，且每个元素初值为0
    vector<int> third(10, 1);                          // 创建一个10个int的vector，且每个元素初值为1
    vector<int> forth(third);                          // third temp 拷贝给vector forth ，两者元素值完全相同
    vector<int> fifth(a, a + 10);                      // 从数组区间[a[0], a[10])中获得初值,注意左开右闭，a[10]无意义这里助于理解
    vector<int> sixth(fifth.begin(), fifth.end() - 5); // temp [temp.begin(),temp.end()-5)区间的元素赋给fifth，注意左开右闭

    cout << "first: ";
    printVector(first);

    cout << "second: ";
    printVector(second);

    cout << "third: ";
    printVector(third);

    cout << "forth: ";
    printVector(forth);

    cout << "fifth: ";
    printVector(fifth);

    cout << "sixth: ";
    printVector(sixth);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
