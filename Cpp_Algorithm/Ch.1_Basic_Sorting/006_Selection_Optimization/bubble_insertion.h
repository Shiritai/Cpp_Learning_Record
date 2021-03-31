# ifndef SELECTION_INSERTION_H
# define SELECTION_INSERTION_H

# include <iostream>

using namespace std;

namespace bubble_insertion{

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
    void bubble_sort(T arr[], int n){
        int lastSwap; // Optimization 2
        for (int i = n - 1; i > 0; --i){
            lastSwap = 0;
            for (int j = 0; j < i; ++j){
                if (arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                    /* 紀錄最後一次交換的位置，因為之後的都已經排序完畢 */
                    lastSwap = j + 1;
                }
            }
            i = lastSwap; // 下次排序時，從 i = lastSwap + 1 到 i = n 都已經排好了
        }
    }
}

# endif