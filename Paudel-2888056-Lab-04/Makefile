/lab4: main.o Exec.o BinaryNodeTree.o
	g++ -std=c++11 -g -Wall main.o Exec.o BinaryNodeTree.o -o lab4

main.o: main.cpp Exec.h BinaryNode.h BinaryNodeTree.h
	g++ -std=c++11 -g -Wall -c main.cpp

Exec.o: Exec.h Exec.cpp BinaryNodeTree.h BinaryNode.h
	g++ -std=c++11 -g -Wall -c Exec.cpp

clean:
	rm *.o lab4
