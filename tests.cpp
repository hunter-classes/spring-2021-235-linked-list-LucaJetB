#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"
#include "Node.h"
#include "Dlist.h"

List *l1 = new List();
Dlist *l2 = new Dlist();

TEST_CASE("insert")
{
	l1->insert("a");
	l1->insert("b");
	l1->insert("c");
	l1->insert("d");
	CHECK(l1->toString() == "d-->c-->b-->a-->nullptr");
	l1->insert(2,"e");
	CHECK(l1->toString() == "d-->c-->e-->b-->a-->nullptr");
}

TEST_CASE("remove")
{
	l1->remove(1);
	CHECK(l1->toString() == "d-->e-->b-->a-->nullptr");
	l1->remove(-1);
	CHECK(l1->toString() == "d-->e-->b-->a-->nullptr");
}

TEST_CASE("get")
{
	CHECK(l1->get(1) == "e");
	CHECK(l1->get(-1) == "Invalid location");
	CHECK(l1->get(543) == "Invalid location");
}

TEST_CASE("Insert")
{
  l2->insert("a");
  l2->insert("b");
  l2->insert("c");
  CHECK(l2->toString() == "a<->b<->c<->nullptr");
  l2->insert(1,"r");
  CHECK(l2->toString() == "a<->r<->b<->c<->nullptr");
}

TEST_CASE("Remove")
{
  l2->remove(2);
  CHECK(l2->toString() == "a<->r<->c<->nullptr");
  l2->remove(0);
  CHECK(l2->toString() == "r<->c<->nullptr");
}

TEST_CASE("get")
{
  CHECK(l2->get(0) == "r");
  CHECK(l2->get(1) == "c");
  l2->insert(1,"x");
  CHECK(l2->get(1) == "x");
  CHECK(l2->get(2) == "c");
  CHECK(l2->get(3) == "Location out of bounds");
}

