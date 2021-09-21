# include "Polynomial.h"
# include <iostream>

using namespace std;

int main(void){
    Polynomial pl1, pl2;

    pl1.add_term(1, 2);
    pl1.add_term(5, 6);
    pl1.add_term(3, 4);
    pl2.add_term(1, 6);
    pl2.add_term(3, 8);

    cout << pl1.to_string() << endl << endl;
    cout << pl2.to_string() << endl << endl;
    cout << (pl1 + pl2).to_string() << endl << endl;
}