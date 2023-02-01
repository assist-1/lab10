all: lab10
lab10: lab10.o
	g++ lab10.o -o lab10
lab10.o: lab10.cpp	
	g++ -c lab10.cpp
clean: 
	rm *.o

