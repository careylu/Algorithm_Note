// Copyright 2023, Tencent Inc.
// Author: root
// Date: 10/30/23
#include <iostream>

using namespace std;

template <typename T>
class SmartPointer
{
public:
    // 构造函数
    explicit SmartPointer(T* ptr = NULL) : _ptr(ptr), _count(ptr ? new int(1) : NULL) {}

    // 拷贝构造函数
    SmartPointer(const SmartPointer<T>& other) : _ptr(other._ptr), _count(other._count)
    {
        if(_count)
            ++(*_count);
    }

    // 赋值操作符
    SmartPointer<T>& operator=(const SmartPointer<T>& other)
    {
        if (this != &other) //&(*_ptr)相当于&&other,得到的是地址
        {
            release();
            _ptr = other._ptr;
            _count = other._count;
            if (_count)
                ++(*_count);
        }
        return *this;
    }

    // 析构函数
    ~SmartPointer()
    {
        release();
    }

    // 重载解引用操作符
    T& operator*() const
    {
        return *_ptr;
    }

    // 重载箭头操作符
    T* operator->() const
    {
        return _ptr;
    }

    // 获取引用计数
    int use_count() const
    {
        return _count ? *_count : 0;
    }

private:
    // 释放资源
    void release()
    {
        if(_count && --(*_count) == 0)
        {
            delete _ptr;
            delete _count;
        }
    }

    T* _ptr;
    int* _count;
};

int main()
{
    SmartPointer<int> sp1(new int(10));
    cout << "sp1 ptr value: " << *sp1 << endl;
    cout << "sp1 ptr address: " << sp1.operator->() << endl;
    cout << "sp1 use_count: " << sp1.use_count() << endl;

    SmartPointer<int> sp2(sp1);
    cout << "sp1 use_count: " << sp1.use_count() << endl;   // _count是指针类型，所以是浅拷贝
    cout << "sp2 use_count: " << sp2.use_count() << endl;
}