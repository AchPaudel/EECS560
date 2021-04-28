exercise1: main.o Exec.o PriorityQueue.cpp PriorityQueue.h Heap.cpp Heap.h Requests.o
	g++ -std=c++11 -g -Wall main.o Exec.o Requests.o -o exercise1

main.o: main.cpp Exec.cpp Requests.cpp
	g++ -std=c++11 -g -Wall -c main.cpp


Requests.o: Requests.h Requests.cpp
	g++ -std=c++11 -g -Wall -c Requests.cpp

Exec.o: Exec.h Exec.cpp PriorityQueue.cpp Heap.cpp Requests.cpp
	g++ -std=c++11 -g -Wall -c Exec.cpp

clean:
	rm *.o exercise1