# include "Heap_sort.h"
# include "Merge_Sort.h"
# include "Quick_Sort.h"
# include "SortDataGen01.h"

using namespace std;

int main(void){
    // int n = 519995; // 親手測試實際最大容納量...
    int n = 500000; // 親手測試實際最大容納量...
    int swaps = 100;
    cout << "Size : " << n /* << ", Swap Times : " << swaps  */<< endl;
    // int * a1 = SortDataGen01::gen_nearly_sorted_arr(n, swaps);
    int * a1 = SortDataGen01::gen_ram_arr(n, 0, n);
    int * a2 = SortDataGen01::copyArray(a1, n);
    int * a3 = SortDataGen01::copyArray(a1, n);
    int * a4 = SortDataGen01::copyArray(a1, n);
    int * a5 = SortDataGen01::copyArray(a1, n);
    int * a6 = SortDataGen01::copyArray(a1, n);
    int * a7 = SortDataGen01::copyArray(a1, n);

    // Quick_Insert::quick_sort(a1, n);
    // SortDataGen01::printArray(a1, n);
    
    SortDataGen01::sortTimeTest("Merge sort", Merge_Sort::Merge::merge_sort, a3, n);
    SortDataGen01::sortTimeTest("Merge Insertion sort", Merge_Sort::Merge::merge_sort, a2, n);
    SortDataGen01::sortTimeTest("Quick Insertion sort (2)", Quick_Insert::quick_sort2, a5, n);
    SortDataGen01::sortTimeTest("Quick Insertion sort (3)", Quick_Insert::quick_sort3, a1, n);
    SortDataGen01::sortTimeTest("Heap sort (1)", heapSort::heapSort1, a6, n);
    SortDataGen01::sortTimeTest("Heap sort (2)", heapSort::heapSort2, a4, n);
    SortDataGen01::sortTimeTest("Heap sort", heapSort::heapSort, a7, n);

    a1 = SortDataGen01::gen_nearly_sorted_arr(n, swaps);
    a2 = SortDataGen01::copyArray(a1, n);
    a3 = SortDataGen01::copyArray(a1, n);
    a4 = SortDataGen01::copyArray(a1, n);
    a5 = SortDataGen01::copyArray(a1, n);
    a6 = SortDataGen01::copyArray(a1, n);
    a7 = SortDataGen01::copyArray(a1, n);

    // Quick_Insert::quick_sort(a1, n);
    // SortDataGen01::printArray(a1, n);
    
    cout << endl;
    cout << "Size : " << n << ", Swap Times : " << swaps << endl;
    SortDataGen01::sortTimeTest("Merge sort", Merge_Sort::Merge::merge_sort, a3, n);
    SortDataGen01::sortTimeTest("Merge Insertion sort", Merge_Sort::Merge::merge_sort, a2, n);
    SortDataGen01::sortTimeTest("Quick Insertion sort (2)", Quick_Insert::quick_sort2, a5, n);
    SortDataGen01::sortTimeTest("Quick Insertion sort (3)", Quick_Insert::quick_sort3, a1, n);
    SortDataGen01::sortTimeTest("Heap sort (1)", heapSort::heapSort1, a6, n);
    SortDataGen01::sortTimeTest("Heap sort (2)", heapSort::heapSort2, a4, n);
    SortDataGen01::sortTimeTest("Heap sort", heapSort::heapSort, a7, n);
    
    // int * a1 = SortDataGen01::gen_nearly_sorted_arr(n, swaps);
    a1 = SortDataGen01::gen_ram_arr(n, 0, 10);
    a2 = SortDataGen01::copyArray(a1, n);
    a3 = SortDataGen01::copyArray(a1, n);
    a4 = SortDataGen01::copyArray(a1, n);
    a5 = SortDataGen01::copyArray(a1, n);
    a6 = SortDataGen01::copyArray(a1, n);
    a7 = SortDataGen01::copyArray(a1, n);

    // Quick_Insert::quick_sort(a1, n);
    // SortDataGen01::printArray(a1, n);
    cout << endl;
    cout << "Size : " << n << ", range from 0 to 10" << endl;
    SortDataGen01::sortTimeTest("Merge sort", Merge_Sort::Merge::merge_sort, a3, n);
    SortDataGen01::sortTimeTest("Merge Insertion sort", Merge_Sort::Merge::merge_sort, a2, n);
    SortDataGen01::sortTimeTest("Quick Insertion sort (2)", Quick_Insert::quick_sort2, a5, n);
    SortDataGen01::sortTimeTest("Quick Insertion sort (3)", Quick_Insert::quick_sort3, a1, n);
    SortDataGen01::sortTimeTest("Heap sort (1)", heapSort::heapSort1, a6, n);
    SortDataGen01::sortTimeTest("Heap sort (2)", heapSort::heapSort2, a4, n);
    SortDataGen01::sortTimeTest("Heap sort", heapSort::heapSort, a7, n);

    delete[] a1;
    delete[] a2;
    delete[] a3;
    delete[] a4;
    delete[] a5;
    delete[] a6;
    delete[] a7;
}