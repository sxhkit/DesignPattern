#pragma once
#include <list>
#include <mutex>
using namespace std;
class Receiver
{
public:
    Receiver();
    ~Receiver();
    void excute();
};

class Command
{
public:
    Command(Receiver *r);
    ~Command();
    virtual void excute() = 0;
protected:
    Receiver *_recv  = NULL;
};

class InstallCommand:public Command
{
public:
    InstallCommand(Receiver *recv);
    ~InstallCommand();
    void excute() override;
};

class UninstallCommand:public Command
{
public:
    UninstallCommand(Receiver *recv);
    ~UninstallCommand();
    void excute() override;
};

class Invoker
{
public:
    Invoker();
    ~Invoker();
    void setCmd(Command *cmd);
    void notify();
private:
    list<Command *> _list;
    mutex _mutex;
};

void testCommand();