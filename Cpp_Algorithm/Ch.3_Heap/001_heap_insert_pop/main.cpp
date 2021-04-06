# include <iostream>
# include <cassert>
# include <time.h>
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
        while (i > 1 && data[i / 2] < data[i]){
            swap(data[i / 2], data[i]);
            i /= 2;
        }
    }

    /* 將 Index i 元素嘗試向下移動，來滿足最大堆的性質 */
    void shiftDown(int i){
        int ind = i;
        T origin = data[i];
        while (ind * 2 <= len && (origin < data[ind * 2] || origin < data[ind * 2 + 1])){
            if (data[ind * 2] > data[ind * 2 + 1]){
                data[ind] = data[ind * 2];
                ind *= 2;
            }
            else {
                data[ind] = data[ind * 2 + 1];
                ind = ind * 2 + 1;
            }
        }
        data[ind] = origin;
    }

    void resize(int change_ratio){
        auto * tmp = data;
        data = new T[capacity * change_ratio + 1];
        for (int i = 1; i < capacity + 1; ++i)
            data[i] = tmp[i];
        delete[] tmp;
        capacity *= change_ratio;
    }
    
public:
    MaxHeap(int capacity){
        data = new T[capacity + 1]; // Since our index start from "1", we need tp plus 1 to the capacity
        this->len = 0;
        this->capacity = capacity;
    }

    void insert(T e){
        if (len + 1 == capacity)
            resize(2);
        data[++len] = e;
        shiftUp(len);
    }

    T popMax(){
        assert(len > 0);
        T result = data[1];
        data[1] = data[len--];
        shiftDown(1);
        return result;
    }

    string toString(){
        char tmp[10000];
        int depth = 0, width = 1;
        for (int i = len; i > 0; i /= 2, ++depth);
        for (int i = 1; i < depth; ++i, width *= 2);
        cout << width << endl;
        sprintf(tmp, "________MaxHeap________\n");
        for (int i = 1, cr = 2, blk = width; i <= len; ++i){
            if (!(i % cr)){
                sprintf(tmp, "%s\n", tmp);
                cr *= 2;
                blk /= 2;
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

int main(void){
    auto maxheap = MaxHeap<int>(15);
    // cout << "Size : " << maxheap.size() << ", capacity : " << maxheap.volume() << endl;

    srand(time(NULL));
    for (int i = 0; i < 40; ++i)
        maxheap.insert(rand() % 100);
    cout << maxheap.toString() << endl;
    cout << "Size : " << maxheap.size() << ", capacity : " << maxheap.volume() << endl;

    cout << endl;
    
    while (!maxheap.isEmpty())
        cout << maxheap.popMax() << " ";
    cout << endl;
    cout << "Size : " << maxheap.size() << ", capacity : " << maxheap.volume() << endl;
}