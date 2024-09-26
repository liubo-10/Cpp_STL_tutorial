/*****************************************************************************
 * | @file    : vector_push_back_size_capacity.cpp
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-11
 * | @version : V1.0.1
 * | @date    : 2024-09-26
 * 
 * --------------
 * | @brief   : vector the influence of push_back to size and capacity
 * 
 * 
 ******************************************************************************/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/*****************************************************************************
 * | @fn     : main
 * | @param  :
 * | @return :
 * --------------
 * | @brief  :
 ******************************************************************************/
int main()
{
    cout << "----------------begain------------------" << endl;
    cout << "----------------test1------------------" << endl;

    vector<int> v_test1;
    // 刚声明并且没有初始化的向量
    // size()为0，capacity()为0
    cout << "vector<int> v_test1" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // push_back(1)，容器内有一个元素
    // size()为1，capacity()为1
    v_test1.push_back(1);
    cout << "1 v_test1.push_back(1)" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // 再次push_back(1)，此时容器内能够提供的空间capacity()不够用了，需要申请空间
    // 申请后的大小是以前的2倍，1 X 2 = 2，此时有两个元素
    // size()为2，capacity()为2
    v_test1.push_back(1);
    cout << "2 v_test1.push_back(1)" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // 再次push_back(1)，容器能够提供的空间是2，又不够，需要申请空间
    // 申请后的空间为原来2倍，2 X 2 = 4，那么size()为3，capacity()为4
    // size()为3，capacity()为3
    v_test1.push_back(1);
    cout << "3 v_test1.push_back(1)" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // 再次push_back(1)，容器还能够提供一个空间，不需要申请新空间
    // size()为4，capacity()为4
    v_test1.push_back(1);
    cout << "4 v_test1.push_back(1)" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // 再次push_back(1)，容器能够提供的空间是4，又不够，需要申请空间
    // 申请后的空间为原来2倍，4 X 2 = 8，那么size()为3，capacity()为4
    // size()为3，capacity()为3
    v_test1.push_back(1);
    cout << "5 v_test1.push_back(1)" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    cout << "----------------test2------------------" << endl << endl;

    vector<int> v_test2;
    cout << "capacity: " << v_test2.capacity() << "  size: " << v_test2.size() << endl;
    // 添加10个元素
    for (int i = 0; i < 10; ++i) {
        v_test2.push_back(i);
        cout << "capacity: " << v_test2.capacity() << "  size: " << v_test2.size() << endl;
    }
    // 将容量用完
    while (v_test2.size() != v_test2.capacity()) v_test2.push_back(0);
    // 添加1个元素
    cout << "size = capacity. insert one element\n";
    v_test2.push_back(0);
    cout << "capacity:" << v_test2.capacity() << "  size:" << v_test2.size() << endl;

    v_test2.reserve(100);
    cout << "reserve capacity 100\n";
    cout << "capacity:" << v_test2.capacity() << "  size:" << v_test2.size() << endl;

    // 将容量用完
    while (v_test2.size() != v_test2.capacity()) v_test2.push_back(42);
    // 添加1个元素
    cout << "size = capacity. insert one element\n";
    v_test2.push_back(0);
    cout << "capacity:" << v_test2.capacity() << "  size:" << v_test2.size() << endl;

    v_test2.resize(50);
    cout << "resize size 50\n";
    cout << "capacity:" << v_test2.capacity() << "  size:" << v_test2.size() << endl;
    getchar();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/***********************************************************
 * end of file
 **********************************************************/
