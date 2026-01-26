# 02_STL_vector_进阶用法


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

## 💞️ vector的元素插入

---

函数原型：

```cpp
//1.尾部插入元素ele
push_back(ele);

//2.在迭代器指向的位置pos处插入一个元素ele
insert(const_iterator pos,ele); 

//3.在迭代器指向的位置pos处插入count个元素ele
insert(const_iterator pos,int count,ele); 

//4.插入一个范围的元素
template <class InputIterator>
void insert(const_iterator pos, InputIterator first, InputIterator last);

//5.插入初始化列表中的元素（C++11 及以上）
void insert(const_iterator pos, initializer_list<T> ilist);

```

push_back: 在vector当前最后一个元素的末尾添加一个新元素。val的内容被复制(或移动)到新元素中。

将容器大小增加了1，当且仅当新vector大小大于当前vector容量时，会自动重新分配存储空间。



使用示例:

```cpp
printf("--------------------begain-------------------\n");

//插入方式1: push_back 函数

//1. 尾部插入元素ele
//push_back(ele);

vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

for (int i = 0; i < 3; ++i) {
    vector_11.push_back(10); //尾部插入3个10
}
cout << "vector_11: ";
print_vector(vector_11);

cout << endl;

//插入方式2: insert 函数

//2.插入一个元素
//iterator insert(const_iterator pos, const T& value);
//在迭代器指向的位置 pos 前面插入一个元素 value

vector<int> vector_21{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector_21.insert(vector_21.begin(), 10); //在首位插入10
cout << "vector_21: ";
print_vector(vector_21);

vector<int> vector_22{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector_22.insert(vector_22.end(), 10); //在末位插入10
cout << "vector_22: ";
print_vector(vector_22);

//3.插入多个相同的元素
//iterator insert(const_iterator pos, size_type count, const T& value);
//在迭代器指向的位置 pos 前面插入 count 个元素 value

vector<int> vector_31{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector_31.insert(vector_31.begin(), 3, 10); //在首位插入3个10
cout << "vector_31: ";
print_vector(vector_31);

vector<int> vector_32{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector_32.insert(vector_32.begin() + 3, 3, 30); //在索引3的位置前面插入3个30
cout << "vector_32: ";
print_vector(vector_32);

//4.插入一个范围的元素
//template <class InputIterator>
//void insert(const_iterator pos, InputIterator first, InputIterator last);

vector<int> vector_40{99, 100, 101};
vector<int> vector_41{0, 1, 2, 3, 4, 5};
vector_41.insert(vector_41.begin() + 2, vector_40.begin(), vector_40.end()); // 在索引2的位置插入 vector_40 的所有元素
cout << "vector_41:";
print_vector(vector_41);

int a[3] = {100, 200, 300};
vector<int> vector_42{0, 1, 2, 3, 4, 5};
vector_42.insert(vector_42.begin() + 2, a, a + 3); // 在索引2的位置插入数组 a 的所有元素，左闭右开
cout << "vector_42:";
print_vector(vector_42);

//5.插入初始化列表中的元素（C++11 及以上）
//void insert(const_iterator pos, initializer_list<T> ilist);

vector<int> vector_51 = {0, 1, 2, 3, 4, 5};
vector_51.insert(vector_51.begin() + 3, {99, 100, 101}); // 在索引3的位置插入初始化列表中的元素
cout << "vector_51:";
print_vector(vector_51);

printf("--------------------end----------------------\n");
```

测试结果:

```log
--------------------begain-------------------
vector_11: 0 1 2 3 4 5 6 7 8 9 10 10 10 

vector_21: 10 0 1 2 3 4 5 6 7 8 9 
vector_22: 0 1 2 3 4 5 6 7 8 9 10 
vector_31: 10 10 10 0 1 2 3 4 5 6 7 8 9 
vector_32: 0 1 2 30 30 30 3 4 5 6 7 8 9 
vector_41:0 1 99 100 101 2 3 4 5 
vector_42:0 1 100 200 300 2 3 4 5 
vector_51:0 1 2 99 100 101 3 4 5 
--------------------end----------------------
```

