# include <iostream>
# include "SortDataGen01.h"

using namespace std;

template <typename T>
void insertion_sort(T arr[], int l, int r);

template <typename T>
void shell_sort(T arr[], int l, int r);

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

class Merge_Insert {
public:
    // 公開呼叫，支持多型，傳入陣列與元素個數
    template<typename T>
    static void merge_sort(T arr[], int n){
        Merge_Insert::split(arr, 0, n - 1);
    }
private:
    template<typename T>
    // 遞迴切割到剩一個元素，私有
    static void split(T arr[], int l, int r){
        // if (l >= r)
        //     return;
        if (r - l <= 100){
            insertion_sort(arr, l, r);
            return;
        }

        int mid = (l + r) / 2; // 注意曾經發生過 l + r 太大溢位的事故...
        Merge_Insert::split(arr, l, mid);
        Merge_Insert::split(arr, mid + 1, r);
        if (arr[mid] > arr[mid + 1]) // Optimize, 只有此時才要合併，否則代表已經排序好了
            Merge_Insert::merge(arr, l, mid, r);
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

class Merge_Shell {
public:
    // 公開呼叫，支持多型，傳入陣列與元素個數
    template<typename T>
    static void merge_sort(T arr[], int n){
        Merge_Shell::split(arr, 0, n - 1);
    }
private:
    template<typename T>
    // 遞迴切割到剩一個元素，私有
    static void split(T arr[], int l, int r){
        // if (l >= r)
        //     return;
        if (r - l <= 300){
            shell_sort(arr, l, r + 1);
            return;
        }

        int mid = (l + r) / 2; // 注意曾經發生過 l + r 太大溢位的事故...
        Merge_Shell::split(arr, l, mid);
        Merge_Shell::split(arr, mid + 1, r);
        if (arr[mid] > arr[mid + 1]) // Optimize, 只有此時才要合併，否則代表已經排序好了
            Merge_Shell::merge(arr, l, mid, r);
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

template <typename T>
void shell_sort(T arr[], int l, int r){
    int span = 1;
    while (span <= ((r - l) >> 2))
        span <<= 1;

    for (int i = span; i >= 1; i >>= 1){ // 跨度漸減
        for (int j = 0; j < (r - l) - i; ++j){
            /* 對 arr[j + span] 用插入排序 */
            int swap_to_low = j;
            while (arr[swap_to_low + l] > arr[swap_to_low + i + l]){
                swap(arr[swap_to_low + l], arr[swap_to_low + i + l]);
                swap_to_low -= i;
                if (swap_to_low < 0)
                    break;
            }
        }
    }
}

template <typename T>
void insertion_sort(T arr[], int l, int r){
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

template <typename T>
void shell_sort_origin(T arr[], int n){
    int span = 1;
    while (span <= (n >> 2))
        span <<= 1;

    for (int i = span; i >= 1; i >>= 1){ // 跨度漸減
        for (int j = 0; j < n - i; ++j){
            /* 對 arr[j + span] 用插入排序 */
            int swap_to_low = j;
            while (arr[swap_to_low] > arr[swap_to_low + i]){
                swap(arr[swap_to_low], arr[swap_to_low + i]);
                swap_to_low -= i;
                if (swap_to_low < 0)
                    break;
            }
        }
    }
}

int main(void){
    int n = 100000;
    int * arr1 = SortDataGen01::gen_ram_arr(n, 0, n);
    int * arr2 = SortDataGen01::copyArray(arr1, n);
    int * arr3 = SortDataGen01::copyArray(arr1, n);
    int * arr4 = SortDataGen01::copyArray(arr1, n);

    cout << "Size : " << n << endl;

    SortDataGen01::sortTimeTest("Shell Sort", shell_sort_origin, arr3, n);
    SortDataGen01::sortTimeTest("Merge Sort", Merge::merge_sort, arr1, n);
    SortDataGen01::sortTimeTest("Merge_Insert Sort", Merge_Insert::merge_sort, arr4, n);
    SortDataGen01::sortTimeTest("Merge_Shell Sort", Merge_Shell::merge_sort, arr2, n);

    int swaps = 1000;
    int * arr1_ = SortDataGen01::gen_nearly_sorted_arr(n, swaps);
    int * arr2_ = SortDataGen01::copyArray(arr1_, n);
    int * arr3_ = SortDataGen01::copyArray(arr1_, n);
    int * arr4_ = SortDataGen01::copyArray(arr1_, n);

    cout << endl << "Size : " << n << ", Swap Times : " << swaps << endl;

    SortDataGen01::sortTimeTest("Shell Sort", shell_sort_origin, arr3, n);
    SortDataGen01::sortTimeTest("Merge Sort", Merge::merge_sort, arr1, n);
    SortDataGen01::sortTimeTest("Merge_Insert Sort", Merge_Insert::merge_sort, arr4, n);
    SortDataGen01::sortTimeTest("Merge_Shell Sort", Merge_Shell::merge_sort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    delete[] arr1_;
    delete[] arr2_;
    delete[] arr3_;
    delete[] arr4_;
}