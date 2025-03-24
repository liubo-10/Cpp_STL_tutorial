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

/***********************************************************
 * end of file
 **********************************************************/
