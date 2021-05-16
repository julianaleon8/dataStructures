CC = g++

all: main 

main: main.o array.o
	g++ -o main main.o array.o

main.o: main.cpp
	g++ -c main.cpp

array.o: array.cpp
	g++ -c array.cpp

clean:
	rm .\main.o
	rm .\array.o