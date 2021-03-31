# ifndef SORT_DATA_GEN01_H
# define SORT_DATA_GEN01_H

# include <cassert> // OwO
# include <ctime>
# include <iostream>

using namespace std;

namespace SortDataGen01{

    /* generate number list in the range of [l, r] */
    int * gen_ram_arr(int n, int l, int r){
        assert(l <= r);
        int * arr = new int[n];
        srand(time(NULL)); // 設置由時間決定的隨機種子
        for (int i = 0; i < n; i++)
            arr[i] = (rand() % (r - l + 1)) + l;
        return arr;
    }

    /* n : number of elements, swapTimes : number of swapped pairs */
    int * gen_nearly_sorted_arr(int n, int swapTimes){
        int * arr = new int[n];
        for (int i = 0; i < n; ++i){
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; ++i){
            swap(arr[rand() % n], arr[rand() % n]);
        }
        return arr;
    }

    template <typename T>
    T * copyArray(T a[], int n){
        T * arr = new T[n];
        copy(a, a + n, arr);
        return arr;
    }

    template <typename T>
    /* print data array */
    void printArray(T arr[], int n){
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }

    template <typename T>
    /* test the correctness of the sort algorithm */
    bool isSorted(T arr[], int n){
        for (int i = 0; i < n - 1; ++i){
            if (arr[i] > arr[i + 1]){
                cout << "Failed at : arr[" << i << "] = " << arr[i] << " and arr[" << i + 1 << "] = " << arr[i + 1] << endl;
                return false;
            }
        }
        return true;
    }

    template <typename T>
    /* sort time counter */
    void sortTimeTest(string nameOfSort, void (* sort) (T[], int), T arr[], int n){
        clock_t start = clock();
        sort(arr, n);
        clock_t end = clock();
        bool incorrect = isSorted(arr, n);
        if (!incorrect)
            cout << "The array has not been sorted by " << nameOfSort <<" yet!\n";
        assert(incorrect);
        cout << nameOfSort << " : " << ((double) end - start) / CLOCKS_PER_SEC << " sec\n";
        return;
    }

};
# endif