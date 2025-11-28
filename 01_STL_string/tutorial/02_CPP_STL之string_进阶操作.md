# 02_CPP_STL之string_进阶操作

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

## 💞️ string 的进阶操作

---



### ✨ string 的构造

```cpp
cout << " -------------------- begain -------------------- " << endl;

// 拼接方式1: 重载 += 运算符

// 1.参数是 string 类型
// string &operator+=(const string &str);
string str11("hello,");
string str1_1("world!");
str11 += str1_1; //两个对象相加赋值给str111对象
cout << "str11:" << str11 << endl;

// 2 参数是 const char * 类型
// string &operator +=(const char *str);//c风格

// 2.1 通过定义变量拼接
const char *s2 = "67890";
string str21("12345");
str21 += s2;
cout << "str21:" << str21 << endl;

// 2.2 字符串常量直接拼接
string str22("abcde");
str22 += "fghij";
cout << "str22:" << str22 << endl;

// 3.参数是 const char 类型
// string &operator +=(const char c);
string str31("abcde");
str31 += "f";
const char c3 = 'g';
str31 += c3;
cout << "str31:" << str31 << endl;

cout << " ---------------------------------------- " << endl;

// 拼接方式2: append 函数

// 4.参数是 string 类型

// 4.1 把字符串s拼接在当前字符串后面
// string &append(const string &s);
string str41("hello,");
string str4_1("world!");
str41.append(str4_1);
cout << "str41:" << str41 << endl;

// 4.2 将s从 start 开始n个字符赋值给字符串
// string &append(const string &s, int start, int n);
string str4_2("1234567890");

string str42_0("hello");
str42_0.append(str4_2, 0, 3);
cout << "str42_0:" << str42_0 << endl;

string str42_1("hello");
str42_1.append(str4_2, 1, 3);
cout << "str42_1:" << str42_1 << endl;

string str42_2("hello");
str42_2.append(str4_2, 2, 3);
cout << "str42_2:" << str42_2 << endl;

// 5.参数是 const char *s 类型
// string &append(const char *s);//append追加方法

// 5.1 通过定义变量拼接
const char *s5_1 = "12345";
string str51("god");
str51.append(s5_1);
cout << "str51:" << str51 << endl;

// 5.2 字符串常量直接拼接
string str52("god");
str52.append("67890");
cout << "str52:" << str52 << endl;

// 5.3 把字符串 const char *s 的前n个字符追加到当前的字符串之后
// string &append(const char *s, int n);
const char *s5_3 = "1234567890";

string str53_0("study");
str53_0.append(s5_3, 0); //前0个追加给 str53_0 对象
cout << "str53_0:" << str53_0 << endl;

string str53_1("study");
str53_1.append(s5_3, 2); //前2个追加给 str53_1 对象
cout << "str53_1:" << str53_1 << endl;

string str53_2("study");
str53_2.append(s5_3, 4); //前4个追加给 str53_2 对象
cout << "str53_2:" << str53_2 << endl;

// 6.参数是 const char c 类型
// string &append(int n,char c);

string str6("AAA");
str6.append(3, 'B');
cout << "str6 :" << str6 << endl;

cout << " -------------------- end -------------------- " << endl;
```

执行结果

```log
 -------------------- begain -------------------- 
str11:hello,world!
str21:1234567890
str22:abcdefghij
str31:abcdefg
 ---------------------------------------- 
str41:hello,world!
str42_0:hello123
str42_1:hello234
str42_2:hello345
str51:god12345
str52:god67890
str53_0:study
str53_1:study12
str53_2:study1234
str6 :AAABBB
 -------------------- end -------------------- 
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
