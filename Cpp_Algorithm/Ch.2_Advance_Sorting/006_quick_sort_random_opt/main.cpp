# include <iostream>
# include "Merge_Quick.h"
# include "SortDataGen01.h"

using namespace std;


class Quick_Insert {
public:
    template<typename T>
    static void quick_sort(T arr[], int n){
        /* Optimization, to avoid degeneration of qsort! */
        srand(time(NULL));
        Quick_Insert::q_sort(arr, 0, n - 1);
    }
private:
    /* user recursion to for partitioning */
    template<typename T>
    static void q_sort(T arr[], int l, int r){
        if (r - l <= 30){
            Quick_Insert::insertion_sort(arr, l, r);
            return;
        }
        int p = Quick_Insert::partition(arr, l, r); // 排序並獲得中間元素
        Quick_Insert::q_sort(arr, l, p - 1);
        Quick_Insert::q_sort(arr, p + 1, r);
    }

    /* *
     * Return the index p such that 
     * all the elements on the LHS are smaller than element p 
     * and all the elements on the RHS are bigger than element p
     * i.e. arr[l ~ p-1] < arr[p]
     * and arr[p+1 ~ r] > arr[p]
     */
    template<typename T>
    static int partition(T arr[], int l, int r){
        /* *
         * Optimization, use random index to avoid degeneration of qsort!
         * 藉由設置隨機索引種子，確保不會每次選擇索引時都選到最左邊的元素
         * 從而避免退化成 O(n^2) 
         * */
        swap(arr[l], arr[rand() % (r - l + 1) + l]);
        int LHS = l;
        T mid_e = arr[l];
        for (int i = l + 1; i <= r; ++i){
            if (arr[i] < mid_e)
                swap(arr[++LHS], arr[i]);
        }
        swap(arr[LHS], arr[l]);
        return LHS;
    }
    template <typename T>
    static void insertion_sort(T arr[], int l, int r){
        for (int i = l + 1; i <= r; ++i){
            /* 若要換位，改成覆蓋取代 swap */
            T tmp = arr[i];
            int j; // 即將插入點
            for (j = i; j > l && arr[j - 1] > tmp; --j){
                arr[j] = arr[j - 1];
            }
            arr[j] = tmp;
        }
    }
};

int main(void){
    int n = 519995; // 親手測試實際最大容納量...
    // int n = 100000; // 親手測試實際最大容納量...
    int swaps = 2;
    cout << "Size : " << n << ", Swap Times : " << swaps << endl;
    int * a1 = SortDataGen01::gen_nearly_sorted_arr(n, swaps);
    // int * a1 = SortDataGen01::gen_ram_arr(n, 0, n);
    int * a2 = SortDataGen01::copyArray(a1, n);
    int * a3 = SortDataGen01::copyArray(a1, n);
    int * a4 = SortDataGen01::copyArray(a1, n);

    // Quick_Insert::quick_sort(a1, n);
    // SortDataGen01::printArray(a1, n);
    
    /* Quick_Insert sort 超快的啦!!! */
    SortDataGen01::sortTimeTest("Merge sort", merge_quick::Merge::merge_sort, a3, n);
    SortDataGen01::sortTimeTest("Merge Insertion sort", merge_quick::Merge::merge_sort, a2, n);
    // SortDataGen01::sortTimeTest("Quick sort", merge_quick::Quick::quick_sort, a4, n);
    SortDataGen01::sortTimeTest("Quick Insertion sort", Quick_Insert::quick_sort, a1, n);
    
    delete[] a1;
    delete[] a2;
    delete[] a3;
    delete[] a4;
}