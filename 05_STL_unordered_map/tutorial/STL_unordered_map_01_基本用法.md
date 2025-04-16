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


> # STL_unordered_map_01_基本用法

unordered_map是存储<key, value>键值对的关联式容器，其允许通过keys快速的索引到与其对应的value。其存储结构为哈希；元素的存储并未按照特定的顺序，而是被组织到桶中，在哪个桶中取决于其散列值。

使用时包含头文件:

```C++
#include <unordered_map>
```



# 一、unordered_map的构造函数

函数原型:

```C++
unordered_map<T1, T2> mp; // 构造一个空容器
unordered_map<T1, T2> mp(n); // 初始桶数量为 n
unordered_map<T1, T2> mp = {{n1, m1},{n2, m2}}; // 列表构造函数
unordered_map<T1, T2> mp2(const unordered_map &mp1); // 拷贝构造一个容器
unordered_map<T1, T2> mp2(mp1.begin(), mp1.end()); // 使用迭代器区间构造一个容器，注意左闭右开
unordered_map<T1, T2> mp2 = move(mp1); // 移动构造函数
```

使用示例:

```c++
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件
#include <iostream> // 包含输入和输出操作
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

// unordered_map 的遍历
void print_unordered_map(unordered_map<int, string> &mp)
{
    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");
    unordered_map<int, string> first; // 构造一个空容器
    first = {{1, "apple"}, {2, "banana"}, {3, "orange"}, {4, "pear"}};

    unordered_map<int, string> second(5);                             // 初始桶数量为 5
    unordered_map<int, string> third = {{1, "apple"}, {2, "banana"}}; // 列表构造函数
    unordered_map<int, string> forth(first);                          // 拷贝构造一个容器
    unordered_map<int, string> fifth(first.begin(), first.end());     // 使用迭代器区间构造一个容器
    unordered_map<int, string> sixth = move(first);                   // 移动构造函数

    cout << "first: " << endl;
    print_unordered_map(first);

    cout << "second: " << endl;
    print_unordered_map(second);

    cout << "third: " << endl;
    print_unordered_map(third);

    cout << "forth: " << endl;
    print_unordered_map(forth);

    cout << "fifth: " << endl;
    print_unordered_map(fifth);

    cout << "sixth: " << endl;
    print_unordered_map(sixth);

    cout << "first: " << endl;
    print_unordered_map(first);

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
4:pear 3:orange 2:banana 1:apple 
second: 

third: 
2:banana 1:apple 
forth: 
4:pear 3:orange 2:banana 1:apple 
fifth: 
1:apple 2:banana 3:orange 4:pear 
sixth: 
4:pear 3:orange 2:banana 1:apple 
first: 

--------------------end----------------------
```

从结果看打印输出是无序的，同时证明了，在内部,unordered_map没有对<kye, value>按照任何特定的顺序排序。

使用移动构造函数会把原数据清空。



# 二、unordered_map的遍历

方法1：

```c++
void print_unordered_map(unordered_map<int, string> &mp)
{
    for (unordered_map<int, string>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << ":" << it->second << " ";
    }
    cout << endl;
}
```

迭代器iterator中的begin和end函数是左闭右开的区间。



方法2：

```c++
void print_unordered_map(unordered_map<int, string> &mp)
{
    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;
}
```



# 三、unordered_map的元素访问

函数原型：

```c++
operator[key];  //返回索引 key 所指的值
front();        //返回容器中第一个数据元素
back();         //返回容器中最后一个数据元素
```

使用示例:

```c++
void get_element_test()
{
    cout << "get_element_test: " << endl;

    unordered_map<int, string> mp;
    mp = {{1, "apple"}, {2, "banana"}, {3, "orange"}, {4, "pear"}};

    cout << 1 << ":" << mp[1] << " " << endl;
    cout << 2 << ":" << mp[2] << " " << endl;

    unordered_map<int, string>::iterator it;

    it = mp.begin();
    cout << it->first << ":" << it->second << " " << endl;
    it++;
    cout << it->first << ":" << it->second << " " << endl;
    it++;
    cout << it->first << ":" << it->second << " " << endl;

    // it = it - 1; // 报错没有减法
}
```

测试结果:

```log
--------------------begain-------------------
get_element_test: 
1:apple 
2:banana 
4:pear 
3:orange 
2:banana 
--------------------end----------------------
```

需要注意的是 mp.begin()打印的是 4:pear 并不是 1:apple。 unordered_map<int, string>::iterator it，迭代器并没有减法运算。

# 四、unordered_map的元素插入

函数原型：

```c++
unordered_map<T1, T2> mp;
pair<T1, T2> p(m, n);
mp.insert(p);                  // 1.借助 pair 插入元素
mp.insert(pair<T1, T2>(m, n)); // 2.借助 pair 插入元素
mp.insert(make_pair(m, n));    // 3.用make_pair函数模板插入
mp[m] = n;                     // 4.使用[]运算符重载函数进行插入
mp.insert({m, n});             // 5.使用 {} 插入元素
```



