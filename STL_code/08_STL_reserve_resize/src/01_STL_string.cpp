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

	//reserve
	string s1;	//定义一个对象
	s1 = "0123456789";
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << endl;

	s1.reserve(30);	//给这个对象请求更大的空间使用权
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << endl;

	s1.reserve(15);	//请求给对象更小的使用权
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/***********************************************************
 * end of file
 **********************************************************/
