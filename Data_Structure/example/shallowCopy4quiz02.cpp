// Demo of shallow copy, with double deletions
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class student {
	public:
		student(){};
		~student(){};
		void print();	// Print score
		vector<int> score;
		string name;
};

void student::print(){
	cout << "name=" << name.c_str() << ", ";
	cout << "score=[";
	for (int i=0; i<score.size(); i++)
		cout << score[i] << " ";
	cout << "]" << endl;
}

int main(){
	student a;
	a.name="John"; a.score.push_back(70); a.score.push_back(60); a.score.push_back(30);
	cout << "a: "; a.print();
	student b=a;	// Copy constructor
	b.name="Mary"; b.score.push_back(90);

	cout << "Address of a.score: " << a.score << endl;
	cout << "Address of b.score: " << b.score << endl;
	cout << "a: "; a.print();
	cout << "b: "; b.print();

	return EXIT_SUCCESS;
}
