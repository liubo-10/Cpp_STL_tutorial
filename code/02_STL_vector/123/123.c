


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