# 六、vector的元素删除

函数原型：

```cpp
pop_back(); //删除最后一个元素
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator begin,const_iterator end); //删除迭代器从begin到end之间的元素
clear(); //删除容器中所有元素
```

使用示例:

```cpp
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
void print_vector(vector<int> &v)
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
    print_vector(v_test);

    // 使用 erase 删除首个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin());
    cout << "使用 erase 删除首个元素，打印v_test: ";
    print_vector(v_test);

    // 使用 erase 删除第二个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin() + 1);
    cout << "使用 erase 删除第二个元素，打印v_test: ";
    print_vector(v_test);

    // 使用 erase 删除全部元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin(), v_test.end());
    cout << "使用 erase 删除全部元素，打印v_test: ";
    print_vector(v_test);

    // 使用 erase 删除前三个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin(), v_test.begin() + 3);
    cout << "使用 erase 删除前三个元素，打印v_test: ";
    print_vector(v_test);

    // 使用 erase 删除后三个元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.end() - 3, v_test.end());
    cout << "使用 erase 删除后三个元素，打印v_test: ";
    print_vector(v_test);

    // 使用 erase 删除前三个后三个之外的元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.erase(v_test.begin() + 3, v_test.end() - 3);
    cout << "使用 erase 删除前三个后三个之外的元素，打印v_test: ";
    print_vector(v_test);

    // 使用 clear 删除全部元素
    v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v_test.clear(); // 调用7，清空所有元素
    cout << "使用 clear 删除全部元素，打印v_test: ";
    print_vector(v_test);

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






# 一、swap函数

函数原型:

```C++
swap(v); //容器v和当前容器互换
```

使用示例:

```cpp
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
void print_vector(vector<int> &v)
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
    vector<int> v_test1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v_test2 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "交换前：" << endl;
    print_vector(v_test1);
    print_vector(v_test2);
    cout << "交换后：" << endl;
    v_test1.swap(v_test2); // 调用互换函数
    print_vector(v_test1);
    print_vector(v_test2);

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
交换前：
0 1 2 3 4 5 6 7 8 9 
9 8 7 6 5 4 3 2 1 0 
交换后：
9 8 7 6 5 4 3 2 1 0 
0 1 2 3 4 5 6 7 8 9 
--------------------end----------------------
```



































# 二、vector 迭代器失效的原因

## 1.内存重新分配

当vector插入元素(如 push_back, insert)时，若当前容量不足vector会申请一块更大的内存，将旧元素拷贝到新内存，并释放就内存。此时：所有迭代器，指针和引用都会失效(因为它们指向旧的内存)。



测试示例:

```cpp
void test1()
{
    cout << "test1: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = v_test.begin();

    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl
         << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it1 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl
         << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it2 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl
         << endl;


    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it3 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl;
    cout << "addr of it3: " << &*it3 << endl
         << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    v_test.push_back(0);
    auto it4 = v_test.begin();

    cout << "push_back 0: " << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it: " << &*it << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl;
    cout << "addr of it3: " << &*it3 << endl;
    cout << "addr of it4: " << &*it4 << endl
         << endl;

    v_test.resize(10);
    vector<int>(v_test).swap(v_test);
    auto it5 = v_test.begin();

    cout << "swap v_test: ";
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "addr of it5: " << &*it5 << endl
         << endl;
    
    v_test.reserve(20);
    auto it6 = v_test.begin();

    cout << "addr of it6: " << &*it6 << endl
         << endl;

    v_test.reserve(30);
    auto it7 = v_test.begin();

    cout << "addr of it7: " << &*it7 << endl
         << endl;
}
```



测试结果:

```log
test1: 
size = 10
capacity = 10
addr of it: 0x55fe3e0552c0

