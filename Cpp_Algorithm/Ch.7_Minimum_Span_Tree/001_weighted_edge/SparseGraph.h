# ifndef SPARSE_GRAPH_H
# define SPARSE_GRAPH_H

# include <iostream>
# include <vector> 
# include <cassert>
# include "Edge.h"

using namespace std;

namespace sparseGraph {
    /**
     * Pros : Easy to traverse adjacency edges 
     * 
     * Cons : 平行邊判斷 
     * Sol : 所有 edges 加入完後再一次刪除, 增加效率
     * */
    template <typename Weight>
    class SparseGraph {
    private :
        int v, e;
        bool directed;
        vector<vector<Edge<Weight> *>> A; // 鄰接表 : 儲存鄰接點的編號
    public :
        SparseGraph(int v, bool directed){
            this->v = v;
            this->e = 0;
            this->directed = directed;
            for (int i = 0; i < v; ++i){
                A.push_back(vector<Edge<Weight> *>());
            }
        }

        ~SparseGraph(){
            for (int i = 0; i < v; ++i)
                for (int j = 0; j < A[i].size(); ++j)
                    delete A[i][j];
        }
        
        int V(){ return v;}
        int E(){ return e;}

        void addEdge(int v1, int v2, Weight w){
            assert(v1 >= 0 && v1 < v);
            assert(v2 >= 0 && v2 < v);
            
            A[v1].push_back(new Edge<Weight>(v1, v2, w));
            if (v1 != v2 && !directed)
                A[v2].push_back(new Edge<Weight>(v2, v1, w));
            ++e;
        }

        /**
         * 若不想要有平行邊 (即重複邊), 理當在此加一個判斷, 
         * 但複雜度為 O(v), 成本過高,  
         * 因此通常是在要查找時一次刪去平行邊較有效率
         */
        bool hasEdge(int v1, int v2){
            assert(v1 >= 0 && v1 < v);
            assert(v2 >= 0 && v2 < v);
            for (int i = 0; i < A[v1].size(); ++i){
                if (A[v1][i]->other(v1) == v2)
                    return true;
            }
            return false;
        }

        void show(){
            for (int i = 0; i < v; ++i){
                cout << "vertex " << i << ": -> ";
                for (int j = 0; j < A[i].size(); ++j)
                    cout << "(to : " << A[i][j]->to() << ", weight : " << A[i][j]->weight() << ") -> ";
                cout << "NULL\n";
            }
        }

        class adjIterator {
        public :
            adjIterator(SparseGraph & graph, int vertex) : iterGraph(graph) {
                this->v = vertex;
                this->index = 0;
            }
            
            Edge<Weight> * begin(){
                index = 0;
                return (iterGraph.A[v].size()) ? iterGraph.A[v][index] : -1; // -1 表此圖沒有東西
            }

            Edge<Weight> * next(){
                ++index;
                return (index < iterGraph.A[v].size()) ? iterGraph.A[v][index] : -1; // -1 表此圖沒有東西
            }

            bool end(){
                return index >= iterGraph.A[v].size();
            }
        private :
            SparseGraph & iterGraph;
            int v, index;
        };
    };
}

# endif