# ifndef DENSE_GRAPH_H
# define DENSE_GRAPH_H

# include <iostream>
# include <vector> 
# include <cassert>
# include "Edge.h"

using namespace std;

namespace denseGraph {
    /* 使用鄰接矩陣 */
    template <typename Weight>
    class DenseGraph {
    private:
        int v, e;
        bool directed;
        vector<vector<Edge<Weight> *>> A;

    public:
        DenseGraph(int v, bool directed){
            this->v = v;
            this->e = 0;
            this->directed = directed;
            for (int i = 0; i < v; ++i)
                A.push_back(vector<Edge<Weight> *>(v, NULL));
        }

        int V(){ return v;}
        int E(){ return e;}

        /* 直接去除平行邊的概念 */
        void addEdge(int v1, int v2, Weight w){
            assert(v1 >= 0 && v1 < v);
            assert(v2 >= 0 && v2 < v);

            if (!hasEdge(v1, v2)){ // (2) thus 加上這個
                A[v1][v2] = new Edge<Weight>(v1, v2, w);
                if (!directed)
                    A[v2][v1] = new Edge<Weight>(v2, v1, w);
                ++e; // (1) 注意 Bug : 有可能原本就有邊
            }
            else {
                A[v1][v2]->modify(w);
                if (!directed)
                    A[v2][v1]->modify(w);
            }
        }

        bool hasEdge(int v1, int v2){
            assert(v1 >= 0 && v1 < v);
            assert(v2 >= 0 && v2 < v);
            return A[v1][v2] != NULL;
        }

        void show(){
            for (int i = 0; i < v; ++i){
                for (int j = 0; j < v; ++j){
                    if (A[i][j] != NULL)
                        cout << A[i][j]->weight() << ((j != v - 1) ? "\t" : "\n");
                    else 
                        cout << "NULL" << ((j != v - 1) ? "\t" : "\n");
                }
            }
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
            Edge<Weight> * begin(){
                index = -1;
                return next();
            }
            Edge<Weight> * next(){
                for (++index; index < iterGraph.V(); ++index){
                    if (iterGraph.A[v][index])
                        return iterGraph.A[v][index];
                }
                return NULL;
            }
            bool end(){
                return index >= iterGraph.V();
            }
        };

        ~DenseGraph(){
            for (int i = 0; i < v; ++i)
                for (int j = 0; j < v; ++j)
                    if (A[i][j] != NULL)
                        delete A[i][j];
        }
    };
}

# endif