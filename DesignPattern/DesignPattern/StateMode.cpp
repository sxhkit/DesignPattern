#include "StateMode.h"
Exerciser::Exerciser()
{
    _high = new HighState;
    _low = new LowState;
    _state = _low;
}

Exerciser::~Exerciser()
{
    delete _high;
    delete _low;
}

void Exerciser::enterLow()
{
    _state = _low;
}

void Exerciser::enterHigh()
{
    _state = _high;
}

void Exerciser::run() {
    _state->run();
}

void Exerciser::walk() {
    _state->walk();
}

HighState::HighState() {

}

HighState::~HighState() {

}

void HighState::run()
{
    printf("at high heartbeat state, can't  run!\n");
}
void HighState::walk()
{
    printf("at high heartbeat state ,just can walk!\n");
}

LowState::LowState()
{

}

LowState::~LowState()
{

}

void LowState::run()
{
    printf("at low heartbeat state,running  is good!\n");
}

void LowState::walk()
{
    printf("at low heartbeat state,walking can't take exercise!\n");
}

void testState()
{
    Exerciser *e = new Exerciser();
    e->enterHigh();
    e->run();
    e->walk();

    e->enterLow();
    e->run();
    e->walk();

    delete e;
}