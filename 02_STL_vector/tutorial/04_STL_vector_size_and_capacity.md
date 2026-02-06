# 04_STL_vector_size_and_capacity

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



## 💞️ vector 大小和容量基本函数

---

### ✨ size()

```cpp
size();     //返回容器中元素的个数
```

作用：返回vector中元素的个数。

注意: vector中保存的实际对象的数量，不一定等于它的存储空间大小（容量）。


### ✨ capacity()

```cpp
capacity(); //容器的容量
```


作用：返回当前为vector分配的存储空间大小（容量），以元素个数表示。

【注意】这个容量不一定等于向量的大小。它可以相等或更大，额外的空间允许容纳增长，而不需要在每次插入时重新分配。这个容量并没有假设向量的大小有限制。当此容量耗尽并且需要更多容量时，容器会自动对其进行扩展(重新分配其存储空间)。vector的大小的理论极限由成员max_size给出。可以通过调用vector::reserve成员显式地改变vector的容量。

### ✨ empty()

```cpp
empty();    //判断容器是否为空
```

作用：判断向量是否为空

### ✨ max_size()

```cpp
max_size();     //返回容器所能容纳的最大元素数目
```

容器所能容纳的最大元素数目，这是系统或者库所实施的限制。但是容器不一定保证能达到该大小，有可能在还未达到该大小的时候，就已经无法继续分配任何的空间了。

## 💞️ resize() 对大小和容量的影响

---

函数原型：

```cpp
//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num);

//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);
```



使用示例:

```cpp
printf("--------------------begain-------------------\n");

vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

cout << "vector_11:" << endl;
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl;
cout << "max_size = " << vector_11.max_size() << endl << endl;

vector<int> vector_12(vector_11);
vector_12.resize(5);
cout << "vector_12:" << endl;
print_vector(vector_12);
cout << "size = " << vector_12.size() << endl;
cout << "capacity = " << vector_12.capacity() << endl;
cout << "max_size = " << vector_12.max_size() << endl << endl;

vector<int> vector_13(vector_11);
vector_13.resize(20);
cout << "vector_13:" << endl;
print_vector(vector_13);
cout << "size = " << vector_13.size() << endl;
cout << "capacity = " << vector_13.capacity() << endl;
cout << "max_size = " << vector_13.max_size() << endl << endl;

vector<int> vector_14(vector_11);
vector_14.resize(20, 9);
cout << "vector_14:" << endl;
print_vector(vector_14);
cout << "size = " << vector_14.size() << endl;
cout << "capacity = " << vector_14.capacity() << endl;
cout << "max_size = " << vector_14.max_size() << endl << endl;

printf("--------------------end----------------------\n");
```

测试结果:

```log
--------------------begain-------------------
vector_11:
0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10
max_size = 2305843009213693951

vector_12:
0 1 2 3 4 
size = 5
capacity = 10
max_size = 2305843009213693951

vector_13:
0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 0 0 0 0 
size = 20
capacity = 20
max_size = 2305843009213693951

vector_14:
0 1 2 3 4 5 6 7 8 9 9 9 9 9 9 9 9 9 9 9 
size = 20
capacity = 20
max_size = 2305843009213693951

--------------------end----------------------
```

测试结果分析
对于刚初始化的 vector_11 size 和 capacity 是一样的
vector_12 resize(5)之后，只减少了元素数量的大小，容量保持不变。vector_12 中原来的元素被丢弃。
vector_13 resize(20)之后，元素数量的大小超过了原来容量，容量增大到和 size 一致。vector_13 中原来的元素保持不变，都出来的位置用0补全。
vector_14 与 vector_13 的操作相似，不同的是原来的元素保持不变，都出来的位置用9补全。
max_size 是系统或者库所实施的限制，系统未变库未变所以大小恒定。



## 💞️ reserve() 对大小和容量的影响

---

函数原型：

```cpp
reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问
```



使用示例:

```cpp
printf("--------------------begain-------------------\n");

vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

cout << "vector_11:" << endl;
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl;
cout << "max_size = " << vector_11.max_size() << endl << endl;

vector<int> vector_12(vector_11);
vector_12.reserve(5); // capacity == size == 10
cout << "vector_12:" << endl;
print_vector(vector_12);
cout << "size = " << vector_12.size() << endl;
cout << "capacity = " << vector_12.capacity() << endl;
cout << "max_size = " << vector_12.max_size() << endl << endl;

vector<int> vector_13(vector_11);
vector_13.reserve(30); // 使得capacity=30，里面的元素不会改变
cout << "vector_13:" << endl;
print_vector(vector_13);
cout << "size = " << vector_13.size() << endl;
cout << "capacity = " << vector_13.capacity() << endl;
cout << "max_size = " << vector_13.max_size() << endl << endl;

printf("--------------------end----------------------\n");
```

测试结果:

```log
--------------------begain-------------------
vector_11:
0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10
max_size = 2305843009213693951

vector_12:
0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10
max_size = 2305843009213693951

vector_13:
0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 30
max_size = 2305843009213693951

--------------------end----------------------
```

结果分析：
vector_12 的测试可知 ，reserve 的值小于size也不会使元素消失，此时的capacity\==size
vector_13 的测试表明，reserve大于 size 也不会是元素增加

## 💞️ clear() 对大小和容量的影响

---

函数原型：

```cpp
clear(); //删除容器中所有元素
```



使用示例:

