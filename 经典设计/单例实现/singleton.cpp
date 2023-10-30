// Copyright 2023, Tencent Inc.
// Author: root
// Date: 10/30/23
#include<cstdio>

class Singleton
{
private:
    // 私有构造函数
    Singleton();

    // 禁止拷贝构造函数
    Singleton(const Singleton&) = delete;
    // 禁止重载赋值运算符函数
    Singleton& operator=(const Singleton&) = delete;


    static Singleton* instance;

public:
    static Singleton* getInstance()
    {
        if(!instance)
        {
            instance =  new Singleton();
        }
        return instance;
    }
};

int main()
{
    Singleton* instance = Singleton::getInstance();
}