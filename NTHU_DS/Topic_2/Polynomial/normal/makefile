main: main.cpp Polynomial.o
	g++ main.cpp Polynomial.o -o main -Wall -O2 -m64 -static-libgcc -std=c++17 -fexec-charset=BIG5

Polynomial.o: Polynomial.cpp
	g++ -c Polynomial.cpp
	 
clean:
	rm *.o main