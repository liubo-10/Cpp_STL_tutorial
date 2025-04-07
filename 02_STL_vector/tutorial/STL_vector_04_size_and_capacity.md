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

# title
hfghgh

## fdfdf
sdfgsgfg























## 1.3 vector大小操作

```c++
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问
```



















### 容量

#### size

作用：返回vector中元素的个数。

【注意】vector中保存的实际对象的数量，不一定等于它的存储空间大小（容量）。

```C++
std::vector<int> myints;
std::cout  << myints.size() << std::endl;  //0
 
for (int i=0; i<10; i++) 
    myints.push_back(i);
std::cout << myints.size() << std::endl;  //10
 
myints.insert (myints.end(),10,100);
std::cout  << myints.size() << std::endl; //20
 
myints.pop_back();
std::cout <<  myints.size() << std::endl; //19
```

#### capacity

作用：返回当前为vector分配的存储空间大小（容量），以元素个数表示。

【注意】这个容量不一定等于向量的大小。它可以相等或更大，额外的空间允许容纳增长，而不需要在每次插入时重新分配。这个容量并没有假设向量的大小有限制。当此容量耗尽并且需要更多容量时，容器会自动对其进行扩展(重新分配其存储空间)。vector的大小的理论极限由成员max_size给出。可以通过调用vector::reserve成员显式地改变vector的容量。

```C++
std::vector<int> myvector;
 
// set some content in the vector:
for (int i=0; i<100; i++) myvector.push_back(i);

std::cout << "size: " << myvector.size() << "\n";            //100
std::cout << "capacity: " << myvector.capacity() << "\n";    //128
std::cout << "max_size: " << myvector.max_size() << "\n";    //1073741823
```













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
