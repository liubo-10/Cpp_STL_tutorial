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




# 💞️ 标题一

---


## ✨ 标题二



### 🌱 标题三

---






 4.2、字符串的取值和修改操作之at方法和重载operator[]方法的区别

使用重载operator[]运算符方法，下标越界不会抛出异常







```
#include <iostream>
#include<string>
using namespace std;
 
void test2(){
   /*
   char &operator[](int n);//重载[]运算符，n是下标
   char &at(int n);//通过at方法获取下标为n的元素
   */
    string str1="hello,string类";//赋值运算符赋值初始化，一般不建议，在这里可以用，因为是常量，不会发生隐式转换
    string str2("hello,string类");//直接赋值初始化，建议使用该方法
    str2[4]='H';//将字符串第五个元素改为H
    cout<<str2<<endl;
    cout<<str2[4]<<endl;
 
    str1.at(1)='E';//使用at方法取值然后修改值
    cout<<str1<<endl;
    cout<<str1[1]<<endl;
 
    try{
        str1[100000]='H';//数组下标访问越界，使用operator[]方法不会抛出异常
    }
    catch(exception &str){
        cout<<str.what()<<endl;//接收来自try的异常
 
    }
    printf("hello,string测试\n");//测试
 
}
 
int main()
{
    test2();//调用函数
    return 0;
}
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
