# ifndef MAXHEAP_H
# define MAXHEAP_H

# include <cassert>
# include <string>

using namespace std;

template <typename T>
class MaxHeap { // 最大堆, i.e. 大者父，小者子
private:
    T * data; // 因為一開始不知道有多少元素
    int len;
    int capacity;

    /* 將 Index i 元素嘗試向上移動，來滿足最大堆的性質 */
    void shiftUp(int i){
        while (i > 1 && data[i >> 1] < data[i]){
            swap(data[i >> 1], data[i]);
            i >>= 1;
        }
    }

    /* 將 Index i 元素嘗試向下移動，來滿足最大堆的性質 */
    void shiftDown(int ind){
        T origin = data[ind];
        int new_ind = ind << 1;
        while (new_ind <= len){
            if (new_ind + 1 <= len && data[new_ind + 1] > data[new_ind])
                ++new_ind;
            if (origin > data[new_ind])
                break;
            data[ind] = data[new_ind];
            ind = new_ind;
            new_ind <<= 1;
        }
        data[ind] = origin;
    }

    void resize(int newCapacity){
        auto * tmp = data;
        data = new T[newCapacity + 1];
        for (int i = 1; i < len + 1; ++i)
            data[i] = tmp[i];
        delete[] tmp;
        capacity = newCapacity;
    }
    
public:
    MaxHeap(int capacity){
        data = new T[capacity + 1]; // Since our index start from "1", we need tp plus 1 to the capacity
        this->len = 0;
        this->capacity = capacity;
    }

    MaxHeap(T arr[], int capacity){
        data = new T[capacity + 1];
        this->capacity = this->len = capacity;
        for (int i = 0; i < capacity; ++i)
            data[i + 1] = arr[i];
        /* *
         * 由第一個 non-leaf node 開始逐一 Shift Down
         * non-leaf node 為 1 ~ len / 2 !!!
         * */
        for (int i = len >> 1; i >= 1; --i)
            shiftDown(i);
    }

    void insert(T e){
        if (len + 1 == capacity)
            resize(2 * capacity);
        data[++len] = e;
        shiftUp(len);
    }

    T popMax(){
        assert(len > 0);
        T result = data[1];
        data[1] = data[len--];
        shiftDown(1);
        if (len * 4 < capacity && 1/2 * capacity > 0)
            resize(1/2 * capacity);
        return result;
    }

    /* 對從 0 開始索引的陣列嘗試 shift down */
    static void shift_down(T arr[], int len, int ind){
        T origin = arr[ind];
        int new_ind = (ind << 1) + 1;
        while (new_ind < len){
            if (new_ind + 1 < len && arr[new_ind + 1] > arr[new_ind]) // go to left or right
                ++new_ind;
            if (origin >= arr[new_ind])
                break;
            arr[ind] = arr[new_ind];
            ind = new_ind;
            new_ind = (ind << 1) + 1; // left child node
        }
        arr[ind] = origin;
    }

    string toString(){
        char tmp[10000];
        int depth = 0, width = 1;
        for (int i = len; i > 0; i >>= 1, ++depth);
        for (int i = 1; i < depth; ++i, width <<= 1);
        sprintf(tmp, "________MaxHeap________\n");
        for (int i = 1, cr = 2, blk = width; i <= len; ++i){
            if (!(i % cr)){
                sprintf(tmp, "%s\n", tmp);
                cr <<= 1;
                blk >>= 1;
            }
            for (int i = 0; i < blk; ++i)
                sprintf(tmp, "%s ", tmp);
            sprintf(tmp, "%s%02d", tmp, data[i]);
        }
        return string(tmp);
    }

    int size(){ return len;}
    int volume(){ return capacity;}
    bool isEmpty(){ return len == 0;}
    ~MaxHeap(){ delete [] data;}
};

# endif