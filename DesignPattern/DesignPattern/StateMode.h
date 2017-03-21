#pragma once   
#include "stdio.h"
/*********************************************************************************************               
*                                                                                            *
*       context() ------------------------------->         state                             *
*          |                                              handle()                           *
*     state->handle()                                     |       |                          *               
*                                            concrete_state_A     concrete_state_b           *
*                                                   handle()            handle()             *
**********************************************************************************************/

class State
{
public:
    virtual void run() = 0;
    virtual void walk() = 0 ;
};

class HighState:public State
{
public:
    HighState();
    ~HighState();
    void run() override;
    void walk() override;
};

class LowState :public State
{
public:
    LowState();
    ~LowState();
    void run() override;
    void walk() override;
};

class Exerciser
{
public:
    Exerciser();
    ~Exerciser();
    void enterLow();
    void enterHigh();
    void run();
    void walk();
private:
    State * _high;
    State * _low;
    State *_state;
};

void testState();