push_back 0: 
size = 11
capacity = 20
addr of it: 0x55fe3e0552c0
addr of it1: 0x55fe3e0552f0

push_back 0: 
size = 21
capacity = 40
addr of it: 0x55fe3e0552c0
addr of it1: 0x55fe3e0552f0
addr of it2: 0x55fe3e055350

push_back 0: 
size = 41
capacity = 80
addr of it: 0x55fe3e0552c0
addr of it1: 0x55fe3e0552f0
addr of it2: 0x55fe3e055350
addr of it3: 0x55fe3e055400

push_back 0: 
size = 81
capacity = 160
addr of it: 0x55fe3e0552c0
addr of it1: 0x55fe3e0552f0
addr of it2: 0x55fe3e055350
addr of it3: 0x55fe3e055400
addr of it4: 0x55fe3e055550

swap v_test: size = 10
capacity = 10
addr of it5: 0x55fe3e0552c0

addr of it6: 0x5637910e02f0

addr of it7: 0x5637910e07e0
```

从测试结果可以看出，每次扩容都会导致 v_test.begin() 的地址发生变化，同时说明，原地址失效。













## 2.元素位置变动

当删除元素(如erase，pop_back)或在中间插入元素时，元素的位置可能发生移动：

被删除元素之后的迭代器会失效（因为后续元素会向前移动）



测试示例:

```cpp
void test2()
{
    cout << "test2: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it1 = v_test.begin() + 5; // 指向 5

    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "it1 = " << *it1 << endl;
    cout << "addr of it1: " << &*it1 << endl
         << endl;

    v_test.erase(v_test.begin() + 1); // 删除 1
    auto it2 = v_test.begin() + 5;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl;
    cout << "it1 = " << *it1 << endl;
    cout << "it2 = " << *it2 << endl;
    cout << "addr of it1: " << &*it1 << endl;
    cout << "addr of it2: " << &*it2 << endl
         << endl;
}
```



测试结果:

```log
test2: 
size = 10
capacity = 10
it1 = 5
addr of it1: 0x56396b34a2d4

size = 9
capacity = 10
it1 = 6
it2 = 6
addr of it1: 0x56396b34a2d4
addr of it2: 0x56396b34a2d4
```

删除数据后，后面的数据补齐删除的数据，迭代器保存的地址不变，然而迭代器指向的值已经改变。




本文链接：https://blog.csdn.net/m0_37251750/article/details/100071023

————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/m0_37251750/article/details/100071023



本文链接：https://blog.csdn.net/fuxiaoxiaoyue/article/details/84847967



 vector 迭代器失效问题

迭代器的主要作用就是让算法能够不用关心底层数据结构，其底层实际就是一个指针，或者是对指针进行了封装
比如：vector的迭代器就是原生态指针 T*。因此迭代器失效，实际就是迭代器底层对应指针所指向的 空间被销毁了，而使用一块已经被释放的空间，造成的后果是程序崩溃(即如果继续使用已经失效的迭代器，程序可能会崩溃)。
对于vector可能会导致其迭代器失效的操作：
会引起其底层空间改变的操作，都有可能是迭代器失效 ，比如： resize、reserve、insert、assign、 push_back 等
指定位置元素的删除操作  erase 
 erase 删除 pos 位置元素后，pos位置之后的元素会往前搬移，没有导致底层空间的改变，理论上讲迭代器不应该会失效，但是：如果pos刚好是最后一个元素，删完之后pos刚好是end的位置，而end位置是没有元素的，那么pos就失效了。因此删除vector中任意位置上元素时，vs就认为该位置迭代器失效了。
划重点了哟！！！ 迭代器失效解决办法：在使用前，对迭代器重新赋值即可。
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/chen_hard/article/details/119759216












# 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。

1. https://blog.csdn.net/qq_52324409/article/details/121000029
2. https://blog.csdn.net/hffh123/article/details/139151432
3. https://blog.csdn.net/HH_KZ1314/article/details/145585503











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
