# include <iostream>
# include "SortDataGen01.h"
# include "selection_insertion.h"

using namespace std;
using namespace selection_insertion;

template <typename T>
void bubble_sort1(T arr[], int n){
    bool swapped = true; // Optimization 1
    for (int i = n - 1; i > 0 && swapped; --i){
        swapped = false;
        for (int j = 0; j < i; ++j){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            //     arr[j] ^= arr[j + 1] ^= arr[j] ^= arr[j + 1];
        }
    }
}

template <typename T>
void bubble_sort2(T arr[], int n){
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

int main(void){
    const int nums = 100000;
    int * a = SortDataGen01::gen_ram_arr(nums, 0, nums);
    // SortDataGen01::printArray(a, nums);
    // bubble_sort2(a, nums);
    // SortDataGen01::printArray(a, nums);

    int * a2 = SortDataGen01::copyArray(a, nums);
    int * a3 = SortDataGen01::copyArray(a, nums);
    int * a4 = SortDataGen01::copyArray(a, nums);

    SortDataGen01::sortTimeTest("Bubble", bubble_sort1, a, nums);
    SortDataGen01::sortTimeTest("Bubble", bubble_sort2, a4, nums);
    SortDataGen01::sortTimeTest("Selection", selection_sort, a2, nums);
    SortDataGen01::sortTimeTest("Insertion", insertion_sort, a3, nums);

    delete[] a;

    delete[] a2;
    delete[] a3;
    delete[] a4;
}