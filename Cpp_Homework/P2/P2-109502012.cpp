# include <iostream>
# include <string>

using namespace std;

class Student{
public:
    Student(string ID, string name, int score){
        this->ID = ID;
        this->name = name;
        this->score = score;
    }

    string getId(){return ID;}
    string getName(){return name;}
    int getScore(){return score;}

    void changeScore(int new_score){
        this->score = new_score;
        return;
    }

private:
    string ID;
    string name;
    int score;
};

//do something

int main()
{
    Student student1 = Student("109123456", "Alex", 90);
    Student student2 = Student("109876543", "Kiki", 75);

    cout << "Before" << endl;
    cout << student1.getId() << " : " << student1.getName() << " : " << student1.getScore() << endl;
    cout << student2.getId() << " : " << student2.getName() << " : " << student2.getScore() << endl;

    student1.changeScore(61);
    student2.changeScore(89);

    cout << "After" << endl;
    cout << student1.getId() << " : " << student1.getName() << " : " << student1.getScore() << endl;
    cout << student2.getId() << " : " << student2.getName() << " : " << student2.getScore() << endl;

    return 0;
}