# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

inline bool comp(int a, int b){ return a < b;}
class intVec {
public:
    intVec(){
        size = 0;
    }
    intVec(int size){
        this->size = size;
    }
    int getSize(){ return size;}

    friend ostream &operator<< (ostream &out, const intVec & tmp){
        out << "[";
        // for (int i = 0; i < tmp.size - 1; ++i)
        //     out << tmp.data[i] << ", ";
        // out << tmp.data[tmp.size - 1] << "]";
        for (int i = 0; i < tmp.size; ++i)
            out << tmp.data[i] << ", ";
        out << "\b\b]";
        return out;
    }

    friend istream &operator>> (istream &in, intVec & tmp){
        int tmpInt;
        for (int i = 0; i < tmp.size; ++i){
            in >> tmpInt;
            cout << tmpInt << endl;
            tmp.data.push_back(tmpInt);
        }
        return in;
    }

    friend intVec operator+ (intVec &tmp1, intVec &tmp2){
        intVec tmp = intVec(tmp1.size + tmp2.size);
        tmp.data.insert(tmp.data.end(), tmp1.data.begin(), tmp1.data.end());
        tmp.data.insert(tmp.data.end(), tmp2.data.begin(), tmp2.data.end());
        sort(tmp.data.begin(), tmp.data.end(), comp);
        return tmp;
    }
private:
    int size;
    vector<int> data;
};


int main(void){
    int size1, size2;
    cin >> size1 >> size2;
    intVec vec1 = intVec(size1), vec2 = intVec(size2);
    cin >> vec1;
    cin >> vec2;
    cout << vec1 << endl;
    cout << vec2 << endl;
    cout << (vec1 + vec2) << endl;
}