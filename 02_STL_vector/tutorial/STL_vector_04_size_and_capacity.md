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


> # STL_vector_04_size_and_capacity



# 一、vector数据量和容量的获取

```c++
size();     //返回容器中元素的个数
capacity(); //容器的容量
empty();    //判断容器是否为空
```

## size

作用：返回vector中元素的个数。

【注意】vector中保存的实际对象的数量，不一定等于它的存储空间大小（容量）。

## capacity

作用：返回当前为vector分配的存储空间大小（容量），以元素个数表示。

【注意】这个容量不一定等于向量的大小。它可以相等或更大，额外的空间允许容纳增长，而不需要在每次插入时重新分配。这个容量并没有假设向量的大小有限制。当此容量耗尽并且需要更多容量时，容器会自动对其进行扩展(重新分配其存储空间)。vector的大小的理论极限由成员max_size给出。可以通过调用vector::reserve成员显式地改变vector的容量。



## 二、resize对vector大小容量的操作

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



# 三、reserve对vector大小容量的操作

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



# 三、clear对vector大小容量的操作

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
