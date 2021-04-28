./lab8: main.o Exec.o
	g++ -std=c++11 -g -Wall main.o Exec.o -o lab8

main.o: main.cpp Exec.h BinaryNode.h LeftistMinTree.h
	g++ -std=c++11 -g -Wall -c main.cpp

Exec.o: Exec.h Exec.cpp LeftistMinTree.h BinaryNode.h
	g++ -std=c++11 -g -Wall -c Exec.cpp

clean:
	rm *.o lab8