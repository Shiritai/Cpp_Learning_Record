# ifndef KRUSKAL_H
# define KRUSKAL_H

# include <iostream>
# include <vector>
# include "Edge.h"
# include "UnionFind.h"
# include "MinHeap.h"

using namespace std;
using namespace unionfind;

/**
 * Minimun Span Tree 問題
 * 
 * 直接依照最短邊, 蒐集頂點
 * 採 Greedy 策略, 遇 loop 就跳過
 * 使用資料結構 unionFind 偵測是否有 loop
 **/
template <typename Graph, typename Weight>
class KruskalMST {
private:
    vector<Edge<Weight>> mst;
    Weight mstWeight;
    
public:
    KruskalMST(Graph & graph){
        MinHeap<Edge<Weight>> pq(graph.E());
        for (int i = 0; i < graph.V(); ++i){
            typename Graph::adjIterator adj(graph, i);
            for (auto e = adj.begin(); !adj.end(); e = adj.next()){
                /* 僅針對無向圖, 所以加入節點編號小者, 自動過濾掉 loop */
                if (e->from() < e->to())
                    pq.insert(* e);
            }
        }

        UnionFind uf(graph.V());
        while (!pq.isEmpty() && mst.size() < graph.V() - 1){
            auto e = pq.pop();
            if (!uf.isConnected(e.from(), e.to())){ // 判斷是否已經被納入最小路徑, 以免形成環
                mst.push_back(e);
                uf.unionThem(e.from(), e.to());
            }
        }

        for (auto it = mst.begin(); it != mst.end(); ++it){
            mstWeight += it->weight();
        }
    }

    ~KruskalMST(){}

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };
};

# endif