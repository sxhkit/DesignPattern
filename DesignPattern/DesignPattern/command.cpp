#include "command.h"
Receiver::Receiver()
{

}

Receiver::~Receiver()
{

}

void Receiver::excute()
{
    printf("receiver excute ");
}

Command::Command(Receiver *r):_recv(NULL)
{

}

Command::~Command()
{

}

InstallCommand::InstallCommand(Receiver *recv):Command(recv)
{

}

InstallCommand::~InstallCommand()
{
}

void InstallCommand::excute()
{
    _recv->excute();
    printf("install\n");
}

UninstallCommand::UninstallCommand(Receiver *recv):Command(recv)
{

}

UninstallCommand::~UninstallCommand()
{

}

void UninstallCommand::excute()
{
    _recv->excute();
    printf("uninstall\n");
}

Invoker::Invoker()
{

}

Invoker::~Invoker()
{

}

void Invoker::setCmd(Command *cmd)
{
    _mutex.lock();
    _list.push_back(cmd);
    _mutex.unlock();
}

void Invoker::notify()
{
    _mutex.lock();
    auto it = _list.begin();
    for (; it != _list.end();it++)
    {
        (*it)->excute();
    }
    _mutex.unlock();
}

void testCommand()
{
    Receiver *r = new Receiver;
    Invoker *i = new Invoker;
    Command *cmd_i = new InstallCommand(r);
    Command *cmd_u = new UninstallCommand(r);
    i->setCmd(cmd_i);
    i->setCmd(cmd_u);
    i->notify();

    delete r;
    delete i;
    delete cmd_u;
    delete cmd_i;
}