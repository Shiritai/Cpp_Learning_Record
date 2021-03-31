# include <iostream>
# include "SortDataGen01.h"
# include "basic_sorts.h"

using namespace std;

class Merge {
public:
    // 公開呼叫，支持多型，傳入陣列與元素個數
    template<typename T>
    static void merge_sort(T arr[], int n){
        Merge::split(arr, 0, n - 1);
    }
private:
    template<typename T>
    // 遞迴切割到剩一個元素，私有
    static void split(T arr[], int l, int r){
        if (l >= r)
            return;
        int mid = (l + r) / 2; // 注意曾經發生過 l + r 太大溢位的事故...
        Merge::split(arr, l, mid);
        Merge::split(arr, mid + 1, r);
        if (arr[mid] > arr[mid + 1]) // Optimize, 只有此時才要合併，否則代表已經排序好了
            Merge::merge(arr, l, mid, r);
    }
    // 合併 arr[l~mid], arr[mid+1 ~ r]
    template<typename T>
    static void merge(T arr[], int l, int mid, int r){
        T aux[r - l + 1]; // aux = auxilary
        /* 複製 arr 到 aux */
        for (int i = l; i <= r; ++i)
            aux[i - l] = arr[i];
        for (int l_min = l, r_min = mid + 1, i = l; i <= r; ++i){
            /* 確認索引是否合法，換言之，是否左/右其中一邊已經合併完成 */
            if (l_min > mid || r_min > r){
                for (int * move = (l_min > mid) ? &r_min : &l_min; i <= r; ++i, ++(* move))
                    arr[i] = aux[(* move) - l];
            }
            /* 左小 */
            else if (aux[l_min - l] < aux[r_min - l]){
                arr[i] = aux[l_min - l];
                ++l_min;
            }
            /* 右小 */
            else {
                arr[i] = aux[r_min - l];
                ++r_min;
            }
        }
    }
};

int main(void){
    int n = 100000;
    int * arr1 = SortDataGen01::gen_ram_arr(n, 0, n);
    int * arr2 = SortDataGen01::copyArray(arr1, n);
    int * arr3 = SortDataGen01::copyArray(arr1, n);
    int * arr4 = SortDataGen01::copyArray(arr1, n);
    int * arr5 = SortDataGen01::copyArray(arr1, n);

    cout << "Size : " << n << endl;

    SortDataGen01::sortTimeTest("Bubble Sort", basic_sorts::bubble_sort, arr4, n);
    SortDataGen01::sortTimeTest("Selection Sort", basic_sorts::selection_sort, arr2, n);
    SortDataGen01::sortTimeTest("Insertion Sort", basic_sorts::insertion_sort, arr1, n);
    SortDataGen01::sortTimeTest("Shell Sort", basic_sorts::shell_sort, arr3, n);
    SortDataGen01::sortTimeTest("Merge Sort", Merge::merge_sort, arr5, n);

    int swaps = 1024;
    int * arr1_ = SortDataGen01::gen_nearly_sorted_arr(n, swaps);
    int * arr2_ = SortDataGen01::copyArray(arr1_, n);
    int * arr3_ = SortDataGen01::copyArray(arr1_, n);
    int * arr4_ = SortDataGen01::copyArray(arr1_, n);
    int * arr5_ = SortDataGen01::copyArray(arr1_, n);

    cout << endl << "Size : " << n << ", Swap Times : " << swaps << endl;

    SortDataGen01::sortTimeTest("Bubble Sort", basic_sorts::bubble_sort, arr4_, n);
    SortDataGen01::sortTimeTest("Selection Sort", basic_sorts::selection_sort, arr2_, n);
    SortDataGen01::sortTimeTest("Insertion Sort", basic_sorts::insertion_sort, arr1_, n);
    SortDataGen01::sortTimeTest("Shell Sort", basic_sorts::shell_sort, arr3_, n);
    SortDataGen01::sortTimeTest("Merge Sort", Merge::merge_sort, arr5_, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    delete[] arr1_;
    delete[] arr2_;
    delete[] arr3_;
    delete[] arr4_;
    delete[] arr5_;
}