# ifndef BELLMANFORD_H
# define BELLMANFORD_H

# include <iostream>
# include <cassert>
# include <stack>
# include <vector>
# include "Edge.h"

using namespace std;

/** 
 * Shortest Path 問題
 * 
 * Bellman-Ford Algorithm
 * Complexity : O(E * V) (低效)
 * 允許負權邊, 並且可以用來偵測是否有負權環
 * 
 * 優化形式 : Queue-Based Bellman-Ford algo
 */
template <typename Graph, typename Weight>
class BellmanFord {
private:
    Graph & G;
    int origin;
    Weight * distTo;
    vector<Edge<Weight> *> path;

    const bool hasNegativeCycle;

    bool detectNegativeCycle(){
        for (int i = 0; i < G.V(); ++i){
            typename Graph::adjIterator adj(G, i);
            for (Edge<Weight> * e = adj.begin(); !adj.end(); e = adj.next())
                if (!path[e->to()] || distTo[e->from()] + e->weight() < distTo[e->to()])
                    return true; // 因為還可以鬆弛
        }
        return false;
    }

public:
    BellmanFord(Graph & graph, int origin) : G(graph) {
        this->origin = origin;
        distTo = new Weight[G.V()];
        for (int i = 0; i < G.V(); ++i){
            path.push_back(NULL);
        }
        /* Bellman Ford */
        /* init origin */
        distTo[origin] = Weight();
        /* 對整張圖做 V - 1 次 Relaxation */
        for (int pass = 1; pass < G.V(); ++pass){
            for (int i = 0; i < G.V(); ++i){
                typename Graph::adjIterator adj(G, i);
                for (Edge<Weight> * e = adj.begin(); !adj.end(); e = adj.next()){
                    if (!path[e->to()] || distTo[e->from()] + e->weight() < distTo[e->to()]){
                        distTo[e->to()] = distTo[e->from()] + e->weight();
                        path[e->to()] = e;
                    }
                }
            }
        }
        hasNegativeCycle = detectNegativeCycle();
    }
    
    bool negativeCycle(){ return hasNegativeCycle; }

    Weight shortestPathTo(int v){
        assert(v >= 0 && v < G.V());
        assert(!hasNegativeCycle);
        return distTo[v];
    }

    bool hasPathTo(int v){
        assert(v >= 0 && v < G.V());
        return path[v] != NULL;
    }

    void shortestPath(int v, vector<Edge<Weight>> & vec){
        assert(v >= 0 && v < G.V());
        assert(!hasNegativeCycle);
        stack<Edge<Weight> *> st;
        Edge<Weight> * e = path[v];
        while (e->from() != origin){ // 自頂點 v 回溯至 origin
            st.push(e);
            e = path[e->from()];
        }
        st.push(e);

        while (!st.empty()){
            e = st.top();
            st.pop();
            vec.push_back(* e);
        }
    }

    void showPath(int v){
        assert(v >= 0 && v < G.V());
        assert(!hasNegativeCycle);

        vector<Edge<Weight>> vec;
        shortestPath(v, vec);
        int i;
        for (i = 0; i < vec.size(); ++i)
            cout << vec[i].from() << " -> ";
        cout << vec[i > 0 ? i - 1 : 0].to() << endl;
    }
};

# endif