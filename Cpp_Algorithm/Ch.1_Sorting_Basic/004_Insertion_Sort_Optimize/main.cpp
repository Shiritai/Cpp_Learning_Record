/* 插入排序：插入元素到適合的位置 */
# include <iostream>
# include "SortDataGen01.h"

using namespace std;

template <typename T>
void insertion_sort(T arr[], int n){
    for (int i = 1; i < n; ++i){
        /* 若要換位，改成逐一覆蓋來取代 swap */
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

int main(void){
    const int nums = 100000;
    int * a = SortDataGen01::gen_nearly_sorted_arr(nums, nums / 5); // 非常有效率...
    // int * a = SortDataGen01::gen_ram_arr(nums, 0, nums); // 第三項引數對插入排序有不小影響
    // int * a = SortDataGen01::gen_ram_arr(nums, 0, nums / 2); // 第三項引數對插入排序有不小影響
    // int * a = SortDataGen01::gen_ram_arr(nums, 0, 0); // 第三項引數對插入排序有不小影響
    int * a2 = SortDataGen01::copyArray(a, nums);
    SortDataGen01::sortTimeTest("Selection sort", selection_sort, a, nums);
    SortDataGen01::sortTimeTest("Insertion sort", insertion_sort, a2, nums);
    cout << "Finally Insertion is faster than Selection.\n";
    delete [] a;
    delete [] a2;
    return 0;
}