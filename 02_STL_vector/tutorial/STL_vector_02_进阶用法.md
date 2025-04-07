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













# 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。

1. https://blog.csdn.net/qq_52324409/article/details/121000029
2. 











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
