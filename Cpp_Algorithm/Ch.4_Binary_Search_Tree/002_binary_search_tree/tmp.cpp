# include <iostream>
# include <string>
# include <vector>
# include "BST.h"

using namespace std;

int main(void){
    BST<string, int> bst = BST<string, int>();
    vector<string> words;
    words.push_back("Meow");
    words.push_back("Meow1");
    words.push_back("Meow");
    words.push_back("Meow2");
    for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
        int *res = bst.searchNonRecur(*iter);
        if (res == NULL)
            bst.insertNonRecur(*iter, 1);
        else
            (*res)++;
        cout << bst.size() << endl;
    }
    cout << bst.size() << endl;
    cout << bst.containNonRecur("Meow") << endl;
    cout << bst.containNonRecur("Meow3") << endl;
}