# include <iostream>
# include <string>
# include <map>
# include <time.h>

using namespace std;

int main(void){
    // auto mapPtr = new map<int, int>();
    map<int, int> map;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i){
        map.insert(pair<int, int>(rand() % 1000, rand() % 1000));
    }
    for (auto i = map.begin(); i != map.end(); ++i){
        cout << i->first << " " << i->second << endl;
    }
}