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
    cout << "----------------begain------------------" << endl << endl;

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
    // 申请后的空间为原来2倍，2 X 2 = 4
    // size()为3，capacity()为4
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
    // 申请后的空间为原来2倍，4 X 2 = 8
    // size()为5，capacity()为8
    v_test1.push_back(1);
    cout << "5 v_test1.push_back(1)" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // 将容量用完
    // size()为8，capacity()为8
    while (v_test1.size() != v_test1.capacity()) {
        v_test1.push_back(0);
    }
    cout << "v_test1.size() == v_test1.capacity()" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // 再次push_back(1)，容器能够提供的空间是8，又不够，需要申请空间
    // 申请后的空间为原来2倍，8 X 2 = 16
    // size()为9，capacity()为16
    v_test1.push_back(1);
    cout << "9 v_test1.push_back(1)" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // 将容量用完
    // size()为16，capacity()为16
    while (v_test1.size() != v_test1.capacity()) {
        v_test1.push_back(0);
    }
    cout << "v_test1.size() == v_test1.capacity()" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // 再次push_back(1)，容器能够提供的空间是16，又不够，需要申请空间
    // 申请后的空间为原来2倍，16 X 2 = 32
    // size()为17，capacity()为32
    v_test1.push_back(1);
    cout << "17 v_test1.push_back(1)" << endl;
    cout << "v_test1.size:" << v_test1.size() << endl;
    cout << "v_test1.capacity:" << v_test1.capacity() << endl << endl;

    // getchar();
    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/***********************************************************
 * end of file
 **********************************************************/
