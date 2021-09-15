# ifndef DIJKSTRA_H
# define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

/** 
 * Shortest Path 問題
 * 
 * n
 * 默認使用在無 「負權邊」 的圖
 * 
 * 尋找 origin 至各點的最短路徑,
 * 每次 Greedy 的取得相鄰點的最短邊,
 * 並隨之使用 Relaxation,
 * 更新 origin 至各點的最短距離,
 * 直到所有點都被訪問, Relaxed,
 * 類似 Prim, 採用 Index MinHeap 作為資結
 */
template <typename Graph, typename Weight>
class Dijkstra {
private:
    Graph & G;
    int origin;

    Weight * distTo; // 盛裝
    bool * marked;
    vector<Edge<Weight> *> path;
public:
    Dijkstra(Graph & graph, int origin) : G(graph) {
        this->origin = origin;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i){
            distTo[i] = Weight(); // 使用默認構造函數
            marked[i] = false;
            path.push_back(NULL);
        }
        IndexMinHeap<Weight> ipq(G.V());
        /* Dijkstra */
        /* 1. origin 相關初始化 */
        distTo[origin] = Weight(); // 對原點初始化距離 = 0
        path[origin] = new Edge<Weight>(origin, origin, Weight());
        marked[origin] = true;
        ipq.insert(origin, distTo[origin]);
        /* 2. 尋路 */
        while (!ipq.isEmpty()){
            int next = ipq.popMinIndex();
            marked[next] = true;
            /* 對 next 頂點進行鬆弛 (Relaxation) 操作 */
            typename Graph::adjIterator adj(G, next);
            for (auto e = adj.begin(); !adj.end(); e = adj.next()){
                int some = e->other(next);
                if (!marked[some]){
                    if (path[some] == NULL || distTo[next] + e->weight() < distTo[some]){ // 是否有鬆弛路徑
                        distTo[some] = distTo[next] + e->weight();
                        path[some] = e;
                        if (ipq.contain(some))
                            ipq.set(some, distTo[some]);
                        else 
                            ipq.insert(some, distTo[some]);
                    }
                }
            }
        }
    }

    ~Dijkstra(){
        delete [] distTo;
        delete [] marked;
    }
    
    Weight shortestPathTo(int v){ return distTo[v]; }
    
    bool hasPathTo(int v){ return marked[v]; }
    
    /* 從 origin -> v 的最短路徑 */
    void shortestPath(int v, vector<Edge<Weight>> &vec){
        assert(v >= 0 && v < G.V());
        stack<Edge<Weight> *> st;
        Edge<Weight> * e = path[v];
        while (e->from() != e->to()){ // 自頂點 v 回溯至 origin
            st.push(e);
            e = path[e->from()];
        }
        while (!st.empty()){
            e = st.top();
            st.pop();
            vec.push_back(* e);
        }
    }

    void showPath(int v){
        assert(v >= 0 && v < G.V());
        vector<Edge<Weight>> vec;
        shortestPath(v, vec);
        int i;
        for (i = 0; i < vec.size(); ++i){
            cout << vec[i].from() << " -> ";
        }
        cout << vec[(i > 0) ? i - 1 : 0].to() << endl;
    }
};

# endif