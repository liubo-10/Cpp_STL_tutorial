/*****************************************************************************
 * | @file    : 03_vector_set_value.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |    V1     2025-04-03
 * |    V2     2025-12-26
 * ---------------------------------------
 * | @brief   : 赋值 vector 测试
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

    vector<int> vector_01 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "vector_01: ";
    print_vector(vector_01);

    // 赋值方式1: 运算符 = 重载

    // 1. 重载赋值运算符 =
    // vector& operator=(const vector &v);
    vector<int> vector_11;
    vector_11 = vector_01;
    cout << "vector_11: ";
    print_vector(vector_11);

    cout << "----------------------------------------" << endl;

    // 赋值方式2: assign 函数

    // 2. 函数参数使用迭代器
    // assign(v.begin(),v.end());
    // 将[v.begin(),v.end())区间中的元素赋值给本身

    vector<int> vector_21;

    vector_21.assign(vector_01.begin(), vector_01.end()); // 把 vector_01 值赋给 vector_21,其余值删除,左闭右开
    cout << "vector_21: ";
    print_vector(vector_21);

    vector_21.assign(vector_01.begin(), vector_01.end() - 5); // 把 vector_01 除后五个值之外值赋给 vector_21,左闭右开
    cout << "vector_21: ";
    print_vector(vector_21);

    // 3. 函数参数使用数值
    // assign(n,elem);
    //将n个elem赋值给本身

    vector<int> vector_31(10, 1);
    cout << "vector_31: ";
    print_vector(vector_31);

    vector_31.assign(5, 9); // 把5个9赋给 forth，其余值删除
    cout << "vector_31: ";
    print_vector(vector_31);

    // 4. 函数参数使用数组
    vector<int> vector_41(10, 1);
    cout << "vector_41: ";
    print_vector(vector_41);

    int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_41.assign(myints, myints + 5); //把 myints 前五个值赋给fifth，fifth左闭右开
    cout << "vector_41: ";
    print_vector(vector_41);

    printf("--------------------end----------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
******************************************************************************/

/* 
--------------------begain-------------------
vector_01: 0 1 2 3 4 5 6 7 8 9 
vector_11: 0 1 2 3 4 5 6 7 8 9 
 ---------------------------------------- 
vector_21: 0 1 2 3 4 5 6 7 8 9 
vector_21: 0 1 2 3 4 
vector_31: 1 1 1 1 1 1 1 1 1 1 
vector_31: 9 9 9 9 9 
vector_41: 1 1 1 1 1 1 1 1 1 1 
vector_41: 0 1 2 3 4 
--------------------end----------------------
*/
