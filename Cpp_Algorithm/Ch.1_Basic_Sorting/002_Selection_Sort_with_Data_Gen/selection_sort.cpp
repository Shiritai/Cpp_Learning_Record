# include <iostream>
# include "SortDataGen01.h"

using namespace std;

void sel_sort(int arr[], int n){
    for (int i = 0; i < n; ++i){
        int min_ind = i; // find minimal val in the range of [i, n)
        for (int j = i + 1; j < n; ++j)
            min_ind = (arr[j] < arr[min_ind]) ? j : min_ind;
        if (i != min_ind)
            arr[i] ^= arr[min_ind] ^= arr[i] ^= arr[min_ind]; // 注意自己 XOR 自己必 = 0
        // swap(arr[i], arr[min_ind]); // 當然有 swap 這麼香的東西...用了不虧
    }
}

int main(void){
    const int nums = 100000;
    int * a = SortDataGen01::gen_ram_arr(nums, 10, 99);
    // sel_sort(a, nums);
    // SortDataGen01::printArray(a, nums);
    SortDataGen01::sortTimeTest("Selection sort", sel_sort, a, nums);
    delete[] a;
}