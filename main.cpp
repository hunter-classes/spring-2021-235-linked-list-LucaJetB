#include <iostream>
#include "Dlist.h"
#include "List.h"
int main(int argc, char *argv[])
{

  List *l1 = new List();
  std::cout << l1->toString() << "\n";

  l1->insert("a");
  l1->insert("b");
  l1->insert("c");
  std::cout << l1->toString() << "\n";
  std::cout << l1->get(3) << std::endl;

  List *l2 = new List();
  l2->insert("a");
  l2->insert("b");
  l2->insert("c");
  l2->insert(1,"d");
  std::cout << l2->toString() << std::endl;
  l2->remove(3);
  std::cout << l2->toString() << std::endl;

  Dlist *l3 = new Dlist();
  std::cout << l3->toString() << std::endl;

  l3->insert("a");
  l3->insert("b");
  l3->insert("c");
  l3->insert(1,"X");
  std::cout << l3->toString() << std::endl;
  return 0;
}

