main: main.cpp SparseMatrix.o
	g++ main.cpp SparseMatrix.o -o main -Wall -O2 -m64 -static-libgcc -std=c++17 -fexec-charset=BIG5

SparseMatrix.o: SparseMatrix.cpp
	g++ -c SparseMatrix.cpp
	 
clean:
	rm *.o main