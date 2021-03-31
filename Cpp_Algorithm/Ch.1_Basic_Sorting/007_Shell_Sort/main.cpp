/* shell sort folk dance : https://youtu.be/CmPA7zE8mx0 */
# include <iostream>
# include "SortDataGen01.h"
# include "selection_insertion.h"

using namespace std;

void shell_sort(int arr[], int n){
    int span = 1;
    while (span <= (n >> 2))
        span <<= 1;

    for (int i = span; i >= 1; i >>= 1){ // 跨度漸減
        for (int j = 0; j < n - i; ++j){
            /* 對 arr[j + span] 用插入排序 */
            int swap_to_low = j;
            while (arr[swap_to_low] > arr[swap_to_low + i]){
                // cout << "swap(" << arr[swap_to_low] << ", " << arr[swap_to_low + i] << ")";
                swap(arr[swap_to_low], arr[swap_to_low + i]);
                // cout << " --> (" << arr[swap_to_low] << ", " << arr[swap_to_low + i] << ")\n";
                swap_to_low -= i;
                if (swap_to_low < 0)
                    break;
            }
        }
        // SortDataGen01::printArray(arr, n);
    }
}

int main(void){
    const int nums = 100000;
    int * a = SortDataGen01::gen_ram_arr(nums, 0, nums);
    // SortDataGen01::printArray(a, nums);
    // shell_sort(a, nums);
    // SortDataGen01::printArray(a, nums);

    int * a2 = SortDataGen01::copyArray(a, nums);
    int * a3 = SortDataGen01::copyArray(a, nums);

    cout << "Sort numbers : " << nums << endl;
    SortDataGen01::sortTimeTest("Shell", shell_sort, a, nums);
    SortDataGen01::sortTimeTest("Insertion", selection_insertion::insertion_sort, a2, nums);
    SortDataGen01::sortTimeTest("Selection", selection_insertion::selection_sort, a3, nums);

    const int swap_num = nums / 10;
    cout << "\nNearly ordered with numbers : " << nums << ", swapped pairs : " << swap_num << endl;
    int * a_ = SortDataGen01::gen_nearly_sorted_arr(nums, swap_num);
    int * a_2 = SortDataGen01::copyArray(a_, nums);
    int * a_3 = SortDataGen01::copyArray(a_, nums);

    SortDataGen01::sortTimeTest("Shell", shell_sort, a_, nums);
    SortDataGen01::sortTimeTest("Insertion", selection_insertion::insertion_sort, a_2, nums);
    SortDataGen01::sortTimeTest("Selection", selection_insertion::selection_sort, a_3, nums);

    delete[] a;
    delete[] a2;
    delete[] a3;
    delete[] a_;
    delete[] a_2;
    delete[] a_3;
}