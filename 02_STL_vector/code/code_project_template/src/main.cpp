/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-04
 * ---------------------------------------
 * | @brief   : vector 删除元素测试
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <iostream>  // 包含输入和输出操作
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// vector的遍历
void printVector(vector<int> &v)
{
    for (auto n : v)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 使用 pop_back 删除最后一个元素
    v_test.pop_back();
    cout << "使用 pop_back 删除最后一个元素后，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除首个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin());
    cout << "使用 erase 删除首个元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除第二个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin() + 1);
    cout << "使用 erase 删除第二个元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除全部元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin(), v_test.end());
    cout << "使用 erase 删除全部元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除前三个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin(), v_test.begin() + 3);
    cout << "使用 erase 删除前三个元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除后三个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.end() - 3, v_test.end());
    cout << "使用 erase 删除后三个元素，打印v_test: ";
    printVector(v_test);

    // 使用 erase 删除前三个后三个之外的元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin() + 3, v_test.end() - 3);
    cout << "使用 erase 删除前三个后三个之外的元素，打印v_test: ";
    printVector(v_test);

    // 使用 clear 删除全部元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.clear(); // 调用7，清空所有元素
    cout << "使用 clear 删除全部元素，打印v_test: ";
    printVector(v_test);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}














vector<int> nums = { 5,6,22,1,4,-5,0,88,6,4,99,8,7 };
	cout << "初始数据：" << endl;
	cout <<"size = "<< nums.size() << endl;
	cout <<"capacity = "<< nums.capacity() << endl;
	for (auto n : nums) {
		cout << n <<" ";
	}

	cout <<endl<<endl<< "resize 10:" << endl;
	nums.resize(10);
	for (auto n : nums) {
		cout << n << " ";
	}
	cout <<endl<< "size = " << nums.size() << endl;
	cout << "capacity = " << nums.capacity() << endl;
	cout << endl << "resize 20:" << endl;
	nums.resize(20);
	for (auto n : nums) {
		cout << n << " ";
	}
	cout << "" << endl;
	cout << "size = " << nums.size() << endl;
	cout << "capacity = " << nums.capacity() << endl;

	//reserve 是保留的意思，reserve的值小于size也不会使元素消失，此时的capacity==size
	cout << endl << "reserve 6:" << endl;
	nums.reserve(6);//capacity == size == 20
	for (auto n : nums) {
		cout << n << " ";
	}
	cout << "" << endl;
	cout << "size = " << nums.size() << endl;
	cout << "capacity = " << nums.capacity() << endl;

	cout << endl << "reserve 30:" << endl;
	nums.reserve(30);//使得capacity=30，里面的元素不会改变
	for (auto n : nums) {
		cout << n << " ";
	}
	cout << "" << endl;
	cout << "size = " << nums.size() << endl;
	cout << "capacity = " << nums.capacity() << endl;

	//clear是清空，不是置零，清空所有元素，所以size为0，但是capacity不变，
	cout << endl << "clear:" << endl;
	nums.clear();
	cout << nums.size() << endl;
	cout << nums.capacity() << endl;
	return 0;
	/*
	 *
初始数据：
size = 13
capacity = 13
5 6 22 1 4 -5 0 88 6 4 99 8 7

resize 10:
5 6 22 1 4 -5 0 88 6 4
size = 10
capacity = 13

resize 20:
5 6 22 1 4 -5 0 88 6 4 0 0 0 0 0 0 0 0 0 0
size = 20
capacity = 20

reserve 6:
5 6 22 1 4 -5 0 88 6 4 0 0 0 0 0 0 0 0 0 0
size = 20
capacity = 20

reserve 30:
5 6 22 1 4 -5 0 88 6 4 0 0 0 0 0 0 0 0 0 0
size = 20
capacity = 30

clear:
0
30
*/


























/*****************************************************************************
 * end of file
 ******************************************************************************/
