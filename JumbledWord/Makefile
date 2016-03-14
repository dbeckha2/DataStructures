
all: jumble

clean:
	 rm *.o jumble

jumble: jumble.o BST.o
	g++ -o jumble jumble.o BST.o

jumble.o: jumble.cpp BST.h
	g++ -c jumble.cpp

BST.o: BST.h BST.cpp
	g++ -c BST.cpp

