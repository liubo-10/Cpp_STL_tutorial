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

void resize_test();
void reserve_test();
void clear_test();

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

    resize_test();
    reserve_test();
    clear_test();

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

void resize_test(){
    cout << "resize_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    vector<int> v_test1 = v_test;
    v_test1.resize(5);
    cout << "resize 5: ";
    printVector(v_test1);
    cout << "size = " << v_test1.size() << endl;
    cout << "capacity = " << v_test1.capacity() << endl << endl;

    vector<int> v_test2 = v_test;
    v_test2.resize(20);
    cout << "resize 20: ";
    printVector(v_test2);
    cout << "size = " << v_test2.size() << endl;
    cout << "capacity = " << v_test2.capacity() << endl << endl;

    vector<int> v_test3 = v_test;
    v_test3.resize(20, 9);
    cout << "resize 20,9: ";
    printVector(v_test3);
    cout << "size = " << v_test3.size() << endl;
    cout << "capacity = " << v_test3.capacity() << endl << endl;
}

void reserve_test(){
    cout << "reserve_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    // reserve 是保留的意思，reserve的值小于size也不会使元素消失，此时的capacity==size
    vector<int> v_test1 = v_test;
    v_test1.reserve(5); // capacity == size == 10
    cout << "reserve 5: ";
    printVector(v_test1);
    cout << "size = " << v_test1.size() << endl;
    cout << "capacity = " << v_test1.capacity() << endl << endl;

    vector<int> v_test2 = v_test;
    v_test2.reserve(30); // 使得capacity=30，里面的元素不会改变
    cout << "reserve 30: ";
    printVector(v_test2);
    cout << "size = " << v_test2.size() << endl;
    cout << "capacity = " << v_test2.capacity() << endl << endl;

}

void clear_test(){
    cout << "clear_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    printVector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    // clear是清空，不是置零，清空所有元素，所以size为0，但是capacity不变，
    v_test.clear();
    cout << "clear: ";
    printVector(v_test);
    cout << "empty = " << v_test.empty() << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;
}







int main7()
{
    cout << "----------------begain------------------" << endl;

	vector<int> ivec;
	cout << "capacity: " << ivec.capacity() << "  size: "  << ivec.size() << endl;
	//添加10个元素
	for (int i = 0; i < 10; ++i)
	{
		ivec.push_back(i);
		cout << "capacity: " << ivec.capacity() << "  size: " << ivec.size() << endl;
	}
	//将容量用完
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	//添加1个元素
	cout << "size = capacity. insert one element\n";
	ivec.push_back(0);
	cout << "capacity:" << ivec.capacity() << "  size:" << ivec.size() << endl;

	ivec.reserve(100);
	cout << "reserve capacity 100\n";
	cout << "capacity:" << ivec.capacity() << "  size:" << ivec.size() << endl;

	//将容量用完
	while (ivec.size() != ivec.capacity())
		ivec.push_back(42);
	//添加1个元素
	cout << "size = capacity. insert one element\n";
	ivec.push_back(0);
	cout << "capacity:" << ivec.capacity() << "  size:" << ivec.size() << endl;

	ivec.resize(50);
	cout << "resize size 50\n";
	cout << "capacity:" << ivec.capacity() << "  size:" << ivec.size() << endl;
	getchar();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}





int main8(){
    cout << "----------------begain------------------" << endl;
    
    cout << "\n----------------大小 容量 测试------------------" << endl;
    vector<int> v;
    for (int i = 0; i < 100000;i ++) {
        v.push_back(i);
    }
    cout << "capacity:" << v.capacity() << endl; // capacity:131072
    cout << "size:" << v.size() << endl;         // size:100000

    // resize改变大小，不改变容量
    cout << "\n----------------resize 测试------------------" << endl;
    v.resize(10);
    cout << "capacity:" << v.capacity() << endl; // capacity:131072
    cout << "size:" << v.size() << endl;         // size:10
    

    // 巧用swap,收缩内存空间
    cout << "\n----------------swap 测试------------------" << endl;

    vector<int>(v).swap(v);
    cout << "capacity:" << v.capacity() << endl; // capacity:10
    cout << "size:" << v.size() << endl;         // size:10

    cout << "\n----------------reserve 测试------------------" << endl;
	vector<int> v1;

	//预先开辟空间
	v1.reserve(100000);

	int* pStart = nullptr;
	int count = 0;
	for (int i = 0; i < 100000;i ++){
		v1.push_back(i);
		if (pStart != &v1[0]){
			pStart = &v1[0];
			count++;
		}
	}

	cout << "count:" << count << endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 @expected output:
-----------------begain------------------

----------------大小 容量 测试------------------
capacity:131072
size:100000

----------------resize 测试------------------
capacity:131072
size:10

----------------swap 测试------------------
capacity:10
size:10

----------------reserve 测试------------------
count:1
----------------end------------------

 */




/*****************************************************************************
 * end of file
 ******************************************************************************/



 int main9()
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




