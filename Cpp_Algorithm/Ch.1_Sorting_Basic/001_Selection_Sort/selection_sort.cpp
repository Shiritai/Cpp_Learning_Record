# include <iostream>

using namespace std;

void sel_sort(int arr[], int n){
    for (int i = 0; i < n; ++i){
        int min_ind = i; // find minimal val in the range of [i, n)
        for (int j = i + 1; j < n; ++j)
            min_ind = (arr[j] < arr[min_ind]) ? j : min_ind;
        if (i != min_ind)
            arr[i] ^= arr[min_ind] ^= arr[i] ^= arr[min_ind]; // 注意自己 XOR 自己必 = 0
        // swap(arr[i], arr[min_ind]); // 當然有 swap 這麼香的東西...用了不虧
    }
}

int main(void){
    int a[10] = {10, 8, 9, 7, 6, 5, 3, 4, 1, 2};
    sel_sort(a, 10);
    for (int i = 0; i < 10; ++i)
        cout << a[i] << " ";
    cout << endl;
}