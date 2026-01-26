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

    //插入方式1: push_back 函数

    //1. 尾部插入元素ele
    //push_back(ele);

    vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 3; ++i) {
        vector_11.push_back(10); //尾部插入3个10
    }
    cout << "在尾部插入3个10，打印 vector_11: ";
    print_vector(vector_11);

    cout << endl;

    //插入方式2: insert 函数

    //2.插入一个元素
    //iterator insert(const_iterator pos, const T& value);
    //在迭代器指向的位置 pos 前面插入一个元素 value

    vector<int> vector_21{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_21.insert(vector_21.begin(), 10); //在首位插入10
    cout << "在首位插入1个10，打印 vector_21: ";
    print_vector(vector_21);

    vector<int> vector_22{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_22.insert(vector_22.end(), 10); //在末位插入10
    cout << "在末位插入1个10，打印 vector_22: ";
    print_vector(vector_22);

    //3.插入多个相同的元素
    //iterator insert(const_iterator pos, size_type count, const T& value);
    //在迭代器指向的位置 pos 前面插入 count 个元素 value

    vector<int> vector_31{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_31.insert(vector_31.begin(), 3, 10); //在首位插入3个10
    cout << "在首位插入3个10，打印 vector_31: ";
    print_vector(vector_31);

    vector<int> vector_32{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_32.insert(vector_32.begin() + 3, 3, 30); //在索引3的位置前面插入3个30
    cout << "在索引3的位置前面插入3个30，打印 vector_32: ";
    print_vector(vector_32);

    //4.插入一个范围的元素
    //template <class InputIterator>
    //void insert(const_iterator pos, InputIterator first, InputIterator last);

    vector<int> vector_40{99, 100, 101};
    vector<int> vector_41{0, 1, 2, 3, 4, 5};
    vector_41.insert(vector_41.begin() + 2, vector_40.begin(), vector_40.end()); // 在索引2的位置插入 vector_40 的所有元素
    cout << "在索引2的位置插入 vector_40 的所有元素，打印 vector_41:";
    print_vector(vector_41);

    int a[3] = {100, 200, 300};
    vector<int> vector_42{0, 1, 2, 3, 4, 5};
    vector_42.insert(vector_42.begin() + 2, a, a + 2); // 在索引2的位置插入数组 a 的所有元素
    cout << "在索引2的位置插入数组 a 的所有元素，打印 vector_42:";
    print_vector(vector_42);

    //5.插入初始化列表中的元素（C++11 及以上）
    //void insert(const_iterator pos, initializer_list<T> ilist);

    vector<int> vector_51 = {0, 1, 2, 3, 4, 5};
    vector_51.insert(vector_51.begin() + 3, {99, 100, 101}); // 在索引3的位置插入初始化列表中的元素
    cout << "在索引3的位置插入列表的所有元素，打印 vector_51:";
    print_vector(vector_51);

    printf("--------------------end----------------------\n");

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
