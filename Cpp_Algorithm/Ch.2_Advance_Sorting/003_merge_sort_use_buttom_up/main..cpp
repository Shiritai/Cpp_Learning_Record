# include <iostream>
# include "SortDataGen01.h"
# define min(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;

class Merge {
public:
    // 公開呼叫，支持多型，傳入陣列與元素個數
    template<typename T>
    static void merge_sort(T arr[], int n){
        /* *
         * Bottom up 的 Merge sort 會比 Recur 的還要慢一些
         * 注意此方法沒有使用到陣列的索引，因此適合拿來幫鏈結序列排序
         * */
        for (int size = 1; size < n; size <<= 1)
            for (int i = 0; i + size < n /* 確保 i + size 存在 */; i += (size << 1))
                Merge::merge(arr, i, i + size - 1, min(i + size + size - 1, n - 1));
    }
private:
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
    // int * arr2 = SortDataGen01::copyArray(arr1, n);
    // int * arr3 = SortDataGen01::copyArray(arr1, n);
    // int * arr4 = SortDataGen01::copyArray(arr1, n);
    // int * arr5 = SortDataGen01::copyArray(arr1, n);

    cout << "Size : " << n << endl;

    // SortDataGen01::sortTimeTest("Bubble Sort", basic_sorts::bubble_sort, arr4, n);
    // SortDataGen01::sortTimeTest("Selection Sort", basic_sorts::selection_sort, arr2, n);
    // SortDataGen01::sortTimeTest("Insertion Sort", basic_sorts::insertion_sort, arr1, n);
    // SortDataGen01::sortTimeTest("Shell Sort", basic_sorts::shell_sort, arr3, n);
    SortDataGen01::sortTimeTest("Merge Sort", Merge::merge_sort, arr1, n);

    // int swaps = 1024;
    // int * arr1_ = SortDataGen01::gen_nearly_sorted_arr(n, swaps);
    // int * arr2_ = SortDataGen01::copyArray(arr1_, n);
    // int * arr3_ = SortDataGen01::copyArray(arr1_, n);
    // int * arr4_ = SortDataGen01::copyArray(arr1_, n);
    // int * arr5_ = SortDataGen01::copyArray(arr1_, n);

    // cout << endl << "Size : " << n << ", Swap Times : " << swaps << endl;

    // SortDataGen01::sortTimeTest("Bubble Sort", basic_sorts::bubble_sort, arr4_, n);
    // SortDataGen01::sortTimeTest("Selection Sort", basic_sorts::selection_sort, arr2_, n);
    // SortDataGen01::sortTimeTest("Insertion Sort", basic_sorts::insertion_sort, arr1_, n);
    // SortDataGen01::sortTimeTest("Shell Sort", basic_sorts::shell_sort, arr3_, n);
    // SortDataGen01::sortTimeTest("Merge Sort", Merge::merge_sort, arr5_, n);

    delete[] arr1;
    // delete[] arr2;
    // delete[] arr3;
    // delete[] arr4;
    // delete[] arr5;

    // delete[] arr1_;
    // delete[] arr2_;
    // delete[] arr3_;
    // delete[] arr4_;
    // delete[] arr5_;
}