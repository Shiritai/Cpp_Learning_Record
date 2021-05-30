// Demo of shallow copy, with double deletions
#include <cstdlib>
#include <iostream>
using namespace std;

class student {
	public:
		student(int n=3){count=n; score=new int[count];};
		~student(){delete [] score;};
		void print();	// Print score
		int *score, count;
		string name;
};

void student::print(){
	cout << "name=" << name.c_str() << ", ";
	cout << "score=[";
	for (int i=0; i<count; i++)
		cout << score[i] << " ";
	cout << "]" << endl;
}

int main(){
	student a(3);
	a.name="John"; a.score[0]=70; a.score[1]=60; a.score[2]=30;
	cout << "a: "; a.print();
	student b=a;	// Copy constructor
	b.name="Mary"; b.score[2]=90;

	cout << "Address of a.score: " << a.score << endl;
	cout << "Address of b.score: " << b.score << endl;
	cout << "a: "; a.print();
	cout << "b: "; b.print();

	return EXIT_SUCCESS;
}
