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

enum Subject{
    CHINESE,
    MATH,
    SCIENCE,
    ENGLISH,
    LENGTH
};

float four_kill_five_add_two_dec(float num){
    if (((int) (num * 1000)) % 10 <= 4)
        return ((int) (num * 100)) / 100.;
    else 
        return ((int) (num * 100 + 1)) / 100.;
}

class student{
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
        int tmp = 0;
        for (int i = 0; i < LENGTH; ++i){
            tmp += this->score[i];
        }
        this->avg = (float) tmp / LENGTH;
    }

    string toString(){
        char tmp[1000];
        sprintf(tmp, "%s %s %d %d %d %d %.2f", ID.c_str(), name.c_str(), score[CHINESE], score[MATH], score[SCIENCE], score[ENGLISH], fKfA(avg));
        return string(tmp);
    }

    string getID(){return ID;}
    string getName(){return name;}
    int getChiSco(){return score[CHINESE];}
    int getMatSco(){return score[ENGLISH];}
    int getSciSco(){return score[SCIENCE];}
    int getEngSco(){return score[ENGLISH];}
};

int input(void){
    cin.sync(); // input optimization
    char buf[100];
    fgets(buf, 0x7fffffff, stdin);
    buf[strlen(buf) - 1] = '\0';
    int tmp = atoi(buf);
    return (tmp >= 1 && tmp <= 5) ? tmp : 0;
}

bool idComp(student data1, student data2){
    return (atoi(data1.getID().c_str()) > atoi(data2.getID().c_str())) ? false : true;
}

void console(void){
    int cmd = 0;
    vector<student> data;
    do
    {
        cout << "(1) Insert (2) Change score (3) Print all (4) Delete (5) Exit\n";
        cmd = input();
        switch (cmd){
            case INSERT:{
                string i, n;
                int c, m, s, e;
                cout << "Please enter student id/name/scores(Chinese/Math/Science/English)\n";
                cin >> i >> n >> c >> m >> s >> e;
                data.push_back(student(i, n, c, m, s, e));
                break;
            }
            case CHANGE_SCORE:{
                if (data.empty()){
                    cout << "There is no data now!\n";
                    break;
                }
                string tmpID;
                cout << "Please enter your student id\n";
                cin >> tmpID;
                int tmpSub, tmpScore;
                cout << "Which subject? (1) Chinese (2) Math (3) Science (4) English\n";
                cin >> tmpSub;
                cout << "Please enter new score\n";
                cin >> tmpScore;
                // for (int i = 0; i < data.size(); ++i){
                //     if (!strcmp(tmpID.c_str(), data[i].getID().c_str())){
                //         data[i].changeScore(tmpSub - 1, tmpScore); // notice here
                //         break;
                //     }
                // }
                bool valid = false;
                for (vector<student>::iterator i = data.begin(); i < data.end(); ++i){
                    if (!strcmp(tmpID.c_str(), (*i).getID().c_str())){
                        (*i).changeScore(tmpSub - 1, tmpScore); // notice here
                        valid = true;
                        break;
                    }
                }
                if (!valid)
                    cout << "Wrong id\n";
                break;
            }
            case PRINT_ALL:{
                /* sort vector using lambda function */
                // sort(data.begin(), data.end(), [](student data1, student data2){
                //     if (strcmp(data1.getID().c_str(), data2.getID().c_str()) == 1)
                //         return false;
                //     else
                //         return true;
                // });
                sort(data.begin(), data.end(), idComp);
                for (vector<student>::iterator i = data.begin(); i != data.end(); ++i) // i : vector<student>::iterator
                    cout << (*i).toString() << endl;
                // for (int i = 0; i < data.size(); ++i) // traditional iterate method
                    // cout << data[i].toString() << endl;
                break;
            }
            case DELETE:{
                if (data.empty()){
                    cout << "There is no data now!\n";
                    break;
                }
                string tmpID;
                cout << "Please enter student id\n";
                cin >> tmpID;
                bool flag = false;
                for (vector<student>::iterator i = data.begin(); i != data.end(); ++i){
                    if (!strcmp(tmpID.c_str(), (*i).getID().c_str())){
                        data.erase(i);
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    cout << "ID not found!\n";
                break;
            }
            case EXIT:{
                // Meow!
                break;
            }
            default:{ // cmd == 0
                cout << "Implicit command, please try again.\n";
                break;
            }
        }
    } while (cmd != 5);
}

int main(void)
{
    console();
}