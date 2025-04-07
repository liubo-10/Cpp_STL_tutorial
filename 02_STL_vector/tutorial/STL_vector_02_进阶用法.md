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


> # STL_vector_02_进阶用法





# 一、swap函数

函数原型:

```C++
swap(v); //容器v和当前容器互换
```

使用示例:

```c++
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <iostream>  // 包含输入和输出操作
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// vector的遍历
void printVector(vector<int> &v)
{
    for (auto n : v)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");
    vector<int> v_test1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v_test2 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "交换前：" << endl;
    printVector(v_test1);
    printVector(v_test2);
    cout << "交换后：" << endl;
    v_test1.swap(v_test2); // 调用互换函数
    printVector(v_test1);
    printVector(v_test2);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}
```

测试结果:

```tex
--------------------begain-------------------
交换前：
0 1 2 3 4 5 6 7 8 9 
9 8 7 6 5 4 3 2 1 0 
交换后：
9 8 7 6 5 4 3 2 1 0 
0 1 2 3 4 5 6 7 8 9 
--------------------end----------------------
```



































# 二、vector 迭代器失效的原因

## 1.内存重新分配(导致所有迭代器失效)

当vector插入元素(如 push_back,  insert)时，若当前容量不足vector会申请一块更大的内存，将旧元素拷贝到新内存，并释放就内存。此时：所有迭代器，指针和引用都会失效(因为它们指向就内存)

```c++
std::vector<int> v = {1, 2, 3};
auto it = v.begin();
v.push_back(4); // 可能导致容量不足，触发内存重新分配
*it = 10;       // 错误！it 已失效！
```







2.元素位置变动(导致部分迭代器失效)

当删除元素(如erase，pop_back)或在中间插入元素时，元素的位置可能发生移动：

被删除元素之后的迭代器会失效（因为后续元素会向前移动）

std::vector<int> v = {1, 2, 3, 4};
auto it = v.begin() + 2; // 指向 3
v.erase(v.begin() + 1);  // 删除 2，元素变为 {1, 3, 4}
*it = 10;                // 错误！it 指向原位置（现在是 4），可能未定义行为
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/HH_KZ1314/article/details/145585503























本文链接：https://blog.csdn.net/m0_37251750/article/details/100071023

————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/m0_37251750/article/details/100071023















本文链接：https://blog.csdn.net/fuxiaoxiaoyue/article/details/84847967



















 vector 迭代器失效问题

迭代器的主要作用就是让算法能够不用关心底层数据结构，其底层实际就是一个指针，或者是对指针进行了封装
比如：vector的迭代器就是原生态指针 T*。因此迭代器失效，实际就是迭代器底层对应指针所指向的 空间被销毁了，而使用一块已经被释放的空间，造成的后果是程序崩溃(即如果继续使用已经失效的迭代器，程序可能会崩溃)。
对于vector可能会导致其迭代器失效的操作：
会引起其底层空间改变的操作，都有可能是迭代器失效 ，比如： resize、reserve、insert、assign、 push_back 等
指定位置元素的删除操作  erase 
 erase 删除 pos 位置元素后，pos位置之后的元素会往前搬移，没有导致底层空间的改变，理论上讲迭代器不应该会失效，但是：如果pos刚好是最后一个元素，删完之后pos刚好是end的位置，而end位置是没有元素的，那么pos就失效了。因此删除vector中任意位置上元素时，vs就认为该位置迭代器失效了。
划重点了哟！！！ 迭代器失效解决办法：在使用前，对迭代器重新赋值即可。
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/chen_hard/article/details/119759216































# 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。

1. https://blog.csdn.net/qq_52324409/article/details/121000029
2. https://blog.csdn.net/hffh123/article/details/139151432
3. https://blog.csdn.net/HH_KZ1314/article/details/145585503











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
