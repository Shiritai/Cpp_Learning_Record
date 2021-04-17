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
    
    class QuickFind : public UnionFind {
    private :
        int * id;
        int count;

    public :
        /* 各元素互不連接 */
        QuickFind(int n){
            count = n;
            id = new int[n];
            for (int i = 0; i < n; i++){
                id[i] = i;
            }
        }

        /* 查找 ID, O(1) */
        int find(int pos){ // Quick Find
            assert(pos >= 0 && pos < count);
            return id[pos];
        }

        /* 確認連通, O(1) */
        bool isConnected(int pos1, int pos2){
            return find(pos1) == find(pos2);
        }

        /* 取聯集, O(n) */
        void unionThem(int pos1, int pos2){
            int ID1 = find(pos1), ID2 = find(pos2);
            if (ID1 != ID2){ // 全變成 ID1
                for (int i = 0; i < count; ++i){
                    id[i] = (id[i] == ID2) ? ID1 : id[i];
                }
            }
        }

        ~QuickFind(){ delete [] id;}
    };

    class QuickUnion : public UnionFind {
    private :
        int * parent;
        int count;

    public :
        QuickUnion(int n){
            count = n;
            parent = new int[n];
            for (int i = 0; i < n; i++){
                parent[i] = i;
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
            if (parent1 != parent2){ // 全變成 parent1
                parent[parent2] = parent1;
            }
        }

        ~QuickUnion(){ delete [] parent;}
    };
}

# endif