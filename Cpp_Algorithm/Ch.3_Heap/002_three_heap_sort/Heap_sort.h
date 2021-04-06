# include "MaxHeap.h"

using namespace std;

namespace heapSort{
    /* 就地 Heapify 後 pop, 從 Index 0 開始 */
    template <typename T>
    void heapSort(T arr[], int n){
        /* Heapify */
        for (int i = (n - 1) / 2; i >= 0; --i) /* (n - 1) / 2 : 第一個 non-leaf Node */
            MaxHeap<T>::shift_down(arr, n, i);
        /* Sort */
        for (int i = n - 1; i > 0; --i){
            swap(arr[0], arr[i]);
            MaxHeap<T>::shift_down(arr, i, 0); // 未排序的在前，排好序的在後
        }
    }

    template <typename T>
    void heapSort1(T arr[], int n){
        auto heap = MaxHeap<T>(n);
        for (int i = 0; i < n; ++i)
            heap.insert(arr[i]);
        for (int i = n - 1; i >= 0; --i)
            arr[i] = heap.popMax();
    }

    template <typename T>
    void heapSort2(T arr[], int n){
        auto heap = MaxHeap<T>(arr, n);
        for (int i = n - 1; i >= 0; --i)
            arr[i] = heap.popMax();
    }

}