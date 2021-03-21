# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

enum Subject
{
    CHINESE,
    MATH,
    SCIENCE,
    ENGLISH,
    LENGTH
};

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

class students {
public:
    student
}

int main(void)
{
    
}