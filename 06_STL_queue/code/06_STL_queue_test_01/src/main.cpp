/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string>    // C语言的标准库，包含字符串处理操作 strcpy等
#include <queue>     //必须包含该头文件

using std::cin;
using std::cout;
using std::endl;

/*****************************************************************************
 * | @fn     : XXXX
 * | @param  : - XXX XXX
 * |           - XXX XXX
 * |           - XXX XXX
 * | @return :
 * --------------
 * | @brief  : XXX
 * |           XXX
 ******************************************************************************/
int main()
{
    printf("----------------begain------------------\n");

    std::queue<std::string> q;

    q.push("first");  // push()在队尾插入一个元素,没有返回值
    cout << "push first" << endl;
    cout << "front:" << q.front() << endl;          // front() 返回队列中的第一个元素
    cout << "back:" << q.back() << endl;            // back() 返回队列中最后一个元素
    cout << "size:" << q.size() << endl;            // size() 返回队列中元素个数
    cout << "empty:" << q.empty() << endl << endl;  // empty() 如果队列空则返回true

    q.push("second");
    cout << "push second" << endl;
    cout << "front:" << q.front() << endl;
    cout << "back:" << q.back() << endl;
    cout << "size:" << q.size() << endl;
    cout << "empty:" << q.empty() << endl << endl;

    q.push("theard");
    cout << "push theard" << endl;
    cout << "front:" << q.front() << endl;
    cout << "back:" << q.back() << endl;
    cout << "size:" << q.size() << endl;
    cout << "empty:" << q.empty() << endl << endl;

    q.pop();  // pop() 将队列中最靠前位置的元素删除，没有返回值
    cout << "pop 1" << endl;
    cout << "front:" << q.front() << endl;
    cout << "back:" << q.back() << endl;
    cout << "size:" << q.size() << endl;
    cout << "empty:" << q.empty() << endl << endl;

    q.pop();
    cout << "pop 2" << endl;
    cout << "front:" << q.front() << endl;
    cout << "back:" << q.back() << endl;
    cout << "size:" << q.size() << endl;
    cout << "empty:" << q.empty() << endl << endl;

    q.pop();
    cout << "pop 3" << endl;
    cout << "front:" << q.front() << endl;
    cout << "back:" << q.back() << endl;
    cout << "size:" << q.size() << endl;
    cout << "empty:" << q.empty() << endl << endl;

    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/