```cpp
printf("--------------------begain-------------------\n");

vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

cout << "before clear: " << endl;
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "empty = " << vector_11.empty() << endl;
cout << "capacity = " << vector_11.capacity() << endl;
cout << "max_size = " << vector_11.max_size() << endl << endl;

vector_11.clear();
cout << "after clear: " << endl;
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "empty = " << vector_11.empty() << endl;
cout << "capacity = " << vector_11.capacity() << endl;
cout << "max_size = " << vector_11.max_size() << endl << endl;

printf("--------------------end----------------------\n");
```

测试结果:

```log
--------------------begain-------------------
before clear: 
0 1 2 3 4 5 6 7 8 9 
size = 10
empty = 0
capacity = 10
max_size = 2305843009213693951

after clear: 

size = 0
empty = 1
capacity = 10
max_size = 2305843009213693951

--------------------end----------------------
```

结果分析：
clear 只清零大小，不改变容量
clear是清空，不是置零，清空所有元素，所以size为0，但是capacity不变，

## 💞️ push_back() 对大小和容量的影响 
---

函数原型：

```cpp
push_back(ele); //尾部插入元素ele
```



使用示例:

```cpp
printf("--------------------begain-------------------\n");

vector<int> vector_11;
cout << "vector_11:" << endl;
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

cout << "push_back 10 elements:" << endl;
int *pStart = &vector_11[0];
int count = 0;
for (int i = 0; i < 10; ++i) {
    vector_11.push_back(i);
    cout << "push_back(" << i << ")" << endl;
    print_vector(vector_11);
    cout << "size = " << vector_11.size() << endl;
    cout << "capacity = " << vector_11.capacity() << endl << endl;

    if (pStart != &vector_11[0]) {
        pStart = &vector_11[0];
        count++;
    }
}
cout << "adress change count:" << count << endl << endl;

cout << "Use up the capacity: " << endl;
while (vector_11.size() != vector_11.capacity()) {
    vector_11.push_back(0);
}
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

cout << "push_back 1 element: " << endl;
vector_11.push_back(1);
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

vector_11.reserve(100);
cout << "reserve capacity 100" << endl;
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

cout << "Use up the capacity: " << endl;
while (vector_11.size() != vector_11.capacity()) {
    vector_11.push_back(2);
}
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

// 再添加1个元素
cout << "push_back 1 element" << endl;
vector_11.push_back(3);
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

cout << "resize(50):" << endl;
vector_11.resize(50);
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

vector<int> vector_12;
// 预先开辟空间
vector_12.reserve(100000);

cout << "push_back 100000 elements:" << endl;
pStart = &vector_12[0];
count = 0;
for (int i = 0; i < 100000; ++i) {
    vector_12.push_back(i);
    if (pStart != &vector_12[0]) {
        pStart = &vector_12[0];
        count++;
    }
}
cout << "adress change count:" << count << endl << endl;

printf("--------------------end----------------------\n");
```

测试结果:

```log
--------------------begain-------------------
vector_11:
size = 0
capacity = 0

push_back 10 elements:
push_back(0)
0 
size = 1
capacity = 1

push_back(1)
0 1 
size = 2
capacity = 2

push_back(2)
0 1 2 
size = 3
capacity = 4

push_back(3)
0 1 2 3 
size = 4
capacity = 4

push_back(4)
0 1 2 3 4 
size = 5
capacity = 8

push_back(5)
0 1 2 3 4 5 
size = 6
capacity = 8

push_back(6)
0 1 2 3 4 5 6 
size = 7
capacity = 8

push_back(7)
0 1 2 3 4 5 6 7 
size = 8
capacity = 8

push_back(8)
0 1 2 3 4 5 6 7 8 
size = 9
capacity = 16

push_back(9)
0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 16

adress change count:5

Use up the capacity: 
0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 
size = 16
capacity = 16

push_back 1 element: 
0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 
size = 17
capacity = 32

reserve capacity 100
0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 
size = 17
capacity = 100

Use up the capacity: 
0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
size = 100
capacity = 100

push_back 1 element
0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 
size = 101
capacity = 200

resize(50):
0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
size = 50
capacity = 200

push_back 100000 elements:
adress change count:0

--------------------end----------------------
```

结果分析：
使用 push_back 在 vector 后面添加元素时，当 capacity 不够用时会扩容到当前值的2倍。当 capacity 够用时，不会改变。





# 三、swap对vector数据量和容量的操作

函数原型：

```cpp
swap(v); //容器v和当前容器互换
```



使用示例:

```cpp
void swap_test()
{
    cout << "swap_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;

    v_test.reserve(30); // 使得capacity=30，里面的元素不会改变
    cout << "reserve 30: ";
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;

    // vector<int>(v_test) 是创建一个匿名对象，并拷贝v_test的数据
    // 以此匿名对象与v_test交换，交换完后系统自动删除匿名对象
    vector<int>(v_test).swap(v_test);

    cout << "swap v_test: ";
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;
}
```

测试结果:

```log
swap_test: 
初始数据: 0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10

reserve 30: 0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 30

swap v_test: 0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10
```

当 swap 能够收缩vestor容量

























# 六、总结

以上就是今天要讲的内容，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
一、 https://blog.csdn.net/as480133937/article/details/123740365
二、 https://blog.csdn.net/weibo1230123/article/details/80210097
三、 LwIP应用开发实战指南：基于STM32









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
