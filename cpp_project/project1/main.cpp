#include <iostream>
#include <string>
#include <vector>
void f(const int i) {}
int main()
{
    const int a = 10;
    auto b = a;

    //*在const左侧则指针本身是常量，
    //*在const右侧则指针指向的内容是常量
    // 两者都有const则两者都是常量
    const char *pointer1;
    char const *pointer2;
    char *const pointer3 = nullptr;
    const char *const pointer4 = nullptr;

    // 两个禁忌：不能使用前一种指针修改指向的内容
    // 不能使用void*指针保存const类型的地址
    const int *ptr;
    int *const ptr2 = &b;
    const int p = 10;
    const void *vp = &p;

    // 可以把非const对象的地址赋给指向const对象的指针
    // 但是依然不能修改指向的内容
    int a22 = 10;
    const int *p = &a22;

    // const常量指针的指向是不能修改的
    int *const p2 = &a22;

    std::cin.get();
}
// 在函数中使用const
const int func1();  // const本身没有意义
const int *func2(); // 指向const int，指针本身可变
int *const func3(); // 指向int，指针本身不可变

void func4(const int var);  // 传参不可变，尤其是引用
void func5(int *const var); // 指针本身不变
void func6(const int *var); // 指针指向的内容不可变
void func7(const int &var); // 引用传递节省资源的同时用const避免改动

class Test
{
    // const对象只能访问const成员函数
    // 非const对象可以访问所有成员函数
    static const int count = 0;
};