# ifndef MERGE_SORT_H
# define MERGE_SORT_H

using namespace std;

namespace Merge_Sort {
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
}

# endif