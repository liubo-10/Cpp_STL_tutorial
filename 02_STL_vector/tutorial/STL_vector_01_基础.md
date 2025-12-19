# STL_vector_01_基础

* 👋 Hi, I’m liubo
* 👀 I’m interested in
* 🌱 I’m currently learning
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📇 sssssdsdsdsdsdsdasd
* 🎃 dsdsdsdsdsddfsgdgasd
* 🍺 jyukyuiyuiyuigkasd
* 🍥 fsdfgdsgsdgdgadsa
* ✨ xcvxcvxcvxcvdasdaasd
* 🍰 dazdsxasxsaxsaasdsa
* 🚨 gdfgdshdfhfhygjtyu
## 💞️ vector 简介
vector模板是STL(Standard Template Library,标准模板库)中的一个容器类，使用方法类似数组。

使用时包含头文件:

```cpp
#include <vector>
```

## 💞️ vector 的构造

函数原型:

```cpp
// 1.构造一个空容器，没有元素。
vector<T> vectorname;

// 2.构造一个包含size个元素的容器。每个元素都是0。
vector<T> vectorname(size);

// 3.构造一个包含size个元素的容器。每个元素都是val。
vector<T> vectorname(size,value);

// 4.拷贝构造
vector<T> vectorname2(vectorname1);

// 5.利用数组构造容器
T m[] = {a,b,c,.....};
vector<T> vectorname(m, m + sizeof(m) / sizeof(T));

// 6.将[v.begin(),v.end())区间中的元素拷贝给本身，注意左闭右开
vector<T> vectorname2(vectorname1.begin(), vectorname1.end()); 

// 7.列表初始化构造容器
vector<T> vectorname{a,b,c,.....};
```

使用示例:

```c++
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件
#include <iostream>  // 包含输入和输出操作

#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// vector的遍历
void printVector(vector<int>& v)
{	//利用迭代器打印 v
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> first;                                 // 创建一个值类型为int的空vector
    vector<int> second(10);                            // 创建一个10个int的vector，且每个元素初值为0
    vector<int> third(10, 1);                          // 创建一个10个int的vector，且每个元素初值为1
    vector<int> forth(third);                          // third temp 拷贝给vector forth ，两者元素值完全相同
    vector<int> fifth(a, a + 10);                      // 从数组区间[a[0], a[10])中获得初值,注意左闭右开，a[10]无意义这里助于理解
    vector<int> sixth(fifth.begin(), fifth.end() - 5); // temp [temp.begin(),temp.end()-5)区间的元素赋给fifth，注意左闭右开
    vector<int> seventh = { -1, 0, 3, 5, 7, 9};        // 列表初始化

    cout << "first: ";
    printVector(first);

    cout << "second: ";
    printVector(second);

    cout << "third: ";
    printVector(third);

    cout << "forth: ";
    printVector(forth);

    cout << "fifth: ";
    printVector(fifth);

    cout << "sixth: ";
    printVector(sixth);
    
    cout << "seventh: ";
    printVector(seventh);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}
```

测试结果:

```log
--------------------begain-------------------
first: 
second: 0 0 0 0 0 0 0 0 0 0 
third: 1 1 1 1 1 1 1 1 1 1 
forth: 1 1 1 1 1 1 1 1 1 1 
fifth: 0 1 2 3 4 5 6 7 8 9 
sixth: 0 1 2 3 4 
seventh: -1 0 3 5 7 9 
--------------------end----------------------
```



# 二、vector的遍历

方法1：

```c++
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
```

迭代器iterator中的begin和end函数是左闭右开的区间。



方法2：

```c++
void printVector(vector<int> &v)
{ 
    for (auto n : v)
    {
        cout << n << " ";
    }
    cout << endl;
}
```



# 三、vector的赋值操作

函数原型：

```c++
vector& operator=(const vector &v); //重载赋值运算符
assign(v.begin(),v.end());          //将[v.begin(),v.end())区间中的元素赋值给本身
assign(n,elem);                     //将n个elem赋值给本身

int myints[];
third.assign(myints,myints+3);   // assigning from array.
```

assign: 将新内容赋给vector，替换其当前内容，并相应地修改其大小。



使用示例:

```c++
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
    vector<int> first = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "first: ";
    printVector(first);

    //操作符 = 赋值
    vector<int> second;
    second = first;
    cout << "second: ";
    printVector(second);

    // assign 函数赋值，使用迭代器
    vector<int> third(10, 1);
    cout << "third1: ";
    printVector(third);

    third.assign(first.begin(), first.end() - 5); // 把first除后五个值之外值赋给third，其余值删除,左闭右开
    cout << "third2: ";
    printVector(third);

    // assign 函数赋值，使用数值
    vector<int> forth(10, 1);
    cout << "forth1: ";
    printVector(forth);

    forth.assign(5, 9); // 把5个9赋给 forth，其余值删除
    cout << "forth2: ";
    printVector(forth);

    // assign 函数赋值，使用数组
    vector<int> fifth(10, 1);
    cout << "fifth1: ";
    printVector(fifth);

    int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fifth.assign(myints, myints + 5); //把 myints 前五个值赋给fifth，fifth左闭右开
    cout << "fifth2: ";
    printVector(fifth);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}
```

