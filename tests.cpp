#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"
#include "Node.h"


List *l1 = new List();


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

