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

# String和c风格字符串对比

- Char\*是一个指针，String是一个类
- string封装了char\*，管理这个字符串，是一个char*型的容器。
- String封装了很多实用的成员方法
  查找find，拷贝copy，删除delete 替换replace，插入insert等
- 不用考虑内存释放和越界

  string管理char所分配的内存。每一次string的复制，取值都由string类负责维护，不用担心复制越界和取值越界等。


# ✨string的使用

# ✨string 的构造
---
```cpp


cout << " ----------------------------------------begain---------------------------------------- " << endl;

// 1.无参默认构造 string
// 创建一个空的字符串
// string();
string s1;
s1 = "123456789";
cout << "s1 :" << s1 << endl;

cout << " -------------------------------------------------------------------------------- " << endl;
//--------------------------------------------------------------------------------------------------

// 2.拷贝构造 string
// 2.1使用一个string对象初始化另一个string对象
// string(const string& str);
string s2(s1);
cout << "s2 :" << s2 << endl;

// 2.2选取 string 字符的拷贝构造
// 将一个字符串对象的第pos位置之后的len个字符初始化给对应的字符串对象
// string(const string& str, size_t pos, size_t len = npos);
string s21(s1, 0, 3);
cout << "s21:" << s21 << endl;

string s22(s1, 1, 3);
cout << "s22:" << s22 << endl;

string s23(s1, 2, 3);
cout << "s23:" << s23 << endl;

cout << " -------------------------------------------------------------------------------- " << endl;
//--------------------------------------------------------------------------------------------------

// 3.使用c类型字符串构造 string
// 3.1使用长变量构造
// string(const char* s);
const char *s = "Hello, world!";
string s3(s);
cout << "s3 :" << s3 << endl;

// 3.2通过字符串常量构造
// string(const char* s);
string s31("hello, world");
cout << "s31:" << s31 << endl;

// 3.3通过字符串前n个字符构造
// string(const char* s, size_t n);
string s32("123456789", 6);
cout << "s32:" << s32 << endl;

cout << " -------------------------------------------------------------------------------- " << endl;
//--------------------------------------------------------------------------------------------------

// 4.使用n个字符c构造 string
// string(size_t n, char c);
string s4(10, 'A');
cout << "s4 :" << s4 << endl;

string s5(10, 'Z');
cout << "s5 :" << s5 << endl;

cout << " ----------------------------------------end---------------------------------------- " << endl;













cout << "--------------------------begain-------------------------" << endl;


// 1.无参默认构造
// 创建一个空的字符串
// string();
string s1;
s1 = "123456789";
cout << "s1:" << s1 << endl;

// 2.拷贝构造
// 使用一个string对象初始化另一个string对象
// string(const string& str);
string s2(s1);
cout << "s2:" << s2 << endl;

// 3.使用c字符串初始化
// string(const char* s);
const char *s = "Hello, world!";
string s3(s);
cout << "s3:" << s3 << endl;

// 4、通过字符串常量初始化
// string(const char* s);
string s4("hello, world");
cout << "s4:" << s4 << endl;

// 5.使用n个字符c初始化
// string(size_t n, char c);
string s5(10, 'x');
cout << "s5:" << s5 << endl;

// 6.通过字符串前n个字符初始化
// string(const char* s, size_t n);
string s6("123456789", 6);
cout << "s6:" << s6 << endl;

// 7.通过string子串初始化
// 将一个字符串对象的第pos位置之后的len个字符初始化给对应的字符串对象
// string(const string& str, size_t pos, size_t len = npos);
string s7(s1, 0, 3);
cout << "s7:" << s7 << endl;

string s8(s1, 1, 3);
cout << "s8:" << s8 << endl;

string s9(s1, 2, 3);
cout << "s9:" << s9 << endl;

cout << "--------------------end----------------------" << endl;


```

执行结果
```log
--------------------begain-------------------
s1:123456789
s2:123456789
s3:Hello, world!
s4:hello, world
s5:xxxxxxxxxx
s6:123456
s7:123
s8:234
s9:345
--------------------end----------------------
```


# ✨string 的赋值操作
---
```cpp
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串









```



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



# ✨总结
---
以上就是今天要讲的内容，后续会有更多内容。







# ✨参考资料
---
版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
1. ===
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
