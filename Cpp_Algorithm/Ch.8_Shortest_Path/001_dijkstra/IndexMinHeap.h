# ifndef INDEX_MINHEAP_H
# define INDEX_MINHEAP_H

# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

template <typename T>
class IndexMinHeap {
private:
    T * data; // 捨棄第 0 位
    int * indexList; // 這個整數組成的索引 array 才是真正的最小堆, 即 indexList 索引們指向的 data 擁有最小堆的性質
    int * reverseList; // 保持 data[i] 的 i 為 indexList[j], where j = reverseList[i]
    // 必有 reverseList[indexList[i]] = i 以及 indexList[reverseList[i]] = i
    // 每逢修改 indexList (即 swap) 時, 需維護 reverseList 使之可以由 "data 索引" 映射到 "indexList 索引"
    int len;
    int capacity;

    void shiftUp(int i){
        while (i > 1 && data[indexList[i >> 1]] > data[indexList[i]]){
            swap(indexList[i], indexList[i >> 1]);
            reverseList[indexList[i]] = i;
            reverseList[indexList[i >> 1]] = i >> 1;
            i >>= 1;
        }
    }

    void shiftDown(int i){
        int newI = i << 1;
        while (newI <= len){
            if (newI + 1 <= len && data[indexList[newI + 1]] < data[indexList[newI]])
                ++newI;
            if (data[indexList[i]] < data[indexList[newI]])
                break;
            swap(indexList[i], indexList[newI]);
            reverseList[indexList[i]] = i;
            reverseList[indexList[newI]] = newI;
            i = newI;
            newI <<= 1;
        }
    }

public:
    IndexMinHeap(int capacity){
        data = new T[capacity + 1];
        indexList = new int[capacity + 1];
        reverseList = new int[capacity + 1];

        for (int i = 1; i <= capacity; ++i)
            reverseList[i] = 0; // 0 表不存在
            
        this->len = 0;
        this->capacity = capacity;
    }

    /* 對使用者而言, 索引從 0 開始 */
    void insert(int ind, T e){
        assert(len + 1 <= capacity);
        assert(ind >= 0 && ind + 1 <= capacity);
        
        ++ind; // 位移 1 使其與本 IndexMinHeap 索引一致
        data[ind] = e;
        indexList[len + 1] = ind;
        reverseList[ind] = ++len; // 即 reverseList[indexList[len + 1]] = len + 1
        shiftUp(len);
    }

    T pop(){
        assert(len > 0);
        T ret = data[indexList[1]];
        swap(indexList[1], indexList[len]);
        reverseList[indexList[1]] = 1; // 刷新 「新的棧頂」 元素的 reverseList
        reverseList[indexList[len--]] = 0; // 即刪除 「原本」 (因為 swap 過) 棧頂元素
        shiftDown(1);
        return ret;
    }

    int popMinIndex(){
        assert(len > 0);
        int ret = indexList[1] - 1; //  對外部而言, 索引自 0 開始
        swap(indexList[1], indexList[len]);
        reverseList[indexList[1]] = 1; // 刷新 「新的棧頂」 元素的 reverseList
        reverseList[indexList[len--]] = 0; // 即刪除 「原本」 (因為 swap 過) 棧頂元素
        shiftDown(1);
        return ret;
    }

    int getMinIndex(){
        assert(len > 0);
        return indexList[1] - 1; //  對外部而言, 索引自 0 開始
    }

    T get(int index){
        assert(contain(index)); // 檢查 i 的合法性時, 因i 在索引範圍內不意味著 data[i + 1] 存在!
        return data[index + 1]; //  對外部而言, 索引自 0 開始
    }

    void set(int index, T newItem){
        assert(contain(index)); // 檢查 i 的合法性時, 因i 在索引範圍內不意味著 data[i + 1] 存在!
        data[++index] = newItem;
        /* use reverseList to optimize the maintainance to the properties of MinHeap */
        shiftUp(reverseList[index]);
        shiftDown(reverseList[index]);
    }

    bool contain(int index){
        assert(index >= 0 && index + 1 <= capacity);
        return reverseList[index + 1] != 0;
    }

    int size(){ return len; }
    int volume(){ return capacity; }
    bool isEmpty(){ return len == 0; }
    ~IndexMinHeap(){
        delete [] data;
        delete [] indexList;
        delete [] reverseList;
    }
};

# endif