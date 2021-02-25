#include <iostream>

#include "List.h"


List::List(){
  head = nullptr;
  
}

void List::insert(std::string data){
  // create a new node
  Node *new_node = new Node(data);

  // insert the new node
  new_node->setNext(head);
  head=new_node;
  }


std::string List::toString(){
  Node *walker = head;
  std::string s = "";
  while (walker != nullptr){
    s = s + walker->getData() + "-->";
    walker = walker->getNext();
    
  }
  s=s+"nullptr";
  return s;
  
}

void List::insert(int loc, std::string data)
{
  if(loc < 0)
    return;
  Node *updated_node = new Node(data);
  Node *walker = head;
  if(loc == 0)
    insert(data);
  else
  {
    int i = 0;
    while(walker != nullptr)
    {
      if(i == loc-1)
      {
        updated_node->setNext(walker->getNext());
        walker->setNext(updated_node);
      }
      i++;
      walker = walker->getNext();
    }
  }
}

void List::remove(int loc)
{
  if(loc < 0)
    return;
  Node *removed_node = new Node();
  Node *walker = head;

  if(loc == 0)
  {
    removed_node->setNext(head);
    head = removed_node;
  }
  else
  {
    for(int i = 0; i < loc-1; i++)
    {
      if(walker->getNext()->getNext() == nullptr)
        return;
      walker = walker->getNext(); //might be able to say walker->getNext() here
    }
    walker->setNext(walker->getNext()->getNext());
  }
}

std::string List::get(int loc)
{
  if(loc < 0)
    return "Invalid location";
  Node *walker = head;
  if(loc == 0)
    return walker->getData();
  else
  {
    for(int i = 0; i < loc; i++)
    {
      if(walker->getNext() == nullptr)
        return "Invalid location";
      walker = walker->getNext();
    }
    return walker->getData();
  }
}

List::~List()
{
  Node *curr = new Node();
  Node *walker = head;
  while(walker != NULL)
  {
    curr = walker->getNext();
    delete walker;
    walker = curr;
  }
}





