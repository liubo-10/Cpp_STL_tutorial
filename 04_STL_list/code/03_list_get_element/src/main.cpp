/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-17
 * ---------------------------------------
 * | @brief   : 访问 list 测试
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <iostream> // 包含输入和输出操作
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

void get_element_test();

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

    get_element_test();

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void get_element_test()
{
    cout << "get_element_test: " << endl;

    list<int> l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "容器中第一个元素是：" << l_test.front() << endl;
    cout << "容器中最后一个元素是：" << l_test.back() << endl;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
