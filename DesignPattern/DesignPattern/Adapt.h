#pragma once
/*
* 
* �� list front �ӿ�ת��pop 
*/
class List
{
public:
    List();
    ~List();
    void front();
    /*
    *  list û�в���������������std list
    */
    void push_back();
private:

};


class Adapt
{
public:
    virtual void pop() = 0;
    virtual void push() = 0;

};

class AdaptList:public Adapt
{
public:
    AdaptList();
    ~AdaptList();
    virtual void pop();
    virtual void push();
private:
    List *_list;
};
