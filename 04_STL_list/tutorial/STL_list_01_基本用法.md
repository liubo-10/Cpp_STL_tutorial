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
=
```

测试结果:

```log
=
```



# 二、vector的遍历

方法1：

```c++
=
```

迭代器iterator中的begin和end函数是左闭右开的区间。



方法2：

```c++
=
```



# 三、vector的赋值操作

函数原型：

```c++
=
```

assign: 将新内容赋给vector，替换其当前内容，并相应地修改其大小。



使用示例:

```c++
=
```

测试结果:

```log
=
```

# 四、vector的元素访问

函数原型：

```c++
=
```



使用示例:

```c++
=
```

测试结果:

```tex
=
```



# 五、vector的元素插入

函数原型：

```c++
=
```

push_back: 在vector当前最后一个元素的末尾添加一个新元素。val的内容被复制(或移动)到新元素中。

将容器大小增加了1，当且仅当新vector大小 > 当前vector容量时，会自动重新分配存储空间。



使用示例:

```c++
=
```

测试结果:

```log
=
```

# 六、vector的元素删除

函数原型：

```c++
=
```

使用示例:

```c++
=
```

测试结果:

```log
=
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













