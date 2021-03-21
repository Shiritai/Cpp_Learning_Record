# include <iostream>
# include "SortDataGen01.h"
# include "bubble_insertion.h"

using namespace std;

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

    SortDataGen01::sortTimeTest("Selection", selection_sort, a, nums);
    SortDataGen01::sortTimeTest("Insertion", bubble_insertion::insertion_sort, a2, nums);
    SortDataGen01::sortTimeTest("Bubble", bubble_insertion::bubble_sort, a3, nums); // 扶不起啊...

    delete[] a;

    delete[] a2;
}