使用示例:

```c++
void insert_test()
{
    cout << "insert_test: " << endl;
    unordered_map<int, string> mp; // 构造一个空容器

    // 1：借助 pair 构造对象插入元素
    pair<int, string> pr(1, "apple");
    mp.insert(pr);
    print_unordered_map(mp);

    // 2：借助 pair 构造匿名对象插入元素
    mp.insert(pair<int, string>(2, "banana"));
    print_unordered_map(mp);

    // 3：调用make_pair函数模板插入元素
    mp.insert(std::make_pair(3, "orange"));
    print_unordered_map(mp);

    // 4：使用[]运算符重载函数插入元素
    mp[4] = "pear";
    print_unordered_map(mp);

    // 5：使用{}插入元素
    mp.insert({5, "lemon"});
    print_unordered_map(mp);
}
```

测试结果:

```log
--------------------begain-------------------
insert_test: 
1:apple 
2:banana 1:apple 
3:orange 2:banana 1:apple 
4:pear 3:orange 2:banana 1:apple 
5:lemon 4:pear 3:orange 2:banana 1:apple 
--------------------end----------------------
```



# 五、vector的元素删除

函数原型：

```c++
unordered_map<T1, T2> mp;
mp.erase(key); // 1：根据 key 删除
unordered_map<int, string>::iterator it;
mp.erase(it); // 2：根据迭代器位置删除
```

使用示例:

```c++
void get_element_test()
-
}
```

测试结果:

```log
--------------------begain-------------------
get_el--end----------------------
```

-



































# unordered_map的容量

















| bool empty() const  | 检测是否为空     |
| ------------------- | ---------------- |
| size_t size() const | 获取有效元素个数 |















# unordered_map的修改操作





| insert                    | 向容器中插入键值对       |
| ------------------------- | ------------------------ |
| erase                     | 删除容器中的键值对       |
| void clear                | 清空容器中的有效元素个数 |
| void swap(unordered map&) | 交换两个容器中的元素     |



















# unordered_map 的桶操作







| size_t bucket_count() const        | 返回哈希桶中桶的总个数      |
| ---------------------------------- | --------------------------- |
| size_t bucket_size(size_t n) const | 返回n号桶中有效元素的总个数 |
| size_t bucket(const K& key)        | 返回元素key所在的桶号       |























# unordered_map的查询









| iterator find(const K& key) | 返回key在哈希桶中的位置               |
| --------------------------- | ------------------------------------- |
| size_t count(const K& key)  | 返回哈希桶中关键码为key的键值对的个数 |







注意：unordered_map中key是不能重复的，因此count函数的返回值最大为1。































unordered_map是存储<key, value>键值对的关联式容器，其允许通过keys快速的索引到与其对应的value。
在unordered_map中，键值通常用于惟一地标识元素，而映射值是一个对象，其内容与此键关联。键和映射值的类型可能不同。
在内部,unordered_map没有对<kye, value>按照任何特定的顺序排序, 为了能在常数范围内找到key所对应的value，unordered_map将相同哈希值的键值对放在相同的桶中。
unordered_map容器通过key访问单个元素要比map快，但它通常在遍历元素子集的范围迭代方面效率较低。
unordered_maps实现了直接访问操作符(operator[])，它允许使用key作为参数直接访问value。
它的迭代器至少是前向迭代器。
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/2301_78029441/article/details/143855839

















unordered_map的接口说明

在使用unordered_map之前，需要包含<unordered_map>头文件

定义空的unordered_map：
可以简单地定义一个指定类型的unordered_map。例如，定义一个存储int类型元素的unordered_map：

使用insert方法插入单个元素：
insert方法返回一个pair类型的值。其中pair的first是一个迭代器，指向插入后的键 - 值对（如果键已经存在，则指向已存在的键 - 值对）；second是一个bool值，表示插入是否成功。
使用[]运算符插入或更新键 - 值对如果键不存在，[]运算符会插入一个新的键 - 值对，并返回对应的值的引用；如果键已经存在，则返回该键对应的值的引用，并且可以通过这个引用修改值

使用find方法查找元素：
find方法返回一个迭代器，如果找到元素，则指向该元素；如果未找到，则返回end()迭代器。

使用erase方法删除单个元素：
可以通过指定元素的值或者迭代器来删除元素。如果通过值删除，会删除第一个匹配的元素。

可以使用迭代器来遍历unordered_map中的元素。由于unordered_map中的元素是无序的，所以遍历的顺序是不确定的。
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：







































# 六、总结

以上就是今天要讲的内容，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
1. https://blog.csdn.net/m0_72532428/article/details/143838161
2. 

https://blog.csdn.net/2301_78029441/article/details/143855839

























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
