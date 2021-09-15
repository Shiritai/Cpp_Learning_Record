# include <iostream> 

# define A_CON 1
# define A_DE 5
# define B_CON 2
# define B_DE 4
# define C_CON 3

using namespace std;

class A {
public:
    A(){ cout << A_CON << endl; }
    ~A(){ cout << A_DE << endl; }
};

class B : public A {
public:
    B(){ cout << B_CON << endl; }
    ~B(){ cout << B_DE << endl; }
};

class C : public B {
public:
    C(){ cout << C_CON << endl; }
};

int main(void){
    C c;
}