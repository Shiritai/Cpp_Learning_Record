# ifndef BINARYSEARCH_H
# define BINARYSEARCH_H

using namespace std;

/* find the indice of certain element, return -1 if the element DNE */
template <typename T>
int binary_search(T arr[], int n, T target){ // O(log(n))
    int l = 0, r = n - 1; // 在 arr[l ~ r] 中尋找 target
    while (l <= r){
        // int mid = (l + r) / 2; // bug!!!
        int mid = l + (r - l) / 2 // avoid overflow
        if (arr[mid] == target)
            return mid;
        /* 在 arr[l ~ mid - 1] 中尋找 target */
        if (arr[mid] < target)
            r = mid - 1;
        /* 在 arr[mid + 1 ~ r] 中尋找 target */
        else // arr[mid] > target
            l = mid + 1;
    }
    return -1;
}

# endif