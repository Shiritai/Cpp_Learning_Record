# include <iostream>

using namespace std;

void func(int a, int & b, int * c){
    a += 4;
    b += 10; //+ b = 15
    * c = a; //+ *c = 7 = b
}

int main(void){
    int a = 3, b = 5, * c = &b;
    func(a, b, c);
    cout << a << endl;
    cout << b << endl;
    cout << (* c) << endl;
}
/* 
a, b, out
0, 0, 2
0, 1, 1
0, 1, 2
      1
 */