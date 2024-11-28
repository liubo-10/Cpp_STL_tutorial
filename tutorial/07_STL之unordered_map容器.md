* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



# c++ unordered_map

在C++98中，STL提供了底层为红黑树结构的一系列关联式容器，在查询时效率可达到O(logN) ，即最差情况下需要比较红黑树的高度次，当树中的节点非常多时，查询效率也不理想。最好的查询是，进行很少的比较次数就能够将元素找到，因此在C++11中，STL又提供了4个unordered系列的关联式容器，这四个容器与红黑树结构的关联式容器使用方式基本类似，只是其底层结构不同。








unordered_map与map的用法基本一直，最大的区别在于：map的key是有序的，而unordered_map的key为无序。



























对比map与unordered_map，两者的区别如下：
实现方式：unordered_map为哈希表，map为红黑树。
查找操作：unordered_map 平均为O(1)，最差为O(n), map为log(n)。
插入，删除操作：unordered_map与查找一样，map为log(n)+平衡二叉树所用的时间。
适用场景：unordered_map适用查找频率高，而map适合要求key有序的场景。















1、unordered_map是存储<key, value>键值对的关联式容器，其允许通过keys快速的索引到与其对应的value。
2、在unordered_map中，键值通常用于惟一地标识元素，而映射值是一个对象，其内容与此键关联。键和映射值的类型可能不同。
3、在内部,unordered_map没有对<kye, value>按照任何特定的顺序排序, 为了能在常数范围内找到key所对应的value，unordered_map将相同哈希值的键值对放在相同的桶中。
4、unordered_map容器通过key访问单个元素要比map快，但它通常在遍历元素子集的范围迭代方面效率较低。
5、unordered_maps实现了直接访问操作符(operator[])，它允许使用key作为参数直接访问value。
6、它的迭代器至少是前向迭代器。







unordered_map的构造方式

        1、构造一个空容器：
    
    unordered_map<string, int> mp1;
    
        2、拷贝构造一个容器：
    
    unordered_map<string, int> mp2(mp1);
    
        3、使用迭代器区间构造一个容器：
    
    unordered_map<string, int> mp2(mp1.begin(), mp1.end());















## unordered_map的函数接口说明



1、unordered_map的容量

| **函数声明**        | **功能介绍**     |
| ------------------- | ---------------- |
| bool empty() const  | 检测是否为空     |
| size_t size() const | 获取有效元素个数 |



2、unordered_map的迭代器



函数声明	功能介绍
begin	赶回unordered_map第一个元素的迭代器位置
end	返回unordered_map最后一个元素下一个位置的迭代器
cbegin	返回unordered_map第一个元素的const迭代器
cend	返回unordered_map最后一个元素下一个位置的const迭代器

- 3、unordered_map的元素访问

| **函数声明** | **功能介绍**                         |
| ------------ | ------------------------------------ |
| operator[ ]  | 返回与key对应的value，没有一个默认值 |

注意：针对于[ ]的重载，该函数实际调用哈希桶的插入操作，用参数key与V()构造一个默认值往底层哈希桶中插入，针对插入成功与否，有如下说明：

    如果key不在哈希桶中，插入成功，返回V()。
    若key已经在哈希桶中，插入失败，将key对应的value返回。

其实和map的[ ]运算符重载的规则没有啥区别。







4、unordered_map的查询

    

函数声明	功能介绍
iterator find(const K& key)	返回key在哈希桶中的位置
size_t count(const K& key)	返回哈希桶中关键码为key的键值对的个数

注意：unordered_map中key是不能重复的，因此count函数的返回值最大为1。









- 5、unordered_map的修改操作

| **函数声明**              | **功能介绍**             |
| ------------------------- | ------------------------ |
|                           |                          |
| erase                     | 删除容器中的键值对       |
| void clear                | 清空容器中的有效元素个数 |
| void swap(unordered map&) | 交换两个容器中的元素     |









6、unordered_map的桶操作



函数声明	功能介绍
size_t bucket_count() const	返回哈希桶中桶的总个数
size_t bucket_size(size_t n) const	返回n号桶中有效元素的总个数
size_t bucket(const K& key)	返回元素key所在的桶号













### 插入

insert  向容器中插入键值对
插入有几种方式：

- 复制插入(复制一个已有的pair的内容)
- 数组插入（直接插入一个二维数组）
- 范围插入（复制一个起始迭代器和终止迭代器中间的内容）
- 数组访问模式插入(和数组的[]操作很相似)
具体的例子可以看后面示例代码。







```C++
/***********************************************************
 * @file name: Hello_World.cpp
 * @author: liubo
 * @date: 2024.04.19
 * @describe: 
 * 
 * 
 **********************************************************/
#include<iostream>
#include<string>
#include<utility>
#include<unordered_map>

using std::cin;
using std::cout;
using std::endl;

using std::pair;
using std::make_pair;
using std::string;
using std::unordered_map;

int main()
{
    cout << "----------------begain------------------" << endl;

    unordered_map<int, string> mp;

    cout << "----------------插入------------------" << endl;
    //1：借助pair构造对象
    pair<int, string> kv(1, "one");
    mp.insert(kv);

    //2：借助pair构造匿名对象插入
    mp.insert(pair<int, string>(2, "two"));

    //3：调用make_pair函数模板插入
    mp.insert(make_pair(3, "three"));

    //4：使用[]运算符重载函数进行插入
    mp[4] = "four";

    //5：使用{}
    mp.insert({ 5, "five" });

    cout << "----------------遍历------------------" << endl;
    //1：迭代器遍历
    unordered_map<int, string>::iterator it = mp.begin();
    cout << "iterator:";
    while (it != mp.end())
    {
        cout << it->first << ":" << it->second << " ";
        it++;
    }
    cout << endl;

    //2：范围for
    cout << "for:";
    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;

    cout << "----------------删除------------------" << endl;
    //1：根据key删除
    mp.erase(4);

    //2：根据迭代器位置删除
    unordered_map<int, string>::iterator pos = mp.find(2);
    if (pos != mp.end())
    {
        mp.erase(pos);
    }

    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;

    cout << "----------------修改------------------" << endl;
    //1：通过迭代器位置修改
    pos = mp.find(5);
    if (pos != mp.end())
    {
        pos->second = "Ⅴ";
    }

    //2：通过[]修改
    mp[3] = "Ⅲ";

    for (auto e : mp)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;

    cout << "----------------交换------------------" << endl;
    unordered_map<int, string> tmp{{7, "日"}, {5, "月"}, {2003, "年"}};
    mp.swap(tmp);
    for (auto e : mp)
    {
        cout << e.first << e.second << " ";
    }
    cout << endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
----------------插入------------------
----------------遍历------------------
iterator:5:five 4:four 3:three 2:two 1:one 
for:5:five 4:four 3:three 2:two 1:one 
----------------删除------------------
5:five 3:three 1:one 
----------------修改------------------
5:Ⅴ 3:Ⅲ 1:one 
----------------交换------------------
2003年 5月 7日 
----------------end------------------
 */

```











版权声明：

本文引用了博主原创文章，著作权归作者所有。遵循 CC 4.0 BY-SA 版权协议，商业转载请联系作者获得授权，非商业转载请附上原文出处链接和本声明。

本文是学习笔记，如有侵权，请联系删除。

参考：

链接：https://blog.csdn.net/bit_zyx/article/details/126765652

链接：https://blog.csdn.net/liu_xinLL/article/details/131506032
























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













  
