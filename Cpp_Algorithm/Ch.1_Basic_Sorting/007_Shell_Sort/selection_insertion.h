# ifndef SELECTION_INSERTION_H
# define SELECTION_INSERTION_H

# include <iostream>
# include "SortDataGen01.h"

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

    void selection_sort(int arr[], int n){
        int min_ind, max_ind; // find min and max value in the range of [i, n - i)
        for (int i = 0; i < n / 2; ++i){
            min_ind = i, max_ind = n - i - 1;
            for (int j = i + 1; j < n - i; ++j){
                min_ind = (arr[j] < arr[min_ind]) ? j : min_ind;
                max_ind = (arr[j] > arr[max_ind]) ? j : max_ind;
            }
            // cout << "min : " << arr[min_ind] << ", max : " << arr[max_ind] << endl;
            swap(arr[i], arr[min_ind]);
            swap(arr[n - i - 1], arr[max_ind]);
            // SortDataGen01::printArray(arr, n);
        }
    }
}

# endif