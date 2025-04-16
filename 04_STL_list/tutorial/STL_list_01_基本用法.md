* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📇 sssssdsdsdsdsdsdasd
* 🎃 dsdsdsdsdsddfsgdgasd
* 🍺 jyukyuiyuiyuigkasd
* 🍥 fsdfgdsgsdgdgadsa
* ✨ xcvxcvxcvxcvdasdaasd
* 🍰 dazdsxasxsaxsaasdsa
* 🚨 gdfgdshdfhfhygjtyu

> # STL_vector_01_基本用法

vector模板是STL(Standard Template Library,标准模板库)中的一个容器类，使用方法类似数组。

使用时包含头文件:

```C++
#include <vector>
```



# 一、vector的构造函数

函数原型:

```C++
vector<T> v ; //使用模板类，默认构造函数
vextor<T> v(n,elem); //将n个elem拷贝给本身
vector<T> v2(const vector &v1) ; //拷贝构造函数
vector<T> v2(v1.begin(), v1.end()); //将[v.begin(),v.end())区间中的元素拷贝给本身，注意左闭右开
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








# STL之list容器

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📖

## list模板介绍



list 是 c++ 中的序列式容器，其实现是双向链表，每个元素都有两个指针，分别指向前一个节点与后一个节点







链表与数组都是计算机常用的内存数据结构，与数组连续内存空间不一样的地方在于，链表的空间是不连续的，链表是将一块块不连续的内存串联起来使用。

正是由于链表的内存不连续这一特点，所以不能像数组一样，可以根据位置随机的访问每个元素，而链表我们压根不知道每个元素的实际位置到底在哪块内存区域。

查找某个元素需要遍历整个链表，直到找到目标元素位置，时间复杂度是 O(n)；

在链表中插入一个元素与删除一个元素的时间复杂度是 O(1)；







头文件:

```C++
#include <list>
```



## std::list 定义对象



```C++
list<A> listname;

list<A> listname(size);

list<A> listname(size,value);

list<A> listname(elselist);

list<A> listname(first, last);
```







## 访问

### front

返回第一个元素的引用

```C++
int nRet = list1.front() // nRet = 1
```



### back

返回最后一个元素的引用

```C++
int nRet = list1.back() // nRet = 3
```



### begin

返回第一个元素的指针(iterator)

```C++
it = list1.begin(); // *it = 1
```



### end

返回最后一个元素的下一位置的指针(list为空时end()=begin())

```C++
it = list1.end();
--it; // *it = 3
```


## 元素移除

### clear

移除所有元素，容器清空

```C++
mylist.clear()
```







### erase

移除iterator位置pos上的元素，返回下一个元素的位置

mylist.size()会减1

```C++
mylist.erase(pos)
```





























## **25.** ***\*3.7 list的底层原理\****

· list的底层是一个双向链表，使用链表存储数据，并不会将它们存储到一整块连续的内存空间中。恰恰相反，各元素占用的存储空间（又称为节点）是独立的、分散的，它们之间的线性关系通过指针来维持,每次插入或删除一个元素，就配置或释放一个元素空间。

· list不支持随机存取，如果需要大量的插入和删除，而不关心随即存取



















## list编程技巧

先判断链表是否为空

 

遇到需要删除头节点的情况，可以建立一个哑节点

遇到需要建立新链表的情况，可以建立一个哑节点

 

注意链表的移动，是不是还是指向头节点，可以新建一个临时变量保存指针，并进行操作初始指针不变。

 

合并多个列表，可以先建立合并两个的函数 






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













