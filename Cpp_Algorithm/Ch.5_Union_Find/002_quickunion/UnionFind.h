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

    class QuickerUnion : public UnionFind {
    private :
        int * parent;
        int * set_size; // set_size[i] 表示以 i 為根的集合元素個數
        int count;

    public :
        QuickerUnion(int n){
            count = n;
            parent = new int[n];
            set_size = new int[n];
            for (int i = 0; i < n; i++){
                parent[i] = i;
                set_size[i] = 1;
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
                if (set_size[parent1] > set_size[parent2]){
                    parent[parent2] = parent1;
                    set_size[parent1] += set_size[parent2];
                }
                else {
                    parent[parent1] = parent2;
                    set_size[parent2] += set_size[parent1];
                }
            }
        }

        ~QuickerUnion(){ delete [] parent; delete [] set_size;}
    };

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
}

# endif