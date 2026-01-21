# 01_STL_vector_基础

* 👋 Hi, I’m liubo
* 👀 I’m interested in
* 🌱 I’m currently learning
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📇 sssssdsdsdsdsdsdasd
* 🎃 dsdsdsdsdsddfsgdgasd
* 🍺 jyukyuiyuiyuigkasd
* 🍥 fsdfgdsgsdgdgadsa
* ✨ xcvxcvxcvxcvdasdaasd
* 🍰 dazdsxasxsaxsaasdsa
* 🚨 gdfgdshdfhfhygjtyu
## 💞️ vector 简介
vector 模板是 STL (Standard Template Library，标准模板库)中的一个容器类，使用方法类似数组。

使用时包含头文件:

```cpp
#include <vector>
```



## 💞️ vector 的基本操作

---

### ✨ vector 的构造

函数原型:

```cpp
// 1.构造一个空容器，没有元素。
vector<T> vectorname;

// 2.构造一个包含size个元素的容器。每个元素都是0。
vector<T> vectorname(size);

// 3.构造一个包含size个元素的容器。每个元素都是val。
vector<T> vectorname(size,value);

// 4.拷贝构造
vector<T> vectorname2(vectorname1);

// 5.利用数组构造容器
T m[] = {a,b,c,.....};
vector<T> vectorname(m, m + sizeof(m) / sizeof(T));

// 6.将[v.begin(),v.end())区间中的元素拷贝给本身，注意左闭右开
vector<T> vectorname2(vectorname1.begin(), vectorname1.end()); 

// 7.列表初始化构造容器
vector<T> vectorname{a,b,c,.....};
```

使用示例:

```cpp
printf("--------------------begain-------------------\n");

// 1.构造一个空容器，没有元素。
// vector<T> vectorname;
vector<int> vector_1; // 创建一个值类型为int的空vector
cout << "vector_1: ";
print_vector(vector_1);

// 2.构造一个包含size个元素的容器。每个元素都是0。
// vector<T> vectorname(size);
vector<int> vector_2(10); // 创建一个10个int的vector，且每个元素初值为0
cout << "vector_2: ";
print_vector(vector_2);

// 3.构造一个包含size个元素的容器。每个元素都是val。
// vector<T> vectorname(size, value);
vector<int> vector_3(10, 1); // 创建一个10个int的vector，且每个元素初值为1
cout << "vector_3: ";
print_vector(vector_3);

// 4.拷贝构造
// vector<T> vectorname2(vectorname1);
vector<int> vector_4(vector_3); // third temp 拷贝给vector forth ，两者元素值完全相同
cout << "vector_4: ";
print_vector(vector_4);

// 5.利用数组构造容器
// T m[] = {a, b, c, .....};
// vector<T> vectorname(m, m + sizeof(m) / sizeof(T));
int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> vector_5(a, a + 10); // 从数组区间[a[0], a[10])中获得初值,注意左闭右开，a[10]无意义这里助于理解
cout << "vector_5: ";
print_vector(vector_5);

// 6.将[v.begin(),v.end())区间中的元素拷贝给本身，注意左闭右开
// vector<T> vectorname2(vectorname1.begin(), vectorname1.end());

// temp [temp.begin(),temp.end()-5)区间的元素赋给fifth，注意左开右闭
vector<int> vector_6(vector_5.begin(), vector_5.end() - 5);
cout << "vector_6: ";
print_vector(vector_6);

vector<int> vectora6(vector_5.begin(), vector_5.end());
cout << "vectora6: ";
print_vector(vectora6);

// 7.列表初始化构造容器
// vector<T> vectorname{a, b, c, .....};
vector<int> vector_7 = {-1, 0, 3, 5, 7, 9}; // 列表初始化
cout << "vector_7: ";
print_vector(vector_7);

vector<int> vectora7{1, 0, -3, -5, -7, -9}; // 可以去掉等号
cout << "vectora7: ";
print_vector(vectora7);

printf("--------------------end----------------------\n");


```

测试结果:

```log
--------------------begain-------------------
vector_1: 
vector_2: 0 0 0 0 0 0 0 0 0 0 
vector_3: 1 1 1 1 1 1 1 1 1 1 
vector_4: 1 1 1 1 1 1 1 1 1 1 
vector_5: 0 1 2 3 4 5 6 7 8 9 
vector_6: 0 1 2 3 4 
vectora6: 0 1 2 3 4 5 6 7 8 9 
vector_7: -1 0 3 5 7 9 
vectora7: 1 0 -3 -5 -7 -9 
--------------------end----------------------
```


