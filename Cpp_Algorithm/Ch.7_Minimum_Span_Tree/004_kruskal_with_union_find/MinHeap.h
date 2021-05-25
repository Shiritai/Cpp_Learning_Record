# ifndef MINHEAP_H
# define MINHEAP_H

# include <cassert>
# include <string>

using namespace std;

template <typename T>
class MinHeap {
private:
    T * data; // 捨棄第 0 位
    int len;
    int capacity;
    // bool (* less_than)(T, T);

    void shiftUp(int i){
        T toUp = data[i];
        // while (i > 1 && less_than(data[i >> 1], toUp)){
        while (i > 1 && data[i >> 1] > toUp){
            data[i] = data[i >> 1];
            i >>= 1;
        }
        data[i] = toUp;
    }

    void shiftDown(int i){
        T toDown = data[i];
        int newI = i << 1;
        while (newI <= len){
            // if (newI + 1 <= len && less_than(data[newI + 1], data[newI]))
            if (newI + 1 <= len && data[newI + 1] < data[newI])
                ++newI;
            // if (less_than(toDown, data[newI]))
            if (toDown < data[newI])
                break;
            data[i] = data[newI];
            i = newI;
            newI <<= 1;
        }
        data[i] = toDown;
    }
    
    void resize(int newCapacity){
        T * tmp = data;
        data = new T[newCapacity + 1];  // 注意 0 位留空
        for (int i = 1; i <= len; ++i)
            data[i] = tmp[i];
        delete [] tmp;
        capacity = newCapacity;
    }

    // bool lessThan(T is, T opponent){
    //     return is < opponent;
    // }

public:
    MinHeap(int capacity){
        data = new T[capacity + 1];
        this->len = 0;
        this->capacity = capacity;
        // this->less_than = lessThan;
    }

    // MinHeap(int capacity, bool (* less_than)(T, T)){
    //     data = new T[capacity + 1];
    //     this->len = 0;
    //     this->capacity = capacity;
    //     this->less_than = less_than;
    // }

    void insert(T e){
        if (len + 1 == capacity)
            resize(2 * capacity);
        data[++len] = e;
        shiftUp(len);
    }

    T pop(){
        assert(len > 0);
        T ret = data[1];
        data[1] = data[len--];
        shiftDown(1);
        if (len * 4 < capacity && capacity > 1)
            resize(capacity / 2);
        return ret;
    }

    int size(){ return len; }
    int volume(){ return capacity; }
    bool isEmpty(){ return len == 0; }
    ~MinHeap(){ delete [] data; }
};

# endif