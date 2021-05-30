/* K-th Smallest Number in a Running Window */
# include <iostream>
# include <time.h>
# include <cassert>

using namespace std;

class K_th_number_window {
private:
    int window, size, target_order;
    int * data;
    /**
     * data[l, r) 3-way partition
     * return the new index of data[index]
     */
    void partition(int * arr, int l, int r){
        assert(l < r);
        int index = rand() % (r - l) + l; // 避免退化
        swap(arr[l], arr[index]);
        int tar = arr[l];
        int eq_l = l; // means no less element
        int check = l + 1;
        int gt_l = r; // means no greater element
        while (check != gt_l){
            if (arr[check] < tar)
                swap(arr[eq_l++], arr[check++]);
            else if (arr[check] == tar)
                ++check;
            else
                swap(arr[check], arr[--gt_l]);
        }
        if (eq_l <= target_order && target_order < gt_l){ // 終止條件
            cout << arr[target_order] << endl;
            return;
        }
        /* Recur */
        if (target_order < eq_l)
            partition(arr, l, eq_l);
        else 
            partition(arr, gt_l, r);
    }
    
public:
    K_th_number_window(int * data, int data_size, int window_size, int target_order){
        assert(data_size >= window_size);
        this->data = data;
        this->size = data_size;
        this->window = window_size;
        this->target_order = target_order;
    }
    void print(){
        srand(time(NULL));
        int * tmp = new int[window];
        for (int i = 0; i <= size - window; ++i){
            for (int j = 0; j < window; ++j)
                tmp[j] = data[i + j];
            partition(tmp, 0, window);
        }
        delete [] tmp;
    }
};