### ✨ vector 的遍历

方法1：

迭代器iterator中的begin和end函数是左闭右开的区间。

```cpp
// vector的遍历

void print_vector(vector<int> &v)

{ // 利用迭代器打印 v

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {

        cout << *it << " ";

    }

    cout << endl;

}
```



方法2：

```c++
void print_vector(vector<int> &v)
{ 
    for (auto n : v)
    {
        cout << n << " ";
    }
    cout << endl;
}
```


### ✨ vector 的赋值

函数原型：

```cpp
vector& operator=(const vector &v); //重载赋值运算符
assign(v.begin(),v.end());          //将[v.begin(),v.end())区间中的元素赋值给本身
assign(n,elem);                     //将n个elem赋值给本身

int myints[];
third.assign(myints,myints+3);   // assigning from array.
```

assign: 将新内容赋给vector，替换其当前内容，并相应地修改其大小。



使用示例:

```cpp
printf("--------------------begain-------------------\n");

vector<int> vector_01 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
cout << "vector_01: ";
print_vector(vector_01);

// 赋值方式1: 运算符 = 重载

// 1. 重载赋值运算符 =
// vector& operator=(const vector &v);
vector<int> vector_11;
vector_11 = vector_01;
cout << "vector_11: ";
print_vector(vector_11);

cout << " ---------------------------------------- " << endl;

// 赋值方式2: assign 函数

// 2. 函数参数使用迭代器
// assign(v.begin(),v.end());
// 将[v.begin(),v.end())区间中的元素赋值给本身

vector<int> vector_21;

vector_21.assign(vector_01.begin(), vector_01.end()); // 把 vector_01 值赋给 vector_21,其余值删除,左闭右开
cout << "vector_21: ";
print_vector(vector_21);

vector_21.assign(vector_01.begin(), vector_01.end() - 5); // 把 vector_01 除后五个值之外值赋给 vector_21,左闭右开
cout << "vector_21: ";
print_vector(vector_21);

// 3. 函数参数使用数值
// assign(n,elem);
//将n个elem赋值给本身

vector<int> vector_31(10, 1);
cout << "vector_31: ";
print_vector(vector_31);

vector_31.assign(5, 9); // 把5个9赋给 forth，其余值删除
cout << "vector_31: ";
print_vector(vector_31);

// 4. 函数参数使用数组
vector<int> vector_41(10, 1);
cout << "vector_41: ";
print_vector(vector_41);

int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector_41.assign(myints, myints + 5); //把 myints 前五个值赋给fifth，fifth左闭右开
cout << "vector_41: ";
print_vector(vector_41);

printf("--------------------end----------------------\n");

```

测试结果:

```log
--------------------begain-------------------
vector_01: 0 1 2 3 4 5 6 7 8 9 
vector_11: 0 1 2 3 4 5 6 7 8 9 
 ---------------------------------------- 
vector_21: 0 1 2 3 4 5 6 7 8 9 
vector_21: 0 1 2 3 4 
vector_31: 1 1 1 1 1 1 1 1 1 1 
vector_31: 9 9 9 9 9 
vector_41: 1 1 1 1 1 1 1 1 1 1 
vector_41: 0 1 2 3 4 
--------------------end----------------------
```


### ✨ vector 的元素访问

函数原型：

```c++
at(int idx);    //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[idx];  //返回索引idx所指的数据，如果idx越界，运行直接报错
front();        //返回容器中第一个数据元素
back();         //返回容器中最后一个数据元素
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

int main()
{
    printf("--------------------begain-------------------\n");
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> v_test(a, a + 10);

    cout << "调用at，打印 v_test: ";
    for (int i = 0; i < v_test.size(); i++)
    {
        cout << v_test.at(i) << " ";
    }
    cout << endl;

    cout << "调用[]，打印 v_test: ";
    for (int i = 0; i < v_test.size(); ++i)
    {
        cout << v_test[i] << " "; // 调用2
    }
    cout << endl;

    cout << "容器中第一个元素是：" << v_test.front() << endl;
    cout << "容器中最后一个元素是：" << v_test.back() << endl;

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
调用at，打印 v_test: 0 1 2 3 4 5 6 7 8 9 
调用[]，打印 v_test: 0 1 2 3 4 5 6 7 8 9 
容器中第一个元素是：0
容器中最后一个元素是：9
--------------------end----------------------
```


# 💞️ 总结

---

以上就是今天要讲的内容，后续会有更多内容。




# 💞️ 参考资料

---

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

