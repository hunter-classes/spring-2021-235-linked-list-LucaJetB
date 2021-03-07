#pragma once
#include "Dnode.h"

class Dlist{
  private:
    Dnode *head;
    Dnode *tail;
    Dnode *cur;
    int size;
    int loc;
  public:
    Dlist();
    ~Dlist();
    std::string toString();
    void insert(std::string data);
    void insert(int loc, std::string data);
    void remove(int loc);
    std::string get(int loc);
    Dnode* goTo(int loc);
};

