/*****************************************************************************
 * | @file    : 09_STL_string_memory.cpp
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-01-05
 * --------------
 * | @brief   : string example
 ******************************************************************************/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
    cout << "\n----------------s.c_str()内存 测试------------------" << endl;
    string s = "abcdefg";
    const char *char_str = s.c_str(); // 传地址 生成一个const char *指针

    cout << s << endl;
    cout << char_str << endl;

    cout << (int *)s.c_str() << endl;       // 输出首地址
    cout << (int *)char_str << endl;        // 输出首地址 与s.c_str()相同
    cout << (int *)(s.c_str() + 1) << endl; // 输出次地址 首地址 + 1
    cout << (int *)(char_str + 1) << endl;  // 输出次地址 首地址 + 1

    cout << "\n----------------s[] 测试------------------" << endl;
    char &a = s[2]; // 得到引用 即s[2]别名
    char &b = s[3];

    cout << s[2] << endl; // c
    cout << s[3] << endl; // d
    cout << a << endl;    // c
    cout << b << endl;    // d

    cout << &s[2] << endl; // cdefg &取地址,相当于打印字符串地址
    cout << &s[3] << endl; // defg
    cout << &a << endl;    // cdefg
    cout << &b << endl;    // defg

    cout << "\n----------------s重新赋值 测试------------------" << endl;
    a = '1';
    b = '2';

    cout << s << endl;                // ab12efg
    cout << &a << endl;               // 12efg
    cout << &b << endl;               // 2efg
    cout << (int *)s.c_str() << endl; // "abcdefg"首地址

    s = "ppppppppppppp";
    a = '1';
    b = '2';

    cout << s << endl;                // pp12ppppppppp
    cout << &a << endl;               // 12ppppppppp
    cout << &b << endl;               // 2ppppppppp
    cout << (int *)s.c_str() << endl; // "ppppppppppppp"首地址 与 "abcdefg"首地址相同

    s = "qqqqqqqqqqqqqqqqqqqqq"; // 当赋值字符串过长是会重新分配内存
    a = '1';
    b = '2';

    cout << s << endl;            // qqqqqqqqqqqqqqqqqqqqq
    cout << &a << endl;           // 12 仍然保留之前的内存
    cout << &b << endl;           // 2 仍然保留之前的内存
    cout << char_str << endl;     // 空 仍然保留之前的内存
    cout << char_str + 2 << endl; // 12 仍然保留之前的内存

    cout << (int *)char_str << endl;  // 与 "abcdefg"首地址相同 仍然保留之前的内存
    cout << (int *)s.c_str() << endl; // "qqqqqqqqqqqqqqqqqqqqq"首地址 与 "abcdefg"首地址不相同 被分配了新内存

    cout << "----------------end------------------" << endl;
    
    return EXIT_SUCCESS;
}

/***********************************************************
 * end of file
 **********************************************************/
