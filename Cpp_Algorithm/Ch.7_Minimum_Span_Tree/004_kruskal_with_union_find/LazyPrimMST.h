# ifndef LAZY_PRIM_H
# define LAZY_PRIM_H

# include <vector>
# include "MinHeap.h"

using namespace std;

/**
 * Minimun Span Tree 問題
 * 
 * 利用切分定理 (Cut Property), 
 * 每次訪問最短距離的鄰近單點, 並取得所有該單點未存取的邊
 * 使用 MinHeap 做為資料結構
 **/
template <typename Graph, typename Weight>
class LazyPrimMST {
private:
    Graph & G;
    MinHeap<Edge<Weight>> pq;
    bool * marked; // 是否進入被切分那一組, 即該 vertex (的所有邊) 是否加入了 MinHeap
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit(int v){
        assert(!marked[v]);
        marked[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight> * e = adj.begin(); !adj.end(); e = adj.next())
            if (!marked[e->other(v)])
                pq.insert(* e);
    }

public:
    LazyPrimMST(Graph & graph) : G(graph), pq(MinHeap<Edge<Weight>>(graph.E())){
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i)
            marked[i] = false;
        mst.clear();
        /* Lazy Prim */
        visit(0); // 訪問最初的點
        while (!pq.isEmpty()){
            Edge<Weight> e = pq.pop();
            if (marked[e.from()] == marked[e.to()])
                continue;
            mst.push_back(e);
            visit((!marked[e.from()]) ? e.from() : e.to()); // 訪問下一個沒被 marked 的點
        }
        for (auto e = mst.begin(); e != mst.end(); ++e)
            mstWeight += (* e).weight();
    }

    ~LazyPrimMST(){
        delete [] marked;
    }
    
    vector<Edge<Weight>> mstEdges(){ return mst; }

    Weight result(){ return mstWeight; }
};

# endif