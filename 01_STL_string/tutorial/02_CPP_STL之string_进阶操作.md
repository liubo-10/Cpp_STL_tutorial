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
