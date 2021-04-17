# ifndef UNIONFIND_H
# define UNIONFIND_H

# include <iostream>
# include <cassert>

using namespace std;

namespace unionfind {

    class UnionFind {
    public :
        virtual bool isConnected(int, int) = 0; // abstract method
        virtual void unionThem(int, int) = 0;
    };

    /* 以層數決定聯集方法 */
    class QuickestUnion : public UnionFind {
    private :
        int * parent;
        int * rank; // rank[i] 表示以 i 為根的樹的 "層數"
        int count;

    public :
        QuickestUnion(int n){
            count = n;
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        /* 查找 ID, O(1) */
        int find(int pos){ // Quick Find
            assert(pos >= 0 && pos < count);
            while (pos != parent[pos]){ // 自己指向自己表示找到根了
                pos = parent[pos];
            }
            return pos;
        }

        /* 確認連通, O(1) */
        bool isConnected(int pos1, int pos2){
            return find(pos1) == find(pos2);
        }

        /* 取聯集, O(n) */
        void unionThem(int pos1, int pos2){
            int parent1 = find(pos1), parent2 = find(pos2);
            if (parent1 != parent2){ // 全變成 "集合元素較小者"
                if (rank[parent1] > rank[parent2]){
                    parent[parent2] = parent1;
                }
                else if (rank[parent1] < rank[parent2]){
                    parent[parent1] = parent2;
                }
                else {
                    parent[parent2] = parent1;
                    ++rank[parent1];
                }
            }
        }

        ~QuickestUnion(){ delete [] parent; delete [] rank;}
    };

    /* 以層數決定聯集方法, 並在每次查詢時壓縮路徑 */
    class QuickUnionFind : public UnionFind {
    private :
        int * parent;
        int * rank; // rank[i] 表示以 i 為根的樹的 "層數"
        int count;

    public :
        QuickUnionFind(int n){
            count = n;
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++){
                parent[i] = i;
                rank[i] = 0; // 這裡任意常數都可以, 不影響整體邏輯
            }
        }

        /* 查找 ID, O(1) */
        int find(int pos){ // Quick Find
            assert(pos >= 0 && pos < count);
            while (pos != parent[pos]){ // 自己指向自己表示找到根了
                parent[pos] = parent[parent[pos]]; // 路徑壓縮
                pos = parent[pos];
            }
            return pos;
        }

        /* 確認連通, O(1) */
        bool isConnected(int pos1, int pos2){
            return find(pos1) == find(pos2);
        }

        /* 取聯集, O(n) */
        void unionThem(int pos1, int pos2){
            int parent1 = find(pos1), parent2 = find(pos2);
            if (parent1 != parent2){ // 全變成 "集合元素較小者"
                if (rank[parent1] > rank[parent2]){
                    parent[parent2] = parent1;
                }
                else if (rank[parent1] < rank[parent2]){
                    parent[parent1] = parent2;
                }
                else {
                    parent[parent2] = parent1;
                    ++rank[parent1];
                }
            }
        }

        ~QuickUnionFind(){ delete [] parent; delete [] rank;}
    };

    /* 以層數決定聯集方法, 並在每次查詢時壓縮路徑 */
    class QuickerUnionFind : public UnionFind {
    private :
        int * parent;
        int * rank; // rank[i] 表示以 i 為根的樹的 "層數"
        int count;

    public :
        QuickerUnionFind(int n){
            count = n;
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++){
                parent[i] = i;
                rank[i] = 0; // 這裡任意常數都可以, 不影響整體邏輯
            }
        }

        /* 查找 ID, O(1) */
        int find(int pos){ // Quick Find
            assert(pos >= 0 && pos < count);
            if (pos != parent[pos]){ // 自己指向自己表示找到根了
                parent[pos] = find(parent[pos]); // Recur 路徑壓縮，對每個點壓縮至根
            }
            return parent[pos];
        }

        /* 確認連通, O(1) */
        bool isConnected(int pos1, int pos2){
            return find(pos1) == find(pos2);
        }

        /* 取聯集, O(n) */
        void unionThem(int pos1, int pos2){
            int parent1 = find(pos1), parent2 = find(pos2);
            if (parent1 != parent2){ // 全變成 "集合元素較小者"
                if (rank[parent1] > rank[parent2]){
                    parent[parent2] = parent1;
                }
                else if (rank[parent1] < rank[parent2]){
                    parent[parent1] = parent2;
                }
                else {
                    parent[parent2] = parent1;
                    ++rank[parent1];
                }
            }
        }

        ~QuickerUnionFind(){ delete [] parent; delete [] rank;}
    };

    /* 以層數決定聯集方法, 並在每次查詢時壓縮路徑 */
    class QuickestUnionFind : public UnionFind {
    private :
        int * parent;
        int * rank; // rank[i] 表示以 i 為根的樹的 "層數"
        int count;

    public :
        QuickestUnionFind(int n){
            count = n;
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++){
                parent[i] = i;
                rank[i] = 0; // 這裡任意常數都可以, 不影響整體邏輯
            }
        }

        int normal_find(int pos){
            while (pos != parent[pos])
                pos = parent[pos];
            return pos;
        }

        /* 查找 ID, O(1) */
        int find(int pos){ // Quick Find
            assert(pos >= 0 && pos < count);
            int root = normal_find(parent[pos]);
            for (int iterPos = pos; iterPos != parent[iterPos]; pos = iterPos){
                iterPos = parent[iterPos];
                parent[pos] = root;
            }
            return root;
        }

        /* 確認連通, O(1) */
        bool isConnected(int pos1, int pos2){
            return find(pos1) == find(pos2);
        }

        /* 取聯集, O(n) */
        void unionThem(int pos1, int pos2){
            int parent1 = find(pos1), parent2 = find(pos2);
            if (parent1 != parent2){ // 全變成 "集合元素較小者"
                if (rank[parent1] > rank[parent2]){
                    parent[parent2] = parent1;
                }
                else if (rank[parent1] < rank[parent2]){
                    parent[parent1] = parent2;
                }
                else {
                    parent[parent2] = parent1;
                    ++rank[parent1];
                }
            }
        }

        ~QuickestUnionFind(){ delete [] parent; delete [] rank;}
    };
}

# endif