测试结果:

```log
--------------------begain-------------------
first: 0 1 2 3 4 5 6 7 8 9 
second: 0 1 2 3 4 5 6 7 8 9 
third1: 1 1 1 1 1 1 1 1 1 1 
third2: 0 1 2 3 4 
forth1: 1 1 1 1 1 1 1 1 1 1 
forth2: 9 9 9 9 9 
fifth1: 1 1 1 1 1 1 1 1 1 1 
fifth2: 0 1 2 3 4 
--------------------end----------------------
```

# 四、vector的元素访问

函数原型：

```c++
at(int idx);    //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[idx];  //返回索引idx所指的数据，如果idx越界，运行直接报错
front();        //返回容器中第一个数据元素
back();         //返回容器中最后一个数据元素
```



使用示例:

```c++
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <iostream>  // 包含输入和输出操作
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    printf("--------------------begain-------------------\n");
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> v_test(a, a + 10);

    cout << "调用at，打印 v_test: ";
    for (int i = 0; i < v_test.size(); i++)
    {
        cout << v_test.at(i) << " ";
    }
    cout << endl;

    cout << "调用[]，打印 v_test: ";
    for (int i = 0; i < v_test.size(); ++i)
    {
        cout << v_test[i] << " "; // 调用2
    }
    cout << endl;

    cout << "容器中第一个元素是：" << v_test.front() << endl;
    cout << "容器中最后一个元素是：" << v_test.back() << endl;

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}
```

测试结果:

```tex
--------------------begain-------------------
调用at，打印 v_test: 0 1 2 3 4 5 6 7 8 9 
调用[]，打印 v_test: 0 1 2 3 4 5 6 7 8 9 
容器中第一个元素是：0
容器中最后一个元素是：9
--------------------end----------------------
```



# 五、vector的元素插入

函数原型：

```c++
push_back(ele); //尾部插入元素ele
insert(const_iterator pos,ele); //在迭代器指向的位置pos处插入一个元素ele
insert(const_iterator pos,int count,ele); //在迭代器指向的位置pos处插入count个元素ele
```

push_back: 在vector当前最后一个元素的末尾添加一个新元素。val的内容被复制(或移动)到新元素中。

将容器大小增加了1，当且仅当新vector大小 > 当前vector容量时，会自动重新分配存储空间。



使用示例:

```c++
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
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> v_test(a, a + 10);

    for (int i = 0; i < 3; ++i)
    {
        v_test.push_back(10);//尾部插入3个10
    }
    cout << "在尾部插入3个10，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.begin(), 10); //在首位插入10
    cout << "在第首位插入10，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.begin(), 2, 20);//在首位插入2个20
    cout << "在首位插入2个20，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.begin() + 3,30); //在第3位后面插入30
    cout << "在第3位后面插入30，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.begin() + 4, 2, 40); //在第4位后面插入2个40
    cout << "在第4位后面插入2个40，打印 v_test: ";
    printVector(v_test);

    v_test.insert(v_test.end() - 3, 2, 50);//在倒数第3位前面插入2个50
    cout << "在倒数第3位前面插入2个50，打印 v_test: ";
    printVector(v_test);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}
```

测试结果:

```log
--------------------begain-------------------
在尾部插入3个10，打印 v_test: 0 1 2 3 4 5 6 7 8 9 10 10 10 
在第首位插入10，打印 v_test: 10 0 1 2 3 4 5 6 7 8 9 10 10 10 
在首位插入2个20，打印 v_test: 20 20 10 0 1 2 3 4 5 6 7 8 9 10 10 10 
在第3位后面插入30，打印 v_test: 20 20 10 30 0 1 2 3 4 5 6 7 8 9 10 10 10 
在第4位后面插入2个40，打印 v_test: 20 20 10 30 40 40 0 1 2 3 4 5 6 7 8 9 10 10 10 
在倒数第3位前面插入2个50，打印 v_test: 20 20 10 30 40 40 0 1 2 3 4 5 6 7 8 9 50 50 10 10 10 
--------------------end----------------------
```

# 六、vector的元素删除

函数原型：

```c++
pop_back(); //删除最后一个元素
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator begin,const_iterator end); //删除迭代器从begin到end之间的元素
clear(); //删除容器中所有元素
```

使用示例:

```c++
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

```

测试结果:

```log
--------------------begain-------------------
使用 pop_back 删除最后一个元素后，打印v_test: 0 1 2 3 4 5 6 7 8 
使用 erase 删除首个元素，打印v_test: 1 2 3 4 5 6 7 8 9 
使用 erase 删除第二个元素，打印v_test: 0 2 3 4 5 6 7 8 9 
使用 erase 删除全部元素，打印v_test: 
使用 erase 删除前三个元素，打印v_test: 3 4 5 6 7 8 9 
使用 erase 删除后三个元素，打印v_test: 0 1 2 3 4 5 6 
使用 erase 删除前三个后三个之外的元素，打印v_test: 0 1 2 7 8 9 
使用 clear 删除全部元素，打印v_test: 
--------------------end----------------------
```



# 七、总结

以上就是今天要讲的内容，后续会有更多内容。

# 八、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。

1. https://blog.csdn.net/qq_52324409/article/details/121000029
4. 
5. 

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

---

