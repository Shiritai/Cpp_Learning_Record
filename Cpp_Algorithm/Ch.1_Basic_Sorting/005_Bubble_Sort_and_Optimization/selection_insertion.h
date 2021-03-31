# ifndef SELECTION_INSERTION_H
# define SELECTION_INSERTION_H

# include <iostream>

using namespace std;

namespace selection_insertion{

    template <typename T>
    void insertion_sort(T arr[], int n){
        for (int i = 1; i < n; ++i){
            /* 若要換位，改成覆蓋取代 swap */
            T tmp = arr[i];
            int j; // 即將插入點
            for (j = i - 1; j >= 0 && arr[j] > tmp; --j){
                arr[j + 1] = arr[j];
            }
            arr[j] = tmp;
        }
    }

    template <typename T>
    void selection_sort(T arr[], int n){
        for (int i = 0; i < n; ++i){
            int min_ind = i; // find minimal val in the range of [i, n)
            for (int j = i + 1; j < n; ++j)
                min_ind = (arr[j] < arr[min_ind]) ? j : min_ind;
            swap(arr[i], arr[min_ind]); // 當然有 swap 這麼香的東西...用了不虧，而且只有基本型變數可以用小花招...
        }
    }
}

# endif