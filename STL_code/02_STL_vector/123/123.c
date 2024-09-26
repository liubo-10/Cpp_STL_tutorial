#include <iostream>
#include<vector>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main()
{
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
	return 0;
}
/*
capacity: 1  size: 1
capacity: 2  size: 2
capacity: 3  size: 3
capacity: 4  size: 4
capacity: 6  size: 5
capacity: 6  size: 6
capacity: 9  size: 7
capacity: 9  size: 8
capacity: 9  size: 9
capacity: 13  size: 10
size = capacity. insert one element
capacity:19  size:14
reserve capacity 100
capacity:100  size:14
size = capacity. insert one element
capacity:150  size:101
*/





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



