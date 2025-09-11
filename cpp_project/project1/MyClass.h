#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

// 这是一个简单的可执行类
class MyClass
{
public:
    // 构造函数
    MyClass() {};

    // 析构函数
    ~MyClass() {};

    // 公共的可执行方法
    void run()
    {
        std::cout << "MyClass is running..." << std::endl;
    }
};

#endif // MYCLASS_H
