/*****************************************************************************
 * | @file    : 04_vector_get_element.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |    V1     2025-04-04
 * |    V2     2025-12-26
 * ---------------------------------------
 * | @brief   : vector 获取元素测试
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <iostream> // 包含输入和输出操作
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    printf("--------------------begain-------------------\n");

    // 访问方式1: 运算符 []

    // 1. 使用运算符 []  访问 vector 元素
    // operator[idx];
    // 返回索引idx所指的数据，如果idx越界，运行直接报错
    vector<int> vector_01{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "调用[]，打印 vector_01: ";
    for (int i = 0; i < vector_01.size(); ++i) {
        cout << vector_01[i] << " "; // 调用2
    }
    cout << endl;

    // 2. 使用函数at  访问 vector 元素
    // at(int idx);
    //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
    cout << "调用at，打印 vector_01: ";
    for (int i = 0; i < vector_01.size(); i++) {
        cout << vector_01.at(i) << " ";
    }
    cout << endl;

    // 3. 使用函数 front back 访问 vector 元素
    // at(int idx);
    // front() 返回容器中第一个数据元素
    // back() 返回容器中最后一个数据元素

    cout << "vector_01 中第一个元素是：" << vector_01.front() << endl;
    cout << "vector_01 中最后一个元素是：" << vector_01.back() << endl;

    printf("--------------------end----------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/

/* 
 --------------------begain-------------------
 调用[]，打印 vector_01: 0 1 2 3 4 5 6 7 8 9 
 调用at，打印 vector_01: 0 1 2 3 4 5 6 7 8 9 
 vector_01 中第一个元素是：0
 vector_01 中最后一个元素是：9
 --------------------end----------------------
*/
