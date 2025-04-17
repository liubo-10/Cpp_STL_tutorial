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

> # STL_list_01_基本用法

list 是 c++ 中的序列式容器，其实现是双向链表，每个元素都有两个指针，分别指向前一个节点与后一个节点

使用时包含头文件:

```C++
#include <list>
```



# 一、list的构造函数

函数原型:

```C++
// 1.构造一个空容器，没有元素。
list<T> listname;

// 2.构造一个包含size个元素的容器。每个元素都是0。
list<T> listname(size);

// 3.构造一个包含size个元素的容器。每个元素都是val。
list<T> listname(size,value);

// 4.拷贝构造
list<T> listname2(listname1);

// 5.利用数组构造容器
T m[] = {a,b,c,.....};
list<T> listname(m, m + sizeof(m) / sizeof(T));

// 6.将[v.begin(),v.end())区间中的元素拷贝给本身，注意左闭右开
list<T> listname2(listname1.begin(), listname1.end()); 

// 7.列表初始化构造容器
list<T> listname{a,b,c,.....};
```



使用示例:

```c++
void create_test()
{
    cout << "create_test: " << endl;
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    list<int> first;                             // 创建一个值类型为int的空list容器
    list<int> second(10);                        // 创建一个10个int的 list ，且每个元素初值为0
    list<int> third(10, 1);                      // 创建一个10个int的 list ，且每个元素初值为1
    list<int> forth(third);                      // third temp 拷贝给 list forth ，两者元素值完全相同
    list<int> fifth(a, a + 10);                  // 从数组区间[a[0], a[10])中获得初值,注意左开右闭，a[10]无意义这里助于理解
    list<int> sixth(fifth.begin(), fifth.end()); // temp [temp.begin(),temp.end()-5)区间的元素赋给fifth，注意左开右闭
    list<int> seventh = {-1, 0, 3, 5, 7, 9};     // 列表初始化

    cout << "first: ";
    print_list(first);

    cout << "second: ";
    print_list(second);

    cout << "third: ";
    print_list(third);

    cout << "forth: ";
    print_list(forth);

    cout << "fifth: ";
    print_list(fifth);

    cout << "sixth: ";
    print_list(sixth);

    cout << "seventh: ";
    print_list(seventh);
}

```

测试结果:

```log
--------------------begain-------------------
create_test: 
first: 
second: 0 0 0 0 0 0 0 0 0 0 
third: 1 1 1 1 1 1 1 1 1 1 
forth: 1 1 1 1 1 1 1 1 1 1 
fifth: 0 1 2 3 4 5 6 7 8 9 
sixth: 0 1 2 3 4 5 6 7 8 9 
seventh: -1 0 3 5 7 9 
--------------------end----------------------
```



# 二、list的遍历

方法1：

```c++
void print_list(std::list<int> &li)
{
	for (auto i = li.begin(); i != li.end(); i++)
	{
    	std::cout << *i << ' ';
	}
	std::cout<<std::endl;
}
```

迭代器iterator中的begin和end函数是左闭右开的区间。list 的迭代器没有减法运算。迭代器只有自加自减没，没有加减法。



方法2：

```c++
void print_list(list<int> &li)
{
    for (auto i : li)
    {
        std::cout << i << ' ';
    }
    cout << endl;
}
```



# 三、list的赋值操作

函数原型：

```c++
list& operator = (const list &listname); //重载赋值运算符
listname2.assign(listname1.begin(),listname1.end());          //将[v.begin(),v.end())区间中的元素赋值给本身
listname.assign(n,elem);                     //将n个elem赋值给本身

T m[] = {a,b,c,.....};
listname.assign(m,m + sizeof(m) / sizeof(T));   // assigning from array.
```

assign: 将新内容赋给vector，替换其当前内容，并相应地修改其大小。



使用示例:

```c++
void set_value_test()
{
    cout << "set_value_test: " << endl;

    list<int> first = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "first: ";
    print_list(first);

    // 操作符 = 赋值
    list<int> second;
    second = first;
    cout << "second: ";
    print_list(second);

    // assign 函数赋值，使用迭代器
    list<int> third(10, 1);
    cout << "third1: ";
    print_list(third);

    third.assign(first.begin(), first.end()); // 把first赋给third，其余值删除,左闭右开
    cout << "third2: ";
    print_list(third);

    // assign 函数赋值，使用数值
    list<int> forth(10, 1);
    cout << "forth1: ";
    print_list(forth);

    forth.assign(5, 9); // 把5个9赋给 forth，其余值删除
    cout << "forth2: ";
    print_list(forth);

    // assign 函数赋值，使用数组
    list<int> fifth(10, 1);
    cout << "fifth1: ";
    print_list(fifth);

    int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fifth.assign(myints, myints + 5); // 把 myints 前五个值赋给fifth，fifth左闭右开
    cout << "fifth2: ";
    print_list(fifth);
}
```

