/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-15
 * ---------------------------------------
 * | @brief   : unordered_map 插入元素测试
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件
#include <iostream> // 包含输入和输出操作
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::unordered_map;

void insert_test();

// unordered_map 的遍历
void print_unordered_map(unordered_map<int, string> &mp)
{
    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    insert_test();
    
    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void insert_test()
{
    cout << "insert_test: " << endl;
    unordered_map<int, string> mp; // 构造一个空容器

	//1：借助pair构造函数
	pair<int, string> pr(1, "apple");
	mp.insert(pr);
    print_unordered_map(mp);

	//2：借助pair构造匿名对象插入
	mp.insert(pair<int, string>(2, "banana"));
    print_unordered_map(mp);

	//3：调用make_pair函数模板插入
	mp.insert(std::make_pair(3, "orange"));
    print_unordered_map(mp);

	//4：使用[]运算符重载函数进行插入
	mp[4] = "pear";
    print_unordered_map(mp);

	//5：使用{}
	mp.insert({ 5, "lemon" });
    print_unordered_map(mp);
}







/*****************************************************************************
 * end of file
 ******************************************************************************/
