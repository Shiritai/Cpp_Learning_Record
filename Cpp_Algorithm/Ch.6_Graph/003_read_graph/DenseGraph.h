# ifndef DENSE_GRAPH_H
# define DENSE_GRAPH_H

# include <iostream>
# include <vector> 
# include <cassert>

using namespace std;

namespace denseGraph {
    /* 使用鄰接矩陣 */
    class DenseGraph {
    private:
        int v, e;
        bool directed;
        vector<vector<bool>> A;
    public :
        DenseGraph(int v, bool directed){
            this->v = v;
            this->e = 0;
            this->directed = directed;
            for (int i = 0; i < v; ++i)
                A.push_back(vector<bool>(v, false));
        }

        int V(){ return v;}
        int E(){ return e;}

        /* 直接去除平行邊的概念 */
        void addEdge(int v1, int v2){
            assert(v1 >= 0 && v1 < v);
            assert(v2 >= 0 && v2 < v);

            /* 以下判斷是否已經存在邊的方式, 自發的解決了平行邊的問題 */
            if (!hasEdge(v1, v2)){ // (2) thus 加上這個
                A[v1][v2] = true;
                if (!directed)
                    A[v2][v1] = true;
                ++e; // (1) 注意 Bug : 有可能原本就有邊
            }
        }

        bool hasEdge(int v1, int v2){
            assert(v1 >= 0 && v1 < v);
            assert(v2 >= 0 && v2 < v);
            return A[v1][v2];
        }

        void show(){
            for (int i = 0; i < v; ++i)
                for (int j = 0; j < v; ++j)
                    cout << A[i][j] << ((j != v - 1) ? "\t" : "\n");
        }

        class adjIterator {
        private: 
            DenseGraph &iterGraph;
            int v;
            int index;
        public: 
            adjIterator(DenseGraph & g, int v) : iterGraph(g) {
                this->v = v;
                this->index = -1;
            }
            int begin(){
                index = -1;
                return next();
            }
            int next(){
                for (++index; index < iterGraph.V(); ++index){
                    if (iterGraph.A[v][index])
                        return index;
                }
                return -1;
            }
            bool end(){
                return index >= iterGraph.V();
            }
        };
    };
}

# endif