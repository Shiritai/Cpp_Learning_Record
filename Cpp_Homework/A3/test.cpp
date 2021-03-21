# include <iostream>
# include <string>
# include <vector>
# include <string.h>
# include <algorithm>

# define INSERT 1
# define CHANGE_SCORE 2
# define PRINT_ALL 3
# define DELETE 4
# define EXIT 5
# define four_kill_five_add_two_dec fKfA

using namespace std;

enum Subject
{
    CHINESE,
    MATH,
    SCIENCE,
    ENGLISH,
    LENGTH
};


int subject_check(int sub){
    if (sub >= 0 && sub < 4)
        return sub;
    else 
        return LENGTH;
}

float four_kill_five_add_two_dec(float num){
    if (((int) (num * 1000)) % 10 <= 4)
        return ((int) (num * 100)) / 100.;
    else 
        return ((int) (num * 100 + 1)) / 100.;
}

class student
{
private:
    string ID;
    string name;
    int score[LENGTH];
    float avg;

public:
    student(string ID, string name, int ChineseScore, int MathScore, int ScienceScore, int EnglishScore)
    {
        this->ID = ID;
        this->name = name;
        this->score[CHINESE] = ChineseScore;
        this->score[MATH] = MathScore;
        this->score[SCIENCE] = ScienceScore;
        this->score[ENGLISH] = EnglishScore;
        int tmp = 0;
        for (int i = 0; i < LENGTH; ++i){
            tmp += score[i];
        }
        this->avg = (float) tmp / LENGTH;
    }

    void changeScore(int sub, int score){
        switch (sub){
            case CHINESE:
                this->score[CHINESE] = score;
                break;
            case MATH:
                this->score[MATH] = score;
                break;
            case SCIENCE:
                this->score[SCIENCE] = score;
                break;
            case ENGLISH:
                this->score[ENGLISH] = score;
                break;
            default:
                this->score[LENGTH] = score;
                break;
        }
    }

    string toString(){
        char tmp[1000];
        sprintf(tmp, "%s %s %d %d %d %d %.2f", ID.c_str(), name.c_str(), score[CHINESE], score[MATH], score[SCIENCE], score[ENGLISH], fKfA(avg));
        string buf = string(tmp);
        return buf;
    }

    string getID(){return ID;}
    string getName(){return name;}
    int getChiSco(){return score[CHINESE];}
    int getMatSco(){return score[ENGLISH];}
    int getSciSco(){return score[SCIENCE];}
    int getEngSco(){return score[ENGLISH];}
};

bool idComp(student data1, student data2){
    if (strcmp(data1.getID().c_str(), data2.getID().c_str()) == 1)
        return true;
    else
        return false;
}

int main(void)
{
    vector<student> data;
    data.push_back(student("123", "Senjyougahara", 97, 91, 96, 94));
    data.push_back(student("128", "Hanekawa", 100, 100, 100, 99));
    data.push_back(student("016", "Hatikuji", 85, 77, 76, 82));
    data.push_back(student("052", "Nadeko", 60, 61, 62, 63));
    
    for (auto i = data.begin(); i != data.end(); ++i) // i : vector<student>::iterator
        cout << (*i).toString() << endl;
    // cout << data[0].toString() << endl;
    // cout << data[1].toString() << endl;
    // cout << data[2].toString() << endl;
    // cout << data[3].toString() << endl;

    cout << endl;

    /* lambda function */
    sort(data.begin(), data.end(), [](student data1, student data2){
        if (strcmp(data1.getID().c_str(), data2.getID().c_str()) == 1)
            return false;
        else
            return true;
    });
    // sort(data.begin(), data.end(), idComp);
    // qsort(&data[0], data.size(), sizeof(student), idComp);
    
    for (auto i = data.begin(); i != data.end(); ++i) // i : vector<student>::iterator
        cout << (*i).toString() << endl;

    // cout << data[0].toString() << endl;
    // cout << data[1].toString() << endl;
    // cout << data[2].toString() << endl;
    // cout << data[3].toString() << endl;
}