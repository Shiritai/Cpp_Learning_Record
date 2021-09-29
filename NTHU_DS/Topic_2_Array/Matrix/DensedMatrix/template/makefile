main: main.cpp Matrix.o
	g++ main.cpp Matrix.o -o main -Wall -O2 -m64 -static-libgcc -std=c++17 -fexec-charset=BIG5

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp
	 
clean:
	rm *.o main