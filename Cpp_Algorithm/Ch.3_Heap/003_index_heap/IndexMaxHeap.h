# ifndef INDEXMAXHEAP_H
# define INDEXMAXHEAP_H

# include <cassert>
# include <string>

using namespace std;

template <typename T>
class IndexMaxHeap { // 最大堆, i.e. 大者父，小者子
private:
    T * data; // 因為一開始不知道有多少元素
    int len, capacity;
    /* 注意，必有 reverse[index[i]] = i; index[reverse[i]] = i */
    int * index, * reverse; // index : 方便整理堆而生的索引陣列; reverse : 紀錄原本 data 的 Indice

    /* 將 Index i 元素嘗試向上移動，來滿足最大堆的性質 */
    void shiftUp(int i){ 
        while (i > 1 && data[index[i >> 1]] < data[index[i]]){
            swap(index[i >> 1], index[i]);
            reverse[index[i >> 1]] = i >> 1;
            reverse[index[i]] = i;
            i >>= 1;
        }
    }

    /* 將 Index ind 元素嘗試向下移動，來滿足最大堆的性質 */
    void shiftDown(int ind){ // 必有 reverse[ind] = origin_position_in_data
        int originInd = ind, originPos = reverse[ind];
        int new_ind = ind << 1;
        while (new_ind <= len){
            if (new_ind + 1 <= len && data[index[new_ind + 1]] > data[index[new_ind]])
                ++new_ind;
            if (data[index[ind]] > data[index[new_ind]])
                break;
            index[ind] = index[new_ind];
            reverse[index[ind]] = ind;
            ind = new_ind;
            new_ind <<= 1;
        }
        index[ind] = originInd;
        reverse[index[ind]] = originPos;
    }

    void resize(int newCapacity){
        auto * tmpD = data, * tmpI = index, * tmpR = reverse;
        data = new T[newCapacity + 1];
        index = new int[newCapacity + 1];
        reverse = new int[newCapacity + 1];
        for (int i = 1; i < len + 1; ++i){
            data[i] = tmpD[i];
            index[i] = tmpI[i];
            reverse[i] = tmpR[i];
        }
        delete[] tmpD;
        delete[] tmpI;
        delete[] tmpR;
        for (int i = capacity; i < newCapacity; ++i) // init
            reverse[i] = 0;
        capacity = newCapacity;
    }
    
public:
    IndexMaxHeap(int capacity){
        data = new T[capacity + 1]; // Since our index start from "1", we need tp plus 1 to the capacity
        this->index = new int[capacity + 1];
        this->reverse = new int[capacity + 1];
        for (int i = 0; i <= capacity; ++i) // init, index = 0 就表示不存在!
            reverse[i] = 0;
        this->len = 0;
        this->capacity = capacity;
    }

    IndexMaxHeap(T arr[], int capacity){
        data = new T[capacity + 1];
        this->capacity = this->len = capacity;
        for (int i = 0; i < capacity; ++i)
            data[i + 1] = arr[i];
        for (int i = len >> 1; i >= 1; --i)
            shiftDown(i);
    }

    /* 對傳入者而言，i 索引自 0 開始 */
    void insert(int i, T e){
        assert(i >= 0);
        if (i + 1 >= capacity)
            resize(2 * capacity);
        data[++i] = e; // 存資料, ++ 是因為對本 Heap 而言，索引自 1 開始
        index[++len] = i; // 存資料的索引，所有 Heap 調整 (Shift up/down) 皆是對此操作
        reverse[i] = len; // 存資料的固有索引，方便藉由索引馬上訪問某資料
        shiftUp(len);
    }

    T popMax(){
        assert(len > 0);
        T result = data[index[1]];
        index[1] = index[len];
        reverse[index[1]] = 1;
        reverse[index[len--]] = 0; // 在此 -- 是為了維護 len
        shiftDown(1);
        if (len * 4 < capacity && 1/2 * capacity > 0)
            resize(1/2 * capacity);
        return result;
    }

    int popMaxIndex(){
        assert(len > 0);
        int resultInd = index[1] - 1; // 對外索引 0 開始
        index[1] = index[len];
        reverse[index[1]] = 1;
        reverse[index[len--]] = 0; // 在此 -- 是為了維護 len
        shiftDown(1);
        if (len * 4 < capacity && 1/2 * capacity > 0)
            resize(1/2 * capacity);
        return resultInd;
    }

    T getElement(int indice){
        assert(indice >= 0 && reverse[indice + 1] != 0); // this means this heap contain this indice
        return data[indice + 1]; // 對外索引 0 開始
    }

    /* Take the indice of your data and the element you'd like to change */
    void changeElement(int indice, T e){
        assert(indice >= 0 && reverse[indice + 1] != 0);
        data[++indice] = e;
        // /* *
        //  * 這樣效率低 -> 引入 reverse (origin index in data)
        //  * 調整 Index Heap 使之滿足 MaxHeap
        //  * 1. 找到資料在 index_heap 裡的位置
        //  * 2. 嘗試上 / 下移
        //  * */
        // for (int j = 1; j < len + 1; ++j){
        //     if (index[j] = i){
        //         shiftUp(j);
        //         shiftDown(j);
        //         return;
        //     }
        // }
        shiftUp(reverse[indice]);
        shiftDown(reverse[indice]);
        return;

    }

    /* 對從 0 開始索引的陣列嘗試 shift down */
    static void shift_down(T arr[], int len, int ind){
        int originInd = ind;
        int new_ind = (ind << 1) + 1;
        while (new_ind < len){
            if (new_ind + 1 < len && arr[new_ind + 1] > arr[new_ind]) // go to left or right
                ++new_ind;
            if (data[index[originInd]] >= arr[new_ind])
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
        sprintf(tmp, "________IndexMaxHeap________\n");
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
    ~MaxHeap(){ delete [] data; delete[] index; delete[] reverse;}
};

# endif