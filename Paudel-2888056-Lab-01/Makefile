exercise1: main.o Exec.o
	g++ -std=c++11 -g -Wall main.o Exec.o -o exercise1

main.o: main.cpp LinkedList.h LinkedList.cpp Node.h Exec.h
	g++ -std=c++11 -g -Wall -c main.cpp

Exec.o: Exec.h Exec.cpp LinkedList.h Node.h
	g++ -std=c++11 -g -Wall -c Exec.cpp

clean:
	rm *.o exercise1
