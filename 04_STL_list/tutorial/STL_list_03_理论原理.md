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


> # STL_list_03_理论原理



链表与数组都是计算机常用的内存数据结构，与数组连续内存空间不一样的地方在于，链表的空间是不连续的，链表是将一块块不连续的内存串联起来使用。

正是由于链表的内存不连续这一特点，所以不能像数组一样，可以根据位置随机的访问每个元素，而链表我们压根不知道每个元素的实际位置到底在哪块内存区域。

查找某个元素需要遍历整个链表，直到找到目标元素位置，时间复杂度是 O(n)；

在链表中插入一个元素与删除一个元素的时间复杂度是 O(1)；











## **25.** ***\*3.7 list的底层原理\****

· list的底层是一个双向链表，使用链表存储数据，并不会将它们存储到一整块连续的内存空间中。恰恰相反，各元素占用的存储空间（又称为节点）是独立的、分散的，它们之间的线性关系通过指针来维持,每次插入或删除一个元素，就配置或释放一个元素空间。

· list不支持随机存取，如果需要大量的插入和删除，而不关心随即存取



















## list编程技巧

先判断链表是否为空

 

遇到需要删除头节点的情况，可以建立一个哑节点

遇到需要建立新链表的情况，可以建立一个哑节点

 

注意链表的移动，是不是还是指向头节点，可以新建一个临时变量保存指针，并进行操作初始指针不变。

 

合并多个列表，可以先建立合并两个的函数 













































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
