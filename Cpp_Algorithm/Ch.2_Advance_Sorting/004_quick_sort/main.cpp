# include <iostream>
# include "Merge_Insertion.h"
# include "SortDataGen01.h"

using namespace std;


class Quick {
public:
    template<typename T>
    static void quick_sort(T arr[], int n){
        Quick::q_sort(arr, 0, n - 1);
    }
private:
    /* user recursion to for partitioning */
    template<typename T>
    static void q_sort(T arr[], int l, int r){
        if (l >= r)
            return;
        int p = Quick::partition(arr, l, r); // 排序並獲得中間元素
        Quick::q_sort(arr, l, p - 1);
        Quick::q_sort(arr, p + 1, r);
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
        int MID = l; // will be the mid index later
        T mid_e = arr[l];
        for (int i = l + 1; i <= r; ++i){
            if (arr[i] < mid_e)
                swap(arr[++MID], arr[i]);
        }
        swap(arr[MID], arr[l]);
        return MID;
    }
};

int main(void){
    int n = 519995; // 親手測試實際最大容納量...
    cout << "Size : " << n << endl;
    int * a1 = SortDataGen01::gen_ram_arr(n, 0, n);
    int * a2 = SortDataGen01::copyArray(a1, n);
    int * a3 = SortDataGen01::copyArray(a1, n);

    // Quick::quick_sort(a1, n);
    // SortDataGen01::printArray(a1, n);
    
    /* Quick sort 超快的啦!!! */
    SortDataGen01::sortTimeTest("Merge sort", merge_insertion::Merge::merge_sort, a1, n);
    SortDataGen01::sortTimeTest("Merge Insertion sort", merge_insertion::Merge::merge_sort, a2, n);
    SortDataGen01::sortTimeTest("Quick sort", Quick::quick_sort, a3, n);
    
    delete[] a1;
    delete[] a2;
    delete[] a3;
}