# ifndef SPARSE_GRAPH_H
# define SPARSE_GRAPH_H

# include <iostream>
# include <vector> 
# include <cassert>

using namespace std;

namespace sparseGraph {
    class SparseGraph {
    private :
        int v, e;
        bool directed;
        vector<vector<int>> A; // 鄰接表 : 儲存鄰接點的編號
    public :
        SparseGraph(int v, bool directed){
            this->v = v;
            this->e = 0;
            this->directed = directed;
            for (int i = 0; i < v; ++i){
                A.push_back(vector<int>());
            }
        }
        
        int V(){ return v;}
        int E(){ return e;}

        void addEdge(int v1, int v2){
            assert(v1 >= 0 && v1 < v);
            assert(v2 >= 0 && v2 < v);
            
            /* 
                * 若不想要有平行邊, 理當在此加一個判斷, 
                * 但複雜度為 O(v), 成本過高,  
                * 因此通常是在要查找時一次刪去平行邊較有效率
                */
            A[v1].push_back(v2);
            if (v1 != v2 && !directed)
                A[v2].push_back(v1);
            ++e;
        }

        bool hasEdge(int v1, int v2){
            assert(v1 >= 0 && v1 < v);
            assert(v2 >= 0 && v2 < v);
            for (auto it = A[v1].begin(); it != A[v1].end(); ++it){
                if (* it == v2)
                    return true;
            }
            return false;
        }
    }
}

# endif