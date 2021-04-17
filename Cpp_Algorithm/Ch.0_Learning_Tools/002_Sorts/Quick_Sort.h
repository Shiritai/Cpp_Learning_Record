# ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include <time.h>

using namespace std;

class Quick_Insert {
public:
    template<typename T>
    static void quick_sort1(T arr[], int n){
        /* Optimization, to avoid degeneration of qsort! */
        srand(time(NULL));
        Quick_Insert::q_sort1(arr, 0, n - 1);
    }

    template<typename T>
    static void quick_sort2(T arr[], int n){
        /* Optimization, to avoid degeneration of qsort! */
        srand(time(NULL));
        Quick_Insert::q_sort2(arr, 0, n - 1);
    }

    template<typename T>
    static void quick_sort3(T arr[], int n){
        /* Optimization, to avoid degeneration of qsort! */
        srand(time(NULL));
        Quick_Insert::q_sort3(arr, 0, n - 1);
    }

private:
    /* user recursion to for partitioning */
    template<typename T>
    static void q_sort1(T arr[], int l, int r){
        if (r - l <= 30){
            Quick_Insert::insertion_sort(arr, l, r);
            return;
        }
        int p = Quick_Insert::partition1(arr, l, r); // 排序並獲得中間元素
        Quick_Insert::q_sort1(arr, l, p - 1);
        Quick_Insert::q_sort1(arr, p + 1, r);
    }

    template <typename T>
    static void q_sort2(T arr[], int l, int r){
        if (r - l <= 30){
            Quick_Insert::insertion_sort(arr, l, r);
            return;
        }
        int p = Quick_Insert::partition2(arr, l, r); // 排序並獲得中間元素
        Quick_Insert::q_sort2(arr, l, p - 1);
        Quick_Insert::q_sort2(arr, p + 1, r);
    }
    /* 分成 <, ==, > 三部分 */
    template <typename T>
    static void q_sort3(T arr[], int l, int r){
        if (r - l <= 30){
            Quick_Insert::insertion_sort(arr, l, r);
            return;
        }
        /* Partition */
        swap(arr[l], arr[rand() % (r - l + 1) + l]);
        T mid_e = arr[l];
        int LHS = l, RHS = r + 1; // arr[l+1 ~ LHS] < mid_e, arr[RHS ~ r] > mid_e
        int cur = l + 1; // arr[LHS+1 ~ cur) == mid_e, 由於 cur 在之後會不斷向後考察，因此用 ")", 起始範圍為空，即 cur == LHS + 1
        while (cur < RHS){
            switch(!!(arr[cur] - mid_e) * (((arr[cur] - mid_e) >> 31 & 1) ? -1 : 1)){
                case -1: // arr[cur] < mid_e
                    swap(arr[cur++], arr[++LHS]);
                    break;
                case 1: // arr[cur] > mid_e
                    swap(arr[cur], arr[--RHS]);
                    break;
                case 0: // arr[cur] == mid_e
                    ++cur;
                    break;
            }
        }
        swap(arr[l], arr[LHS]);
        q_sort3(arr, l, LHS - 1);
        q_sort3(arr, RHS, r);
        return;
    }

    /* *
     * Return the index p such that 
     * all the elements on the LHS are smaller than element p 
     * and all the elements on the RHS are bigger than element p
     * i.e. arr[l ~ p-1] < arr[p]
     * and arr[p+1 ~ r] > arr[p]
     */
    template<typename T>
    static int partition1(T arr[], int l, int r){
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

    /* A new approach of partitioning */
    template<typename T>
    static int partition2(T arr[], int l, int r){
        swap(arr[l], arr[rand() % (r - l + 1) + l]);
        T mid_e = arr[l];
        /* This time, arr[l+1 ~ LHS] <= arr[l] and arr[RHS ~ r] >= arr[l] */
        int LHS = l + 1, RHS = r;
        while (1){
            while (LHS <= r && arr[LHS] < mid_e) ++LHS; // 吸納同樣小於參考子的元素們
            while (RHS > l && arr[RHS] > mid_e) --RHS; // 吸納同樣大於參考子的元素們
            if (LHS > RHS)  break;
            swap(arr[RHS--], arr[LHS++]);
        }
        swap(arr[l], arr[RHS]); // 此時 RHS < LHS 且 arr[RHS] 正是最後一個 < arr[l] 的值
        return RHS;
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

# endif