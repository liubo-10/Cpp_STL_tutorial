/*****************************************************************************
 * | @file    : 13_vector_adress.cpp
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |    V1     2026-01-15
 * |    V2     2026-01-20
 * ---------------------------------------
 * | @brief   : vector 数据量和容量测试
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

    cout << __FILE__ << endl;

    cout << "test1: " << endl;
    vector<int> v_test = {0, 1, 2};
    auto it = v_test.begin();

    cout << "v_test origin: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl << endl;

    // push_back（） 对 vector 地址的影响
    cout << "The influence of push_back on address: " << endl;

    // 第一次将容量用完
    while (v_test.size() != v_test.capacity()) {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it1 = v_test.begin();

    cout << "Use up the capacity: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl << endl;

    // 第二次将容量用完
    while (v_test.size() != v_test.capacity()) {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it2 = v_test.begin();

    cout << "Use up the capacity: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl << endl;

    // 第三次将容量用完
    while (v_test.size() != v_test.capacity()) {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it3 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl;
    cout << "addr of it3: " << &*it3 << endl << endl;

    // 第四次将容量用完
    while (v_test.size() != v_test.capacity()) {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it4 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl;
    cout << "addr of it3: " << &*it3 << endl;
    cout << "addr of it4: " << &*it4 << endl << endl;

    // reserve（） 对 vector 地址的影响
    cout << "The influence of reserve on address: " << endl;

    v_test.resize(10);
    vector<int>(v_test).swap(v_test);
    auto it5 = v_test.begin();

    cout << "swap v_test: ";
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it5: " << &*it5 << endl
         << endl;

    v_test.reserve(20);
    auto it6 = v_test.begin();

    cout << "addr of it6: " << &*it6 << endl
         << endl;

    v_test.reserve(30);
    auto it7 = v_test.begin();

    cout << "addr of it7: " << &*it7 << endl
         << endl;







    printf("--------------------end----------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
