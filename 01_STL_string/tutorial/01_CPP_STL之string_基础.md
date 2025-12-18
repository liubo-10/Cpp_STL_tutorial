# 01_CPP_STL之string_基础

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

## 💞️ string简介

---
C风格字符串(以空字符结尾的字符数组)太过复杂难于掌握，不适合大程序的开发，所以C++标准库定义了一种string类，定义在头文件\<string\>。

头文件:

```cpp
#include <string>
```

## 💞️ String和c风格字符串对比

---

1. char\*是一个指针，string是一个类
2. string封装了 char\*，管理这个字符串，是一个 char\* 型的容器。
3. string封装了很多实用的成员方法。查找find，拷贝copy，删除delete 替换replace，插入insert等
4. 不用考虑内存释放和越界

  string管理char所分配的内存。每一次string的复制，取值都由string类负责维护，不用担心复制越界和取值越界等。
  string.c_str() 可将 string 装换为 const char \*str

### ✨ string和c-style字符串转换

```c++
//string 转 char*
string str = "it";
const char* cstr = str.c_str();
//char* 转 string 
char* s = "it";
string str(s);
```




## 💞️ string 的基本操作

---

### ✨ string 的构造

```cpp
cout << " -------------------- begain -------------------- " << endl;

// 1.无参默认构造 string
// 创建一个空的字符串
// string();
string str11;
str11 = "123456789";
cout << "str11 :" << str11 << endl;

cout << " ---------------------------------------- " << endl;

// 2.拷贝构造 string
// 2.1使用一个string对象初始化另一个string对象
// string(const string& str);
string str21(str11);
cout << "str21 :" << str21 << endl;

// 2.2选取 string 字符的拷贝构造
// 将一个字符串对象的第pos位置之后的len个字符初始化给对应的字符串对象
// string(const string& str, size_t pos, size_t len = npos);
string str22_1(str11, 0, 3);
cout << "str22_1:" << str22_1 << endl;

string str22_2(str11, 1, 3);
cout << "str22_2:" << str22_2 << endl;

string str22_3(str11, 2, 3);
cout << "str22_3:" << str22_3 << endl;

cout << " ---------------------------------------- " << endl;

// 3.使用c类型字符串构造 string
// 3.1使用长变量构造
// string(const char* s);
const char *s3 = "Hello, world!";
string str31(s3);
cout << "str31:" << str31 << endl;

// 3.2通过字符串常量构造
// string(const char* s);
string str32("hello, world");
cout << "str32:" << str32 << endl;

// 3.3通过字符串前n个字符构造
// string(const char* s, size_t n);
string s33("123456789", 6);
cout << "s33:" << s33 << endl;

cout << " ---------------------------------------- " << endl;

// 4.使用n个字符c构造 string
// string(size_t n, char c);
string str41_1(10, 'A');
cout << "str41_1:" << str41_1 << endl;

string str41_2(10, 'Z');
cout << "str41_2:" << str41_2 << endl;

cout << " -------------------- end -------------------- " << endl;
```

执行结果

```log
 -------------------- begain -------------------- 
str11 :123456789
 ---------------------------------------- 
str21 :123456789
str22_1:123
str22_2:234
str22_3:345
 ---------------------------------------- 
str31:Hello, world!
str32:hello, world
s33:123456
 ---------------------------------------- 
str41_1:AAAAAAAAAA
str41_2:ZZZZZZZZZZ
 -------------------- end -------------------- 
```

### ✨ string 的赋值

