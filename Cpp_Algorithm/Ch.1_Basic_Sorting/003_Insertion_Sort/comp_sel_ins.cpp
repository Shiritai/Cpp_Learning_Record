/* 插入排序：插入元素到適合的位置 */
# include <iostream>
# include "SortDataGen01.h"

using namespace std;

template <typename T>
void insertion_sort(T arr[], int n){
    for (int i = 1; i < n; ++i){
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; --j){ // 有機會提前結束迴圈，增加效率
            swap(arr[j], arr[j + 1]);
        }
    }
}

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
    const int nums = 100000;
    int * a = SortDataGen01::gen_ram_arr(nums, 0, 2 * nums);
    int * a2 = SortDataGen01::copyArray(a, nums);
    // insertion_sort(a, nums);
    // SortDataGen01::printArray(a, nums);
    SortDataGen01::sortTimeTest("Selection sort", selection_sort, a, nums);
    SortDataGen01::sortTimeTest("Insertion sort", insertion_sort, a2, nums);
    cout << "Insertion is slower than Selection!? We need some optimizations.\n";
    delete [] a;
    delete [] a2;
    return 0;
}