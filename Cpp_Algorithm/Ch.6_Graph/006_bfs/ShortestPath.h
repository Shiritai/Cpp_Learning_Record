# include <vector>
# include <stack>
# include <iostream>
# include <cassert>
# include <queue>
# include <algorithm> 

using namespace std;

/* 廣度優先遍歷 -> 得無權圖的最短路徑 */
template <typename Graph>
class ShortestPath {
private: 
    Graph & G;
    bool * visited; // 紀錄訪問過的序列
    int origin;
    int * path;
    int * order;
    
    void dfs(int v){
        visited[v] = true;
        
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()){
            if (!visited[i]){
                path[i] = v;
                dfs(i); // recur
            }
        }
    }

public:
    ShortestPath(Graph & graph, int origin) : G(graph){
        assert(origin >= 0 && origin < G.V());
        visited = new bool[G.V()];
        path = new int[G.V()];
        order = new int[G.V()];
        this->origin = origin;
        for (int i = 0; i < G.V(); ++i){
            visited[i] = false;
            path[i] = -1;
            order[i] = -1;
        }
        queue<int> q;
        q.push(origin);
        visited[origin] = true;
        order[origin] = 0; // 原點到自己距離 = 0    
        while (!q.empty()){
            int tmp = q.front();
            q.pop();

            typename Graph::adjIterator adj(G, tmp);
            for (int i = adj.begin(); !adj.end(); i = adj.next()){
                if (!visited[i]){
                    q.push(i);

                    visited[i] = true;
                    path[i] = tmp;
                    order[i] = order[tmp] + 1;
                }
            }
        }
    }

    bool hasPath(int v){
        assert(v >= 0 && v < G.V());
        return visited[v];
    }
    
    void getPath(int v, vector<int> &vec){
        stack<int> st;
        int p = v;
        while(p != -1){
            st.push(p);
            p = path[p];
        }
        vec.clear();
        while (!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
    }

    void showPath(int v){
        vector<int> vec;
        getPath(v, vec);
        for_each(vec.begin(), vec.end(), [](int a){ cout << a << " -> "; });
        cout << "end\n";
    }

    int length(int v){
        assert(v >= 0 && v < G.V());
        return order[v];
    }

    ~ShortestPath(){
        delete [] visited;
        delete [] path;
        delete [] order;
    }

};