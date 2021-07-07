CC = g++

all: main 

main: main.o array.o list.o graph.o treeBS.o
	g++ -o main main.o array.o list.o graph.o treeBS.o

main.o: main.cpp
	g++ -c main.cpp

array.o: array.cpp
	g++ -c array.cpp

list.o: list.cpp
	g++ -c list.cpp

graph.o: graph.cpp
	g++ -c graph.cpp

treeBS.o: treeBS.cpp
	g++ -c treeBS.cpp
	
clean:
	rm .\main.o
	rm .\array.o