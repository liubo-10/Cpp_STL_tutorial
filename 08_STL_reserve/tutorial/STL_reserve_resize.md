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

# STL_reserve_resize





下面讨论size与capacity的区别：

size一定与动态数组aha声明时的大小(即1000)相等，它是我们显式预定的空间。



而capacity则是系统数组在内存中连续空间的总大小，也就是说，我们可能申请了100大小的内存，但系统开辟空间时，给我们开辟了200大小的连续内存，这多出来的100，可以理解为备用空间。我们自己使用时，只能使用size大小内的空间(除非在尾部先添加)，而不能直接使用备用空间（如下标越界）。



一般而言，size=capacity ，此时没有备用空间。如果想在尾部添加(push_back)1个大小的内存空间，则系统会在另一个足够大的地方重新开辟空间，并将原来的数组赋值到新位置上。但一般会额外多开辟一些备用空间，为的就是防止反复移动整个数组，而导致运行效率降低。











size() – 返回目前存在的元素数。即： 元素个数
capacity() – 返回容器能存储 数据的个数。 即：容器容量
reserve() --设置 capacity 大小
resize() --设置 size ，重新指定有效元素的个数 ，区别与reserve()指定 容量的大小
clear() --清空所有元素，把size设置成0，capacity不变


​       



capacity 一般大于size的原因是为了避免 每次增加数据时都要重新分配内存，所以一般会 生成一个较大的空间，以便随后的数据插入。
size是当前vector容器真实占用的大小，也就是容器当前拥有多少个容器。
capacity是指在发生realloc前能允许的最大元素数，即预分配的内存空间。
这两个属性分别对应两个方法：resize()和reserve()。
使用resize()，容器内的对象内存空间是真正存在的。
使用reserve()仅仅只是修改了capacity的值，容器内的对象并没有真实的内存空间(空间是"野"的)。
此时切记使用[]操作符访问容器内的对象，很可能出现数组越界的问题。
针对capacity这个属性，STL中的其他容器，如list map set deque，由于这些容器的内存是散列分布的，因此不会发生类似realloc()的调用情况，因此我们可以认为capacity属性针对这些容器是没有意义的，因此设计时这些容器没有该属性。
在STL中，拥有capacity属性的容器只有vector和string。

































原文链接：https://blog.csdn.net/luolaihua2018/article/details/109406092











原文链接：https://blog.csdn.net/jyx1572676601/article/details/122791915



























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
