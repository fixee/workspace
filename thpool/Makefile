
all: tasklist.o main.o
	g++ -lpthread tasklist.o main.o -o exe 

tasklist.o: tasklist.h tasklist.cpp
	g++ -lpthread -c tasklist.cpp 

main.o: main.cpp
	g++ -lpthread -c main.cpp

clean:
	rm -rf *.o
