// Basic use of STL vector
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define PRINT(x)	{cout << #x << " = " << x << endl;}

// Print a vec
template <class T>
void vecPrint(vector<T> vec, char *vecName){
	typename vector<T>::iterator i;
	cout << vecName << " = ";
	for (i=vec.begin(); i!=vec.end(); i++)
		cout << *i << " ";
	cout << endl;
}

int main(){
	// Create a vector, initialized by an array
	int cArray[] = {9,3,7,8,8,6,8,2,2,5};
	int vecLen = sizeof(cArray)/sizeof(int);
	PRINT(vecLen);
	vector<int> vec1(cArray, cArray+vecLen);
	vecPrint(vec1, "vec1");
	// Write STL vector
	FILE *outputFile = fopen ("vecWrite.bin", "wb");
	fwrite(vec1.data(), sizeof(decltype(vec1)::value_type), vec1.size(), outputFile);
	fclose(outputFile);
	return 0;
}