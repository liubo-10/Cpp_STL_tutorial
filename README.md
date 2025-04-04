# STL_tutorial
STL_tutorial







C++
STL之内存管理
STL的内存管理分为两级

第一个级别用于较大内存分配与释放的管理(>128byte), malloc_alloc

第二个级别用于小于128byte的内存管理,default_alloc

stl有很多种allocator，根据C++的标准，stl的allocator把对象的申请和释放分为四个步骤：

（1） 申请内存空间，对应的函数是allocator：：allocate（）

（2） 执行构造函数，对应的函数是allocator：：construct（）

（3） 执行析构函数，对应的函数是allocator：：destory（）

（4） 释放内存空间，对应的函数是allocator：：的allocate（）

STL相关概念
SGI 全称为 Silicon Graphics Inc. 硅图公司，SGI_STL是SGI实现的C++的标准模板库。美国硅图公司成立于1982年，是一个生产高性能计算机系统的跨国公司，总部设在美国加州旧金山硅谷
_default_alloc_template分配器
这个分配器采用的是内存池的思想，有效的避免了内碎片的问题，内碎片是已经被分配出去了，外碎片是由于太小无法分配出去的空间。

（1）如果申请的空间大于128bytes，就将申请的操作移交给_malloc_alloc_template分配器去处理，如果申请内存大小小于128bytes，就从本分配器维护的内存池中分配内存。

（2）该分配器用空闲链表的方式维护内存池中的空闲空间，空闲链表的形状类似于下图所示：

总结
以上就是今天要讲的内容，后续会有更多内容。

参考资料
版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。

https://blog.csdn.net/cgcoder/article/details/74468915?spm=1001.2101.3001.6650.7&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EVECTOR_COMMERCIAL%7ERRF-7-74468915-blog-73730267.235%5Ev43%5Epc_blog_bottom_relevance_base9&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EVECTOR_COMMERCIAL%7ERRF-7-74468915-blog-73730267.235%5Ev43%5Epc_blog_bottom_relevance_base9&utm_relevant_index=14
https://blog.csdn.net/tangchenchan/article/details/46794633
https://blog.csdn.net/m0_37947204/article/details/80315111
https://blog.csdn.net/Mr_Garfield__/article/details/81274529