测试结果:

```log
--------------------begain-------------------
set_value_test: 
first: 0 1 2 3 4 5 6 7 8 9 
second: 0 1 2 3 4 5 6 7 8 9 
third1: 1 1 1 1 1 1 1 1 1 1 
third2: 0 1 2 3 4 5 6 7 8 9 
forth1: 1 1 1 1 1 1 1 1 1 1 
forth2: 9 9 9 9 9 
fifth1: 1 1 1 1 1 1 1 1 1 1 
fifth2: 0 1 2 3 4 
--------------------end----------------------
```

# 四、list的元素访问

函数原型：

```c++
front(); //返回容器中第一个数据的引用
back();  //返回容器中最后一个数据的引用
```



使用示例:

```c++
void get_element_test()
{
    cout << "get_element_test: " << endl;

    list<int> l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "容器中第一个元素是：" << l_test.front() << endl;
    cout << "容器中最后一个元素是：" << l_test.back() << endl;
}
```

测试结果:

```tex
--------------------begain-------------------
get_element_test: 
容器中第一个元素是：0
容器中最后一个元素是：9
--------------------end----------------------
```



# 五、vector的元素插入

函数原型：

```c++
push_back(ele);  //尾部插入元素ele
push_front(ele); //首部插入元素ele
insert(const_iterator pos,ele); //在迭代器指向的位置pos处插入一个元素ele
insert(const_iterator pos,int count,ele); //在迭代器指向的位置pos处插入count个元素ele
```

使用示例:

```c++
void insert_element_test()
{
    cout << "insert_element_test: " << endl;

    list<int> l_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    l_test.push_back(10); // 尾部插入10
    cout << "在尾部插入10: " << endl;
    print_list(l_test);

    l_test.push_front(20); // 首部插入20
    cout << "在首部插入20: " << endl;
    print_list(l_test);

    l_test.insert(l_test.begin(), 30); // 在首位插入10
    cout << "在首部插入30: " << endl;
    print_list(l_test);

    l_test.insert(l_test.begin(), 2, 40); // 在首位插入2个40
    cout << "在首部插入2个40: " << endl;
    print_list(l_test);

    list<int>::iterator it;
    it = l_test.begin();
    // it = it + 3; // 报错 没有加法
    it++;
    it++;
    it++;
    l_test.insert(it, 50); // 在第3位后面插入30
    cout << "在第3位后面插入50: " << endl;
    print_list(l_test);

    it = l_test.end();
    // it = it - 3; //  报错 没有减法
    it--;
    it--;
    it--;

    l_test.insert(it, 2, 60); // 在倒数第3位前面插入2个60
    cout << "在倒数第3位前面插入2个60: " << endl;
    print_list(l_test);
}
```

测试结果:

```log
--------------------begain-------------------
insert_element_test: 
在尾部插入10: 
0 1 2 3 4 5 6 7 8 9 10 
在首部插入20: 
20 0 1 2 3 4 5 6 7 8 9 10 
在首部插入30: 
30 20 0 1 2 3 4 5 6 7 8 9 10 
在首部插入2个40: 
40 40 30 20 0 1 2 3 4 5 6 7 8 9 10 
在第3位后面插入50: 
40 40 30 50 20 0 1 2 3 4 5 6 7 8 9 10 
在倒数第3位前面插入2个60: 
40 40 30 50 20 0 1 2 3 4 5 6 7 60 60 8 9 10 
--------------------end----------------------
```

# 六、vector的元素删除

函数原型：

```c++
pop_back();  //删除最后一个元素
pop_front(); //删除第一个元素
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator begin,const_iterator end); //删除迭代器从begin到end之间的元素
clear(); //删除容器中所有元素
```

使用示例:

```c++
=
```

测试结果:

```log
=
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



























# 七、总结

以上就是今天要讲的内容，后续会有更多内容。

# 八、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。

1. https://blog.csdn.net/m0_46655373/article/details/122289492
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













