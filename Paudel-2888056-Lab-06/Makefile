exercise1: main.o Exec.o MinMaxHeap.tpp MinMaxHeap.h
	g++ -std=c++11 -g -Wall main.o Exec.o -o exercise1

main.o: main.cpp Exec.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Exec.o: Exec.h Exec.cpp MinMaxHeap.tpp
	g++ -std=c++11 -g -Wall -c Exec.cpp

clean:
	rm *.o exercise1