```cpp
cout << " -------------------- begain -------------------- " << endl;

// 赋值方式1: 运算符 = 重载

// 1. char*类型字符串 赋值给当前的字符串
// string &operator=(const char *s)

// 1.1 通过定义变量赋值
const char *s1 = "Hello, world!";
string str11;
str11 = s1;
cout << "str11:" << str11 << endl;

// 1.2 字符串常量直接赋值
string str12;
str12 = "123456789";
cout << "str12:" << str12 << endl;

// 2. 把字符串s赋给当前的字符串
// string &operator=(const string &s);
string str21;
str21 = str11;
cout << "str21:" << str21 << endl;

// 3. 字符赋值给当前的字符串
// string &operator=(char c);
string str31;
str31 = 'A';
cout << "str31:" << str31 << endl;

cout << " ---------------------------------------- " << endl;

// 赋值方式2: assign 函数

// 4. assign 参数为 char*类型字符串
// string &assign(const char *s);

// 4.1 参数为字符串变量
string str41;
const char *s4 = "123456789";
str41.assign(s4);
cout << "str41:" << str41 << endl;

// 4.2 参数为字符串常量
string str42;
str42.assign("Hello, world!");
cout << "str42:" << str42 << endl;

// 4.3 把字符串s的前n个字符赋给当前的字符串
// string &assign(const char *s, int n);
string str43_1;
str43_1.assign(s4, 1);
cout << "str43_1:" << str43_1 << endl;

string str43_2;
str43_2.assign(s4, 2);
cout << "str43_2:" << str43_2 << endl;

string str43_3;
str43_3.assign(s4, 3);
cout << "str43_3:" << str43_3 << endl;

// 5. assign 参数为 string 类型字符串
// string &assign(const string &s);

// 5.1 把string字符串s赋给当前字符串
string str51;
str51.assign(str42);
cout << "str51:" << str51 << endl;

// 5.2 将string字符串s从start开始n个字符赋值给字符串
// string &assign(const string &s, int start, int n);
string str52_1;
str52_1.assign(str41, 0, 3);
cout << "str52_1:" << str52_1 << endl;

string str52_2;
str52_2.assign(str41, 1, 3);
cout << "str52_2:" << str52_2 << endl;

string str52_3;
str52_3.assign(str41, 2, 3);
cout << "str52_3:" << str52_3 << endl;

// 6. assign 参数为 n个字符c
// string &assign(int n, char c);

string str6;
str6.assign(5, 'Z');
cout << "str6 :" << str6 << endl;

cout << " -------------------- end -------------------- " << endl;

```

执行结果

```log
 -------------------- begain -------------------- 
str11:Hello, world!
str12:123456789
str21:Hello, world!
str31:A
 ---------------------------------------- 
str41:123456789
str42:Hello, world!
str43_1:1
str43_2:12
str43_3:123
str51:Hello, world!
str52_1:123
str52_2:234
str52_3:345
str6 :ZZZZZ
 -------------------- end -------------------- 
 -------------------- end -------------------- 
```

### ✨ string 的元素操作

string存取字符操作

```cpp
cout << " -------------------- begain -------------------- " << endl;

// 1. 重载[]运算符，n是下标
// char &operator[](int n);
string str1("hello, world");
cout << "str1:" << str1 << endl;

str1[0] = 'H'; //将字符串第1个元素改为H
cout << "str1:" << str1 << endl;

str1[7] = 'W'; //将字符串第8个元素改为H
cout << "str1:" << str1 << endl;

cout << " ---------------------------------------- " << endl;

// 2. 通过at方法获取下标为n的元素
// char &at(int n);
string str2("hello, world");
cout << "str2:" << str2 << endl;

str2.at(0) = 'H'; //将字符串第1个元素改为H
cout << "str2:" << str2 << endl;

str2.at(7) = 'W'; //将字符串第8个元素改为H
cout << "str2:" << str2 << endl;

cout << " ---------------------------------------- " << endl;

// 3. 字符串的取值和修改操作之at方法和重载operator[]方法的区别

// 使用重载operator[]运算符方法，下标越界不会抛出异常
try {
    str1[100] = 'H';                  // 数组下标访问越界，使用operator[]方法不会抛出异常
} catch (std::exception &str) {       // 接收来自try的异常
    cout << "string [] test" << endl; // 不会打印
    cout << str.what() << endl;       // 不会打印
}

cout << " ---------------------------------------- " << endl;

// 使用at方法，下标越界会抛出异常
try {
    str2.at(100) = 'H';                 // 抛出异常，程序不会终止
} catch (std::exception &str) {         // 接收来自try的异常
    cout << "string at() test" << endl; // 会打印
    cout << str.what() << endl;         // 会打印
}

cout << " -------------------- end -------------------- " << endl;

```

执行结果

```log
 -------------------- begain -------------------- 
str1:hello, world
str1:Hello, world
str1:Hello, World
 ---------------------------------------- 
str2:hello, world
str2:Hello, world
str2:Hello, World
 ---------------------------------------- 
 ---------------------------------------- 
string at() test
basic_string::at: __n (which is 100) >= this->size() (which is 12)
 -------------------- end -------------------- 
```

## 💞️ 总结

---

以上就是今天要讲的内容，后续会有更多内容。

## 💞️ 参考资料

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
