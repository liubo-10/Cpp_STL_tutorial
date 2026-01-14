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



## 💞️ vector 数据量和容量基本函数

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
max_size();     //返回容器中元素的个数 ### 容器所能容纳的最大元素数目
```

容器所能容纳的最大元素数目，这是系统或者库所实施的限制。但是容器不一定保证能达到该大小，有可能在还未达到该大小的时候，就已经无法继续分配任何的空间了。

## 💞️ resize() 对数据量和容量的操作

---

函数原型：

```c++
//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num);

//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);
```



使用示例:

```c++
void resize_test(){
    cout << "resize_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    vector<int> v_test1 = v_test;
    v_test1.resize(5);
    cout << "resize 5: ";
    print_vector(v_test1);
    cout << "size = " << v_test1.size() << endl;
    cout << "capacity = " << v_test1.capacity() << endl << endl;

    vector<int> v_test2 = v_test;
    v_test2.resize(20);
    cout << "resize 20: ";
    print_vector(v_test2);
    cout << "size = " << v_test2.size() << endl;
    cout << "capacity = " << v_test2.capacity() << endl << endl;

    vector<int> v_test3 = v_test;
    v_test3.resize(20, 9);
    cout << "resize 20,9: ";
    print_vector(v_test3);
    cout << "size = " << v_test3.size() << endl;
    cout << "capacity = " << v_test3.capacity() << endl << endl;
}
```

测试结果:

```tex
resize_test: 
初始数据: 0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10

resize 5: 0 1 2 3 4 
size = 5
capacity = 10

resize 20: 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 0 0 0 0 
size = 20
capacity = 20

resize 20,9: 0 1 2 3 4 5 6 7 8 9 9 9 9 9 9 9 9 9 9 9 
size = 20
capacity = 20
```



# 三、reserve对vector数据量和容量的操作

函数原型：

```c++
reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问
```



使用示例:

```c++
void reserve_test(){
    cout << "reserve_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    // reserve 是保留的意思，reserve的值小于size也不会使元素消失，此时的capacity==size
    vector<int> v_test1 = v_test;
    v_test1.reserve(5); // capacity == size == 10
    cout << "reserve 5: ";
    print_vector(v_test1);
    cout << "size = " << v_test1.size() << endl;
    cout << "capacity = " << v_test1.capacity() << endl << endl;

    vector<int> v_test2 = v_test;
    v_test2.reserve(30); // 使得capacity=30，里面的元素不会改变
    cout << "reserve 30: ";
    print_vector(v_test2);
    cout << "size = " << v_test2.size() << endl;
    cout << "capacity = " << v_test2.capacity() << endl << endl;

}
```

测试结果:

```tex
reserve_test: 
初始数据: 0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10

reserve 5: 0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10

reserve 30: 0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 30
```

reserve 是保留的意思，reserve的值小于size也不会使元素消失，此时的capacity==size



# 三、clear对vector数据量和容量的操作

函数原型：

```c++
clear(); //删除容器中所有元素
```



使用示例:

```c++
void clear_test(){
    cout << "clear_test: " << endl;
    vector<int> v_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始数据: ";
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;

    // clear是清空，不是置零，清空所有元素，所以size为0，但是capacity不变，
    v_test.clear();
    cout << "clear: ";
    print_vector(v_test);
    cout << "empty = " << v_test.empty() << endl;
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl << endl;
}
```

测试结果:

```tex
clear_test: 
初始数据: 0 1 2 3 4 5 6 7 8 9 
size = 10
capacity = 10

clear: 
empty = 1
size = 0
capacity = 10
```

clear 只清零大小，不改变容量



# 三、push_back对vector数据量和容量的操作

函数原型：

```c++
push_back(ele); //尾部插入元素ele
```



使用示例:

```c++
void push_back_test()
{
    cout << "push_back_test: " << endl;
    vector<int> v_test;
    cout << "未初始化vector: ";
    print_vector(v_test);
    cout << "size = " << v_test.size() << endl;
    cout << "capacity = " << v_test.capacity() << endl
         << endl;

    cout << "添加10个元素: " << endl;
    int *pStart = &v_test[0];
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        v_test.push_back(i);
        cout << "capacity: " << v_test.capacity() << "  size: " << v_test.size() << endl;
        if (pStart != &v_test[0])
        {
            pStart = &v_test[0];
            count++;
        }
    }
    cout << "count:" << count << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    cout << endl;

    // 添加1个元素
    cout << "size = capacity\n";
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl;

    cout << "insert one element\n";
    v_test.push_back(0);
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl
         << endl;

    v_test.reserve(100);
    cout << "reserve capacity 100\n";
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl;

    // 将容量用完
    while (v_test.size() != v_test.capacity())
    {
        v_test.push_back(0);
    }
    cout << endl;

    // 添加1个元素
    cout << "size = capacity\n";
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl;

    cout << "insert one element\n";
    v_test.push_back(0);
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl
         << endl;

    v_test.resize(50);
    cout << "resize size 50\n";
    cout << "capacity:" << v_test.capacity() << "  size:" << v_test.size() << endl
         << endl;

    vector<int> v1;
    // 预先开辟空间
    v1.reserve(100000);

    pStart = &v1[0];
    count = 0;
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
        if (pStart != &v1[0])
        {
            pStart = &v1[0];
            count++;
        }
    }
    cout << "count:" << count << endl;
}
```

测试结果:

```tex
push_back_test: 
未初始化vector: 
size = 0
capacity = 0

添加10个元素: 
capacity: 1  size: 1
capacity: 2  size: 2
capacity: 4  size: 3
capacity: 4  size: 4
capacity: 8  size: 5
capacity: 8  size: 6
capacity: 8  size: 7
capacity: 8  size: 8
capacity: 16  size: 9
capacity: 16  size: 10
count:5

size = capacity
capacity:16  size:16
insert one element
capacity:32  size:17

reserve capacity 100
capacity:100  size:17

size = capacity
capacity:100  size:100
insert one element
capacity:200  size:101

resize size 50
capacity:200  size:50

count:0
```

当 capacity 不够用时扩容当前值的2倍





# 三、swap对vector数据量和容量的操作

函数原型：

```c++
swap(v); //容器v和当前容器互换
```



使用示例:

```c++
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

```tex
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
