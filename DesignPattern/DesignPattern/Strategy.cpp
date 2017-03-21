#include "Strategy.h"
StrategyA::StrategyA()
{
}

StrategyA::~StrategyA()
{
}

void StrategyA::Operator(){
    printf("use Strategy A!\n");
}

StrategyB::StrategyB() {

}

StrategyB::~StrategyB()
{

}

void StrategyB::Operator()
{
    printf("use Strategy B!\n");
}

NewSence::NewSence(Strategy * s)
{
    _strategy = s;
}

NewSence::~NewSence()
{
    delete _strategy;
}

void NewSence::useStrategy()
{
    printf(" new  sence ");
    _strategy->Operator();
}

OldSence::OldSence(Strategy * s)
{
    _strategy = s;
}

OldSence::~OldSence()
{
    delete _strategy;
}

void OldSence::useStrategy()
{
    printf("old sence ");
    _strategy->Operator();
}

void testStrategy()
{
    Sence *a = new NewSence(new StrategyA);
    Sence *b = new OldSence(new StrategyB);
    a->useStrategy();
    b->useStrategy();


    Sence *c = new NewSence(new StrategyB);
    Sence *d = new OldSence(new StrategyA);

    c->useStrategy();
    d->useStrategy();

    delete a;
    delete b;
    delete c;
    delete d;
}
