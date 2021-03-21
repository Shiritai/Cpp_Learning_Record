/* 插入排序：插入元素到適合的位置 */
# include <iostream>
# include "SortDataGen01.h"

using namespace std;

template <typename T>
void insertion_sort(T arr[], int n){
    for (int i = 1; i < n; ++i){
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; --j){
            swap(arr[j], arr[j + 1]);
        }
    }
}

int main(void){
    const int nums = 100000;
    int * a = SortDataGen01::gen_ram_arr(nums, 0, 2 * nums);
    // insertion_sort(a, nums);
    // SortDataGen01::printArray(a, nums);
    SortDataGen01::sortTimeTest("Insertion sort", insertion_sort, a, nums);
    delete [] a;
    return 0;
}