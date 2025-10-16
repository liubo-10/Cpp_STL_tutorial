/*****************************************************************************
 * | @file    : 01_STL_string.cpp
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-01-05
 * --------------
 * | @brief   : string example
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
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

    // reserve
    string s1;  // 定义一个对象
    s1 = "0123456789";
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << s1.capacity() << endl;
    cout << endl;

    s1.reserve(30);  // 给这个对象请求更大的空间使用权
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << s1.capacity() << endl;
    cout << endl;

    s1.reserve(15);  // 请求给对象更小的使用权
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << s1.capacity() << endl;

    string s2;  // 定义一个对象

    s2 = "123456789012345678901234567890";
    cout << s2 << endl;
    cout << s2.size() << endl;
    cout << s2.capacity() << endl;
    cout << endl;

    vector<int> v;  // 此时没有初始化，所以size()和capacity()都是0；
    cout << v.size() << endl << v.capacity() << endl;
    v.push_back(1);
    cout << v.size() << endl << v.capacity() << endl;  // 此时容器内有一个元素了，那么size()和capacity()都是1
    v.push_back(1);
    cout<< v.size() << endl<< v.capacity()<< endl;  // 此时容器内能够提供的空间capacity()不够用了，需要申请内容，申请多少呢，申请后的大小应该是以前的2倍，那就应该是2了，此时有两个元素，size（）为2，capacity（）也是2
    v.push_back(1);
    cout<< v.size() << endl<< v.capacity()<< endl;  // 此时容器能够提供的空间是2，又增加元素，不够，需要申请空间，申请后的空间为原来2倍，就是4了，那么size()为3，capacity（）为4
    v.push_back(1);
    cout << v.size() << endl<< v.capacity() << endl;  // 容器还能够提供一个空间，不需要申请新空间，size()为4，capacity（）为4
    v.push_back(1);
    cout << v.size() << endl << v.capacity() << endl;  // 空间不够，需要申请，size()为5，capacity为8

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/***********************************************************
 * end of file
 **********************************************************/
