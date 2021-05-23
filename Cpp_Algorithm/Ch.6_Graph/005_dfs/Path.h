# include <vector>
# include <stack>
# include <iostream>
# include <cassert>
# include <algorithm> 

using namespace std;

template <typename Graph>
class Path {
private: 
    Graph & G;
    bool * visited; // 紀錄訪問過的序列
    int origin;
    int * path;
    
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
    Path(Graph & graph, int origin) : G(graph){
        assert(origin >= 0 && origin < G.V());
        visited = new bool[G.V()];
        path = new int[G.V()];
        this->origin = origin;
        for (int i = 0; i < G.V(); ++i){
            visited[i] = false;
            path[i] = -1;
        }
        dfs(origin);
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

    ~Path(){
        delete [] visited;
        delete [] path;
    }

};