# include <iostream>
# include <string>

using namespace std;

class fruit {
public:
    fruit(string name, int mass){
        this->name = name;
        this->mass = mass;
    }

    string getName(){return name;}
    int getMass(){return mass;}
    void changeMass(int newMass){this->mass = newMass;}

    friend bool compare(fruit &f1, fruit &f2){
        return f1.mass < f2.mass;
    }

    friend void swapMass(fruit &f1, fruit &f2){
        if (f1.mass > f2.mass)
            cout << f1.name << " > " << f2.name << endl;
        else
            cout << f2.name << " > " << f1.name << endl;
        int tmp = f1.mass;
        f1.mass = f2.mass;
        f2.mass = tmp;
    } 

private:
    string name;
    int mass;
};

int main(void){
    string n1, n2;
    int m1, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    fruit tmp[2] = {fruit(n1, m1), fruit(n2, m2)};
    cout << tmp[compare(tmp[0], tmp[1])].getName() << " is heavy\n";
    swapMass(tmp[0], tmp[1]);
    cout << tmp[compare(tmp[0], tmp[1])].getName() << " is heavy\n";
}