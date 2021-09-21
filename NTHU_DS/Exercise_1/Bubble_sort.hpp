# include <utility>

typedef int keytype;
typedef int index;

/** 
 * 又是從 1 開始的邪教...
 */
void bubble_sort(keytype arr[], int n){
    for (index i = 0; i < n; ++i)
        for (index j = i + 1; j < n; ++j)
            if (arr[j] < arr[i])
                std::swap(arr[i], arr[j]); // assume time complexity O(1)
}