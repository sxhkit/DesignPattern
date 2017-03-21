// ”√int ¿‡–Õ 
#pragma once
#include "stdio.h"
class Strategy
{
public:
    virtual void  Operator() = 0;
};

class StrategyA: public Strategy
{
public:
    StrategyA();
    ~StrategyA();
    void  Operator() override;
};

class StrategyB:public Strategy
{
public:
    StrategyB();
    ~StrategyB();
    void Operator() override;
};

class Sence
{
public:
    virtual void useStrategy() = 0;
protected:
    Strategy *_strategy = NULL;
};

class NewSence:public Sence
{
public:
    NewSence(Strategy * s);
    ~NewSence();
    void useStrategy() override;
};

class OldSence:public Sence
{
public:
    OldSence(Strategy * s);
    ~OldSence();
    void useStrategy() override;
};

void testStrategy();
