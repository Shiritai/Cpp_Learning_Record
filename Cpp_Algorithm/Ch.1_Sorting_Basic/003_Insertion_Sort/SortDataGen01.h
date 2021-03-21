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
    /* test correctness of the sort algo */
    bool isSorted(T arr[], int n){
        for (int i = 0; i < n - 1; ++i){
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    template <typename T>
    /* sort time counter */
    void sortTimeTest(string nameOfSort, void (* sort) (T[], int), T arr[], int n){
        clock_t start = clock();
        sort(arr, n);
        clock_t end = clock();
        assert(isSorted(arr, n));
        cout << nameOfSort << " : " << ((double) end - start) / CLOCKS_PER_SEC << " sec\n";
        return;
    }

};
# endif