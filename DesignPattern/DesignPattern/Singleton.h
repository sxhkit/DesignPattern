#pragma once
#include <lmcons.h>
#include <mutex>
/*
*     C++ 03 以后是线程的安全的
*/
class SlingletonA
{
    SlingletonA() {

    }
public:
    ~SlingletonA(){

    }
    static SlingletonA * getInstanc()
    {
        static  SlingletonA slingletinA;
        return &slingletinA;
    }

private:

};

class SlingletonB
{
    SlingletonB() {

    }
public:
    ~SlingletonB()
    {

    }
    /*
    *    线程不安全
    */
    static SlingletonB *getInstance_1()
    {
        if (_instance)
        {
            _instance = new SlingletonB;
        }
        return _instance;
    }
    /*
    *     线程安装，每次访问都要上锁，其实只要第一创建的时候需要上锁，所以该方法也不好
    */
    static SlingletonB *getInstance_2()
    {
        _mutex.lock();
        if (_instance)
        {
            _instance = new SlingletonB;
        }
        _mutex.unlock();
        return _instance;
    }

    /*
    *    为了避免二 方法的确定，可能会想到 下面的方法，事实方法3 是存在安全隐患的，
    *    如果 多个线程 访问的时候A 进入了锁，但是A 尚未解锁，此时B 同样进入 if判断，那么问题就来了，
    *    实际创建了多个instance,最终导致内存泄漏，甚至存在其他不可预料的问题
    */
    static SlingletonB *getInstance_3()
    {
        if (_instance)
        {
            _mutex.lock();
            _instance = new SlingletonB;
            _mutex.unlock();
        }
        return _instance;
    }
private:
    static SlingletonB * _instance;
    static std::mutex _mutex;
};
