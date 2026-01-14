# 03_STL_vector_理论原理

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


> # STL_vector_03_理论原理

vector模板是C++标准模板库(STL(Standard Template Library))中的一个容器类，被设计为动态数组，即它可以根据需要自动分配内存空间来存储元素。vector模板的本质是一个类模板，它使用了C++语言中的模板技术，使其能够适应不同的数据类型，提供了一种通用的容器类实现方法。vector类使用连续的内存来存储元素，它提供了访问和操作元素的方法，还提供其他方法以帮助用户管理容器的大小和分配内存等,可以方便地存储和管理各种类型的数据。



vector和普通数组的区别：
1.数组是静态的，长度不可改变，而vector可以动态扩展，增加长度。
2.数组内数据通常存储在栈上，而vector中数据存储在堆上。



















## vector特点

1. 动态扩容：vector模板可以动态地扩充容器大小，当容器中元素数量增加时，vector会自动分配更多的内存空间来存储元素。这样可以避免手动分配内存空间带来的麻烦和错误。
2. 随机访问：vector中的元素是连续存储的，因此，可以通过下标的方式（使用[]操作符）来访问任何一个元素。这使得vector可以高效地进行随机访问。
3. 内存管理：vector会自动管理内存，当元素被删除或者容器的大小被缩小时，vector会自动回收不再需要的内存。这种管理方式可以避免内存泄漏问题。
4. 插入和删除元素：vector提供了多种插入和删除元素的方法，如push_back()  pop_back()、erase()等。这些方法可以方便地操作容器中的元素。
5. 大小变化：vector中的元素数量可以随时变化，因此可以方便地进行动态管理。同时，vector还提供了一些方法，如size()、capacity()、empty()等，以帮助用户管理容器的大小和内存分配等问题。

所谓动态增加大小，并不是在原空间之后续接新空间(因为无法保证原空间之后尚有可配置的空间)，而是一块更大的内存空间，然后将原数据拷贝新空间，并释放原空间。因此，对vector的任何操作，一旦引起空间的重新配置，指向原vector的所有迭代器就都失效了。这是程序员容易犯的一个错误，务必小心。

Vector的实现技术，关键在于其对大小的控制以及重新配置时的数据移动效率，一旦vector旧空间满了，如果客户每新增一个元素，vector内部只是扩充一个元素的空间，实为不智，因为所谓的扩充空间(不论多大)，一如刚所说，是”配置新空间-数据移动-释放旧空间”的大工程,时间成本很高，应该加入某种未雨绸缪的考虑，稍后我们便可以看到vector的空间配置策略。

### vector与array

vector的数据安排以及操作方式，与array（数组）非常相似，两者的唯一差别在于空间的运用的灵活性。

Array是静态空间，一旦配置了就不能改变，要换大一点或者小一点的空间，可以，一切琐碎得由自己来，首先配置一块新的空间，然后将旧空间的数据搬往新空间，再释放原来的空间。

Vector是动态空间，随着元素的加入，它的内部机制会自动扩充空间以容纳新元素。因此vector的运用对于内存的合理利用与运用的灵活性有很大的帮助，我们再也不必害怕空间不足而一开始就要求一个大块头的array了。

## 3.1 vector的底层原理

· vector底层是一个动态数组 ，包含三个迭代器， start和finish之间是已经被使用的空间范围 end _ of _ storage是整块连续空间包括备用空间的尾部 。

· 当空间不够装下数据（ vec . push_ back( val) ）时，会自动申请另一片更大的空 间（1.5倍或者2倍） ，然后把原来的数据拷贝到新的内存空间，接着释放原来的 那片空间[vector内存增长机制] 。

· 当释放或者删除（ v ec . c l e ar ()）里面的数据时，其存储空间不释放，仅仅是清 空了里面的数据。因此，对vector的任何操作一旦引起了空间的重新配置，指向原vector 的所有迭代器会都失效了 。

## 3.2 vector中的reserve和resize的区别

· reserve是直接扩充到已经确定的大小，可以减少多次开辟、释放空间的问题（优化push_back），就可以提高效率，其次还可以减少多次要拷贝数据的问题。reserve只是保证vector中的空间大小（capacity）最少达到参数所指定的大小n。reserve()只有一个参数。

· resize()可以改变有效空间的大小，也有改变默认值的功能。capacity的大小也会随着改变。resize()可以有多个参数。

## 3.3 vector中的size和capacity的区别

· size表示当前vector中有多少个元素（finish - start）;

· capacity函数则表示它已经分配的内存中可以容纳多少元素（end_of_storage - start）;

## 3.4 vector中erase方法与algorithn中的remove方法区别

· vector中erase方法真正删除了元素，迭代器不能访问了

· remove只是简单地将元素移到了容器的最后面，迭代器还是可以访问到。因为algorithm通过迭代器进行操作，不知道容器的内部结构，所以无法进行真正的删除。

## 3.5 vector迭代器失效的情况

· 当插入一个元素到vector中，由于引起了内存重新分配，所以指向原内存的迭代器全部失效。

· 当删除容器中一个元素后,该迭代器所指向的元素已经被删除，那么也造成迭代器失效。erase方法会返回下一个有效的迭代器，所以当我们要删除某个元素时，需要it=vec.erase(it);。

## 3.6 正确释放vector的内存(clear(), swap(), shrink_to_fit())

· vec.clear()：清空内容，但是不释放内存。

· vector().swap(vec)：清空内容，且释放内存，想得到一个全新的vector。

· vec.shrink_to_fit()：请求容器降低其capacity和size匹配。

· vec.clear();vec.shrink_to_fit();：清空内容，且释放内存。





















# title

hfghgh

## fdfdf
sdfgsgfg













# 2、vector的相关概念

动态扩展：动态扩展并不是在原空间之后续接新空间，而是找到比原来更大的内存空间，将原数据拷贝到新空间，释放原空间。

























# 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



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
