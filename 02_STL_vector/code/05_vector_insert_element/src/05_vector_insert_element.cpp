/*****************************************************************************
 * | @file    : 05_vector_insert_element.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |    V1     2025-04-04
 * |    V2     2025-12-26
 * ---------------------------------------
 * | @brief   : vector 插入元素测试
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

    // 插入方式1: push_back 函数

    // 1. 尾部插入元素ele
    // push_back(ele);

    vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 3; ++i) {
        vector_11.push_back(10); //尾部插入3个10
    }
    cout << "在尾部插入3个10，打印 vector_11: ";
    print_vector(vector_11);

    cout << "----------------------------------------" << endl;

    // 插入方式2: insert 函数

    // 2. 在迭代器指向的位置pos处插入一个元素ele
    // insert(const_iterator pos,ele); 

    vector<int> vector_21{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_21.insert(vector_21.begin(), 10); //在首位插入10
    cout << "在首位插入1个10，打印 vector_21: ";
    print_vector(vector_21);

    // 3. 在迭代器指向的位置pos处插入count个元素ele
    // insert(const_iterator pos,int count,ele); 

    vector<int> vector_31{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_31.insert(vector_31.begin(), 2, 20); //在首位插入2个20
    cout << "在首位插入2个20，打印 vector_31: ";
    print_vector(vector_31);

    vector<int> vector_32{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_32.insert(vector_32.begin() + 3, 30); //在第3位后面插入30
    cout << "在第3位后面插入30，打印 vector_32: ";
    print_vector(vector_32);

    vector<int> vector_33{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_33.insert(vector_33.begin() + 4, 2, 40); //在第4位后面插入2个40
    cout << "在第4位后面插入2个40，打印 vector_33: ";
    print_vector(vector_33);

    vector<int> vector_34{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_34.insert(vector_34.end() - 3, 2, 50); //在倒数第3位前面插入2个50
    cout << "在倒数第3位前面插入2个50，打印 vector_34: ";
    print_vector(vector_34);

    printf("--------------------end----------------------\n");

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
