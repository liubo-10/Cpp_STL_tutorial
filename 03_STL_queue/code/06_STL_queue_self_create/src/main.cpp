/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-02-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等

using std::cin;
using std::cout;
using std::endl;

class queue
{
    /*默认私有*/
    int q[100];
    int sloc, rloc;

   public:
    queue();
    void qput(int i);
    int qget();
};
queue::queue()
{
    sloc = rloc = 0;
    cout << "queue initialized" << endl;
}
void queue::qput(int i)
{
    if (sloc == 100) {
        cout << "queue is full" << endl;
        return;
    }
    sloc++;
    q[sloc] = i;
}
int queue::qget()
{
    if (rloc == sloc) {
        cout << "queue is empty" << endl;
        return 0;
    }
    rloc++;
    return q[rloc];
}

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

    queue a,b;
    a.qput(10);
    b.qput(20);
    a.qput(20);
    b.qput(19);
    cout<<a.qget()<<" ";
    cout<<b.qget()<<"\n";
    cout<<a.qget()<<" "; 
    cout<<b.qget()<<"\n";

    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
