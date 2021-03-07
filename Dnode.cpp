#include <iostream>
#include "Dnode.h"

Dnode::Dnode()
: next(nullptr), prev(nullptr) { }

Dnode::Dnode(std::string data)
{
  this->data = data;
  next = nullptr;
  prev = nullptr;
}

Dnode::Dnode(std::string data, Dnode *next, Dnode *prev)
{
  this->data = data;
  this->next = next;
  this->prev = prev;
}

Dnode::~Dnode()
{
  delete next;
  delete prev;
}

void Dnode::setPrev(Dnode *prev)
{
  this->prev = prev;
}

void Dnode::setNext(Dnode *next)
{
  this->next = next;
}

void Dnode::setData(std::string data)
{
  this->data = data;
}

Dnode *Dnode::getNext()
{
  return next;
}

Dnode *Dnode::getPrev()
{
  return prev;
}

std::string Dnode::getData()
{
  return data;
}
