# ifndef BASIC_SORTS_H
# define BASIC_SORTS_H

// # include <iostream>
// # include "SortDataGen01.h"

using namespace std;

namespace basic_sorts{

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
        int min_ind, max_ind; // find min and max value in the range of [i, n - i)
        for (int i = 0; i < n / 2; ++i){
            min_ind = i, max_ind = n - i - 1;
            for (int j = i + 1; j < n - i; ++j){
                min_ind = (arr[j] < arr[min_ind]) ? j : min_ind;
                max_ind = (arr[j] > arr[max_ind]) ? j : max_ind;
            }
            swap(arr[i], arr[min_ind]);
            swap(arr[n - i - 1], arr[max_ind]);
        }
    }

    template <typename T>
    void shell_sort(T arr[], int n){
        int span = 1;
        while (span <= (n >> 2))
            span <<= 1;

        for (int i = span; i >= 1; i >>= 1){ // 跨度漸減
            for (int j = 0; j < n - i; ++j){
                /* 對 arr[j + span] 用插入排序 */
                int swap_to_low = j;
                while (arr[swap_to_low] > arr[swap_to_low + i]){
                    swap(arr[swap_to_low], arr[swap_to_low + i]);
                    swap_to_low -= i;
                    if (swap_to_low < 0)
                        break;
                }
            }
        }
    }

    /* Advance version of bubble sort */
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