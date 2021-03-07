#include <iostream>
#include "Dlist.h"
#include <cmath>

Dlist::Dlist()
{
  head = new Dnode();
  tail = new Dnode();
  head->setNext(tail);
  head->setPrev(nullptr);
  tail->setNext(nullptr);
  tail->setPrev(head);
  size = 0;
}
Dlist::~Dlist()
{
  delete head;
  delete tail;
}

std::string Dlist::toString()
{
  Dnode *walker = head;
  std::string str;
  while(walker != nullptr)
  {
    str += walker->getData();
    str += "<->";
    walker = walker->getNext();
  }
  str += "nullptr";
  return str;
}

void Dlist::insert(std::string data){
  Dnode *new_node = new Dnode(data);
  if(size == 0){
    head->setData(data);
    cur = head;
  }
  else{
    cur->setNext(new_node);
    cur->getNext()->setPrev(cur);
    cur = new_node;
    tail = new_node;
  }
  size++;
}

void Dlist::insert(int loc, std::string data)
{
  Dnode *newnode = new Dnode(data);
  if (loc == 0)
  {
    newnode->setNext(head);
    newnode->setPrev(nullptr);
    if (head != nullptr)
      head->setPrev(newnode);
    head=newnode;
    cur=newnode;
    size++;
  }
  else if (loc > size || loc < 0)
    std::cout <<"location out of bounds"<< std::endl;

  else if (loc <= size/2)
  {
    cur = head;
    int count = 1;
    while (count != loc)
    {
      cur = cur->getNext();
      count++;
    }
    Dnode *insert = new Dnode(data);
    insert->setNext(cur->getNext());
    cur->setNext(insert);
    insert->setPrev(cur);
    insert->getNext()->setPrev(insert);
    size++;
  }

  else if (loc > size/2 && loc <size)
  {
    int count = size-1;
    cur = tail;
    while (count != loc){
      cur = cur->getPrev();
      count--;
    }

    Dnode *insert = new Dnode(data);
    insert->setPrev(cur->getPrev());
    insert->setNext(cur);
    cur->setPrev(insert);
    insert->getPrev()->setNext(insert);
    size++;
  }

  else if (loc = size)
  {
    Dnode *insert = new Dnode(data);
    cur = tail;
    insert->setNext(nullptr);
    cur->setNext(insert);
    insert->setPrev(cur);
    size++;
  }
}

void Dlist::remove(int loc)
{
  if (loc == 0)
  {
    head = head->getNext();
    size--;
  }
  else if (loc>=size || loc<0)
  {
    std::cout<<"out of bounds" <<std::endl;
  }
  else if (loc <= size/2)
  {
    cur = head;
    int count = 1;
    while (count != loc)
    {
      if (cur->getNext()->getNext() == nullptr)
      {
        std::cout<<"out of bounds"<<std::endl;
        return;
      }
      cur = cur->getNext();
      count++;
    }
    cur->setNext(cur->getNext()->getNext());
    size--;
  }
  else if (loc > size/2 && loc < size)
  {
    cur = tail;
    int count = size-1;
    while (count != loc){
      if (cur->getPrev()->getPrev() == nullptr)
      {
        std::cout <<"out of bounds"<<std::endl;
        return;
      }
      cur = cur->getPrev();
      count--;
    }
    cur->getPrev()->setNext(cur->getNext());
    size--;
  }
  else if (loc  == size-1)
  {
    cur = tail;
    cur->setPrev(cur->getPrev()->getPrev());
    size--;
  }
}

std::string Dlist::get(int loc)
{
  if (loc == 0)
  {
    cur = head;
    return cur->getData();
  }

  else if (loc >= size || loc < 0)
  {
    return "Location out of bounds";
  }

  if (loc <= size/2)
  {
    int count = 0;
    cur = head;
    while (count != loc){
      cur = cur->getNext();
      count ++;
    }
    return cur->getData();
  }

  else if (loc > size/2)
  {
    int count = size-1;
    cur = tail;
    while(count != loc)
    {
      cur = cur->getPrev();
      count--;
    }
  }
  return cur->getData();
}

