OBJECTS=main.o List.o Node.o Dnode.o Dlist.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o List.o Node.o Dnode.o Dlist.o
	$(CXX) -o main $(OBJECTS)

tests: tests.o List.o Node.o Dnode.o Dlist.o
		$(CXX) -o tests tests.o List.o Node.o Dnode.o Dlist.o

main.o: main.cpp List.h

tests.o: tests.cpp doctest.h List.h Node.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

Dlist.o: Dlist.cpp Dlist.h Dnode.o

Dnode.o: Dnode.cpp Dnode.h

clean:
	rm -f Dnode.o Dlist.o Node.o List.o tests.o main.o main tests
