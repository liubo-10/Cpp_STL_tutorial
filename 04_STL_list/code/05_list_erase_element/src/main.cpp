/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-17
 * ---------------------------------------
 * | @brief   : 删除 list 测试
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

void erase_element_test();

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

    erase_element_test();

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void erase_element_test()
{
    cout << "erase_element_test: " << endl;

    list<int> l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 使用 pop_back 删除最后一个元素
    l_test.pop_back();
    cout << "使用 pop_back 删除最后一个元素: " << endl;
    print_list(l_test);

    // 使用 pop_front 删除第一个元素
    l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    l_test.pop_front();
    cout << "使用 pop_front 删除第一个元素: " << endl;
    print_list(l_test);

    // 使用 erase 删除首个元素
    l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    l_test.erase(l_test.begin());
    cout << "使用 erase 删除首个元素: " << endl;
    print_list(l_test);

    // 使用 erase 删除第二个元素
    l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    l_test.erase(l_test.begin()++);
    cout << "使用 erase 删除第二个元素: " << endl;
    print_list(l_test);

    // 使用 erase 删除全部元素
    l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    l_test.erase(l_test.begin(), l_test.end());
    cout << "使用 erase 删除全部元素: " << endl;
    print_list(l_test);

    // 使用 erase 删除前三个后三个之外的元素
    list<int>::iterator it1, it2;
    it1 = l_test.begin();
    it1++;
    it1++;
    it1++;
    it2 = l_test.end();
    it2--;
    it2--;
    it2--;

    l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    l_test.erase(it1, it2);
    cout << "使用 erase 删除前三个后三个之外的元素: " << endl;
    print_list(l_test);

    // 使用 clear 删除全部元素
    l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    l_test.clear(); // 调用7，清空所有元素
    cout << "使用 clear 删除全部元素: ";
    print_list(l_test);
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
