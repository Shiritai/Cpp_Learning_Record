# ifndef STUDENT_H
# define STUDENT_H

# include <iostream>
# include <string>

using namespace std;

struct Student{

    string name;
    int score;

    /* Override "<" */
    // front : 1. higher score 2. dictionary sort name
    bool operator <(const Student &otherStudent){
        return score != otherStudent.score ? score > otherStudent.score : name < otherStudent.name;
    }

    /* Override "<<" */
    friend ostream & operator <<(ostream &buf, const Student &student){
        buf << "Student : " << student.name << " " << student.score << endl;
        return buf;
    }
};

# endif