# ifndef PRIM_H
# define PRIM_H

# include <vector>
# include "IndexMinHeap.h"

using namespace std;

/**
 * Minimun Span Tree 問題
 * 
 * 利用切分定理 (Cut Property), 
 * 每次僅需為各個單點保留最短距離的邊, 
 * 因此改用 Index MinHeap 做為資料結構
 * 方便以索引的方式紀錄可以訪問單點的最短距離
 * */
template <typename Graph, typename Weight>
class PrimMST {
private:
    Graph & G;
    IndexMinHeap<Weight> ipq;
    vector<Edge<Weight> *> edgeTo;
    bool * marked; // 是否進入被切分那一組, 即該 vertex (的所有邊) 是否加入了 IndexMinHeap
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit(int v){
        assert(!marked[v]);
        marked[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight> * e = adj.begin(); !adj.end(); e = adj.next()){
            int anotherV = e->other(v);
            if (!marked[anotherV]){
                if (!edgeTo[anotherV]){
                    ipq.insert(anotherV, e->weight());
                    edgeTo[anotherV] = e;
                }
                else if (e->weight() < edgeTo[anotherV]->weight()){
                    ipq.set(anotherV, e->weight());
                    edgeTo[anotherV] = e;
                }
            }
        }
    }

public:
    PrimMST(Graph & graph) : G(graph), ipq(IndexMinHeap<Weight>(graph.E())){
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i){
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();
        /* Prim */
        visit(0); // 訪問最初的點
        while (!ipq.isEmpty()){
            int v = ipq.popMinIndex();
            assert(edgeTo[v]);
            mst.push_back(* edgeTo[v]);
            visit(v);
        }
        for (auto e = mst.begin(); e != mst.end(); ++e)
            mstWeight += (* e).weight();
    }

    ~PrimMST(){
        delete [] marked;
    }
    
    vector<Edge<Weight>> mstEdges(){ return mst; }

    Weight result(){ return mstWeight; }
};

# endif