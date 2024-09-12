/*****************************************************************************
 * | @file    : vector_size.cpp
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-11
 * --------------
 * | @brief   : vector size test
 * 
 * 
 * https://blog.csdn.net/JIEJINQUANIL/article/details/51166154?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522908BB720-376B-4F29-8B2A-026B70C0B064%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=908BB720-376B-4F29-8B2A-026B70C0B064&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-51166154-null-null.142^v100^pc_search_result_base7&utm_term=capacity&spm=1018.2226.3001.4187
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

    // reserve
    // 此时没有初始化，所以size()和capacity()都是0；
    vector<int> v;
    cout << "vector<int> v" << endl;
    cout << "v.size:" << v.size() << endl;
    cout << "v.capacity:" << v.capacity() << endl << endl;

    // 此时容器内有一个元素了，那么size()和capacity()都是1
    v.push_back(1);
    cout << "1 v.push_back(1)" << endl;
    cout << "v.size:" << v.size() << endl;
    cout << "v.capacity:" << v.capacity() << endl << endl;

    // 此时容器内能够提供的空间capacity()不够用了，需要申请内容，
    // 申请多少呢，申请后的大小应该是以前的2倍，那就应该是2了，此时有两个元素，size()为2，capacity()也是2
    v.push_back(1);
    cout << "2 v.push_back(1)" << endl;
    cout << "v.size:" << v.size() << endl;
    cout << "v.capacity:" << v.capacity() << endl << endl;

    // 此时容器能够提供的空间是2，又增加元素，不够，需要申请空间，
    // 申请后的空间为原来2倍，就是4了，那么size()为3，capacity()为4
    v.push_back(1);
    cout << "3 v.push_back(1)" << endl;
    cout << "v.size:" << v.size() << endl;
    cout << "v.capacity:" << v.capacity() << endl << endl;

    // 容器还能够提供一个空间，不需要申请新空间，size()为4，capacity()为4
    v.push_back(1);
    cout << "4 v.push_back(1)" << endl;
    cout << "v.size:" << v.size() << endl;
    cout << "v.capacity:" << v.capacity() << endl << endl;

    // 空间不够，需要申请，size()为5，capacity为8
    v.push_back(1);
    cout << "5 v.push_back(1)" << endl;
    cout << "v.size:" << v.size() << endl;
    cout << "v.capacity:" << v.capacity() << endl<< endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/***********************************************************
 * end of file
 **********************************************************/
