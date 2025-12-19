/*****************************************************************************
 * | @file    : 01_vector_create.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-03-31
 * ---------------------------------------
 * | @brief   : 创建 vector 测试
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件
#include <iostream> // 包含输入和输出操作

#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// vector的遍历
void print_vector(vector<int> &v)
{ // 利用迭代器打印 v
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    // 1.构造一个空容器，没有元素。
    // vector<T> vectorname;
    vector<int> vector_1; // 创建一个值类型为int的空vector
    cout << "vector_1: ";
    print_vector(vector_1);

    // 2.构造一个包含size个元素的容器。每个元素都是0。
    // vector<T> vectorname(size);
    vector<int> vector_2(10); // 创建一个10个int的vector，且每个元素初值为0
    cout << "vector_2: ";
    print_vector(vector_2);

    // 3.构造一个包含size个元素的容器。每个元素都是val。
    // vector<T> vectorname(size, value);
    vector<int> vector_3(10, 1); // 创建一个10个int的vector，且每个元素初值为1
    cout << "vector_3: ";
    printVector(vector_3);

    // 4.拷贝构造
    // vector<T> vectorname2(vectorname1);
    vector<int> vector_4(vector_3); // third temp 拷贝给vector forth ，两者元素值完全相同
    cout << "vector_4: ";
    printVector(vector_4);

    // 5.利用数组构造容器
    // T m[] = {a, b, c, .....};
    // vector<T> vectorname(m, m + sizeof(m) / sizeof(T));
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vector_5(a, a + 10); // 从数组区间[a[0], a[10])中获得初值,注意左开右闭，a[10]无意义这里助于理解
    cout << "vector_5: ";
    printVector(vector_5);

    // 6.将[v.begin(),v.end())区间中的元素拷贝给本身，注意左闭右开
    // vector<T> vectorname2(vectorname1.begin(), vectorname1.end());
    vector<int> vector_6(fifth.begin(), fifth.end() - 5); // temp [temp.begin(),temp.end()-5)区间的元素赋给fifth，注意左开右闭
    cout << "vector_6: ";
    printVector(vector_6);

    // 7.列表初始化构造容器
    // vector<T> vectorname{a, b, c, .....};
    vector<int> vector_7 = {-1, 0, 3, 5, 7, 9}; // 列表初始化
    cout << "vector_7: ";
    printVector(vector_7);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
