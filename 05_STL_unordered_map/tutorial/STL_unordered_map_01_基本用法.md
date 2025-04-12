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



# 一、unordered_map的构造函数

函数原型:

```C++
unordered_map<T1, T2> mp; // 构造一个空容器
unordered_map<T1, T2> mp2(const unordered_map &mp1); // 拷贝构造一个容器
unordered_map<T1, T2> mp2(mp1.begin(), mp1.end()); // 使用迭代器区间构造一个容器，注意左闭右开
```

使用示例:

```c++








=
```

测试结果:

```tex
====
```





































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
1. ===
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
