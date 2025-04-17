/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-16
 * ---------------------------------------
 * | @brief   : 创建 list 测试
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件
#include <iostream>  // 包含输入和输出操作

#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

void create_test();

// list 的遍历
void print_list(list<int> &li)
{
    for (auto i : li)
    {
        std::cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    create_test();

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void create_test()
{
    cout << "create_test: " << endl;
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    list<int> first;                             // 创建一个值类型为int的空list容器
    list<int> second(10);                        // 创建一个10个int的 list ，且每个元素初值为0
    list<int> third(10, 1);                      // 创建一个10个int的 list ，且每个元素初值为1
    list<int> forth(third);                      // third temp 拷贝给 list forth ，两者元素值完全相同
    list<int> fifth(a, a + 10);                  // 从数组区间[a[0], a[10])中获得初值,注意左开右闭，a[10]无意义这里助于理解
    list<int> sixth(fifth.begin(), fifth.end()); // temp [temp.begin(),temp.end()-5)区间的元素赋给fifth，注意左开右闭
    list<int> seventh = {-1, 0, 3, 5, 7, 9};     // 列表初始化

    cout << "first: ";
    print_list(first);

    cout << "second: ";
    print_list(second);

    cout << "third: ";
    print_list(third);

    cout << "forth: ";
    print_list(forth);

    cout << "fifth: ";
    print_list(fifth);

    cout << "sixth: ";
    print_list(sixth);

    cout << "seventh: ";
    print_list(seventh);
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
