#pragma once
#include <lmcons.h>
#include <mutex>
/*
*     C++ 03 �Ժ����̵߳İ�ȫ��
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
    *    �̲߳���ȫ
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
    *     �̰߳�װ��ÿ�η��ʶ�Ҫ��������ʵֻҪ��һ������ʱ����Ҫ���������Ը÷���Ҳ����
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
    *    Ϊ�˱���� ������ȷ�������ܻ��뵽 ����ķ�������ʵ����3 �Ǵ��ڰ�ȫ�����ģ�
    *    ��� ����߳� ���ʵ�ʱ��A ��������������A ��δ��������ʱB ͬ������ if�жϣ���ô��������ˣ�
    *    ʵ�ʴ����˶��instance,���յ����ڴ�й©������������������Ԥ�ϵ�����
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
