#include "Adapt.h"
#include <stdio.h>
List::List()
{
}

List::~List()
{
}

void List::front()
{
    printf("front\n");
}

void List::push_back()
{
    printf("push_back\n");
}

AdaptList::AdaptList()
{   
    _list = new List;
}

AdaptList::~AdaptList()
{
}

void AdaptList::pop()
{
    _list->front();
}

void AdaptList::push()
{
    _list->push_back();
}