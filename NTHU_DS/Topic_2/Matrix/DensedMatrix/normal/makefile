main: main.cpp DensedMatrix.o
	g++ main.cpp DensedMatrix.o -o main -Wall -O2 -m64 -static-libgcc -std=c++17 -fexec-charset=BIG5

DensedMatrix.o: DensedMatrix.cpp
	g++ -c DensedMatrix.cpp
	 
clean:
	rm *.o main