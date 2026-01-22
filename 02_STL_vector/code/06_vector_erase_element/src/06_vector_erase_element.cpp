/*****************************************************************************
 * | @file    : 06_vector_erase_element.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |    V1     2025-04-04
 * |    V2     2025-12-30
 * ---------------------------------------
 * | @brief   : vector 删除元素测试
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <iostream> // 包含输入和输出操作
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

//vector的遍历
void print_vector(vector<int> &v)
{
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    printf("--------------------begain-------------------\n");

    //删除方式1: pop_back 函数

    //1.尾部删除元素ele
    //pop_back(ele);
    //删除最后一个元素

    vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector_11.pop_back();
    cout << "vector_11: ";
    print_vector(vector_11);

    vector<int> vector_12{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector_12.pop_back();
    vector_12.pop_back();
    cout << "vector_12: ";
    print_vector(vector_12);

    cout << "----------------------------------------" << endl;

    //删除方式2: erase 函数

    //2.删除迭代器指向的元素
    //erase(const_iterator pos);

    //使用 erase 删除首个元素
    vector<int> vector_21{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_21.erase(vector_21.begin());
    cout << "vector_21: ";
    print_vector(vector_21);

    // 使用 erase 删除第二个元素
    vector<int> vector_22{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_22.erase(vector_22.begin() + 1);
    cout << "vector_22: ";
    print_vector(vector_22);

    //3.删除迭代器从begin到end之间的元素
    //erase(const_iterator begin,const_iterator end);

    // 使用 erase 删除全部元素
    vector<int> vector_31{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_31.erase(vector_31.begin(), vector_31.end());
    cout << "vector_31: ";
    print_vector(vector_31);

    // 使用 erase 删除前三个元素
    vector<int> vector_32{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_32.erase(vector_32.begin(), vector_32.begin() + 3);
    cout << "vector_32: ";
    print_vector(vector_32);

    // 使用 erase 删除后三个元素
    vector<int> vector_33{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_33.erase(vector_33.end() - 3, vector_33.end());
    cout << "vector_33: ";
    print_vector(vector_33);

    // 使用 erase 删除前三个后三个之外的元素
    vector<int> vector_34{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_34.erase(vector_34.begin() + 3, vector_34.end() - 3);
    cout << "vector_34: ";
    print_vector(vector_34);

    cout << "----------------------------------------" << endl;

    //删除方式3:  函数

    //clear();
    //删除容器中所有元素

    // 使用 clear 删除全部元素
    vector_41{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector_41.clear(); // 调用7，清空所有元素
    cout << "vector_41: ";
    print_vector(vector_41);

    printf("--------------------end----------------------\n");

    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
