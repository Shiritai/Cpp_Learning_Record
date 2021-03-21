# include <iostream>
# include <string>
# include "Student.h"

using namespace std;

template <typename T>

void sel_sort(T arr[], int n){
    for (int i = 0; i < n; ++i){
        int min_ind = i; // find minimal val in the range of [i, n)
        for (int j = i + 1; j < n; ++j)
            min_ind = (arr[j] < arr[min_ind]) ? j : min_ind;
        swap(arr[i], arr[min_ind]); // 當然有 swap 這麼香的東西...用了不虧，而且只有基本型變數可以用小花招...
    }
}

int main(void){
    /* int */
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sel_sort(a, 10);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    /* float */
    float b[4] = {4.4, 3.3, 2.2, 1.1};
    sel_sort(b, 4);
    for (int i = 0; i < 4; i++)
        cout << b[i] << " ";
    cout << endl;
    /* string */
    string c[4] = {"D", "C", "B", "A"};
    sel_sort(c, 4);
    for (int i = 0; i < 4; i++)
        cout << c[i] << " ";
    cout << endl;

    Student d[4] = {{"D", 90}, {"C", 100}, {"B", 95}, {"A", 95}};
    sel_sort(d, 4);
    for (int i = 0; i < 4; i++)
        cout << d[i];
    cout << endl;

    return 0;
}