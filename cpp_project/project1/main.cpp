#include "hello.h"
#include <iostream>
using namespace std;

#define yuefen month
int a5 = 1;
int &b = a5;
const int *p = NULL;
// const指针指向的值不可以更改，但是指针的值可以更改，即数据只读

/*
 *标识符必须是字母数字下划线组成
 *数字不能是标识符第一位
 *最好做到命名见名知意
 */
int main()
{
    int ain = 0;
    bool bools = true;
    // 数据输入原理
    while ((cin >> ain))
    {
        if (cin.get() == '\n')
            break;
    }
    // 对于bool类型来说，1为true，0为false
    cout << "a5 = " << b << "Hello" << bools << endl;
    /*
     *哈哈哈哈
     *谁哈哈哈哈
     */
    string str = "fuckworld";
    cout << str << endl;
    cout << "short类型所占的空间大小" << sizeof(short) << endl;
    system("pause");
    return 0;
}
