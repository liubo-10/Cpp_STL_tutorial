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




# 💞️ 标题一

---


## ✨ 标题二



### 🌱 标题三



# 💞️ string简介

---
C风格字符串(以空字符结尾的字符数组)太过复杂难于掌握，不适合大程序的开发，所以C++标准库定义了一种string类，定义在头文件\<string\>。


头文件:

```C++
#include<string>
```

# 💞️ String和c风格字符串对比

---

- Char\*是一个指针，String是一个类
- string封装了 char\*，管理这个字符串，是一个 char\* 型的容器。
- String封装了很多实用的成员方法
  查找find，拷贝copy，删除delete 替换replace，插入insert等
- 不用考虑内存释放和越界

  string管理char所分配的内存。每一次string的复制，取值都由string类负责维护，不用担心复制越界和取值越界等。


# 💞️ string 的基本操作

---

## ✨ string 的构造

```cpp
cout << " -------------------- begain -------------------- " << endl;

// 1.无参默认构造 string
// 创建一个空的字符串
// string();
string s11;
s11 = "123456789";
cout << "s11 :" << s11 << endl;

cout << " ---------------------------------------- " << endl;

// 2.拷贝构造 string
// 2.1使用一个string对象初始化另一个string对象
// string(const string& str);
string s21(s11);
cout << "s21 :" << s21 << endl;

// 2.2选取 string 字符的拷贝构造
// 将一个字符串对象的第pos位置之后的len个字符初始化给对应的字符串对象
// string(const string& str, size_t pos, size_t len = npos);
string s22_1(s11, 0, 3);
cout << "s22_1:" << s22_1 << endl;

string s22_2(s11, 1, 3);
cout << "s22_2:" << s22_2 << endl;

string s22_3(s11, 2, 3);
cout << "s22_3:" << s22_3 << endl;

cout << " ---------------------------------------- " << endl;

// 3.使用c类型字符串构造 string
// 3.1使用长变量构造
// string(const char* s);
const char *s3 = "Hello, world!";
string s31(s3);
cout << "s31:" << s31 << endl;

// 3.2通过字符串常量构造
// string(const char* s);
string s32("hello, world");
cout << "s32:" << s32 << endl;

// 3.3通过字符串前n个字符构造
// string(const char* s, size_t n);
string s33("123456789", 6);
cout << "s33:" << s33 << endl;

cout << " ---------------------------------------- " << endl;

// 4.使用n个字符c构造 string
// string(size_t n, char c);
string s41_1(10, 'A');
cout << "s41_1:" << s41_1 << endl;

string s41_2(10, 'Z');
cout << "s41_2:" << s41_2 << endl;

cout << " -------------------- end -------------------- " << endl;
```

执行结果
```log
 -------------------- begain -------------------- 
s11 :123456789
 ---------------------------------------- 
s21 :123456789
s22_1:123
s22_2:234
s22_3:345
 ---------------------------------------- 
s31:Hello, world!
s32:hello, world
s33:123456
 ---------------------------------------- 
s41_1:AAAAAAAAAA
s41_2:ZZZZZZZZZZ
 -------------------- end -------------------- 
```

## ✨ string 的赋值

```cpp
cout << " -------------------- begain -------------------- " << endl;

// 赋值方式一: 运算符 = 重载

// 1. char*类型字符串 赋值给当前的字符串
// string &operator=(const char *s)

// 1.1 通过变量赋值
const char *s1 = "Hello, world!";
string s11;
s11 = s1;
cout << "s11:" << s11 << endl;

// 1.2 字符串常量赋值
string s12;
s12 = "123456789";
cout << "s12:" << s12 << endl;

// 2. 把字符串s赋给当前的字符串
// string &operator=(const string &s);
string s21;
s21 = s11;
cout << "s21:" << s21 << endl;

// 3. 字符赋值给当前的字符串
// string &operator=(char c);
string s31;
s31 = 'A';
cout << "s31:" << s31 << endl;

cout << " ---------------------------------------- " << endl;

// 赋值方式2: assign 函数

// 4. assign 参数为 char*类型字符串
// string &assign(const char *s);

// 4.1 参数为字符串变量
string s41;
const char *s4 = "123456789";
s41.assign(s4);
cout << "s41:" << s41 << endl;

// 4.2 参数为字符串常量
string s42;
s42.assign("Hello, world!");
cout << "s42:" << s42 << endl;

// 4.3 把字符串s的前n个字符赋给当前的字符串
// string &assign(const char *s, int n);
string s431;
s431.assign(s4, 1);
cout << "s431:" << s431 << endl;

string s432;
s432.assign(s4, 2);
cout << "s432:" << s432 << endl;

string s433;
s433.assign(s4, 3);
cout << "s433:" << s433 << endl;

// 5. assign 参数为 string 类型字符串
// string &assign(const string &s);

// 5.1 把字符串s赋给当前字符串
string s51;
s51.assign(s42);
cout << "s51:" << s51 << endl;

// 5.2 将s从start开始n个字符赋值给字符串
// string &assign(const string &s, int start, int n);
string s521;
s521.assign(s41, 0, 3);
cout << "s521:" << s521 << endl;

string s522;
s522.assign(s41, 1, 3);
cout << "s522:" << s522 << endl;

string s523;
s523.assign(s41, 2, 3);
cout << "s523:" << s523 << endl;

// 6. assign 参数为 n个字符c
// string &assign(int n, char c);

string s6;
s6.assign(5, 'Z');
cout << "s6:" << s6 << endl;

cout << " -------------------- end -------------------- " << endl;

```




## ✨ string 的单元素操作



string存取字符操作

```c++
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
```








string拼接操作

```c++
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c
```



string查找和替换

```c++
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
```



string比较操作

```c++
/*
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。
*/
int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
```



string子串

```c++
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
```



string插入和删除操作

```c++
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符 
```



string和c-style字符串转换

```c++
//string 转 char*
string str = "it";
const char* cstr = str.c_str();
//char* 转 string 
char* s = "it";
string str(s);
```



在c++中存在一个从const char*到string的隐式类型转换，却不存在从一个string对象到C_string的自动类型转换。对于string类型的字符串，可以通过c_str()函数返回string对象对应的C_string.

通常，程序员在整个程序中应坚持使用string类对象，直到必须将内容转化为char*时才将其转换为C_string.



# 💞️ 总结

---

以上就是今天要讲的内容，后续会有更多内容。







# 💞️ 参考资料

---

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
1. [https://blog.csdn.net/m0_74126249/article/details/132269079](https://blog.csdn.net/m0_74126249/article/details/132269079) 
2. [https://blog.csdn.net/qq_55610255/article/details/132947932](https://blog.csdn.net/qq_55610255/article/details/132947932)





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
