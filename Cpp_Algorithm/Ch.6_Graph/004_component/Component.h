# include <cassert>
using namespace std;

template <typename Graph>
class Component {
private: 
    Graph & G;
    bool * visited; // 紀錄訪問過的序列
    int cnt;
    int * id; // 不同分量給不同 id

    void dfs(int v){
        visited[v] = true;
        
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()){
            if (!visited[i])
                dfs(i); // recur
        }
    }

public:
    Component(Graph & graph) : G(graph){
        visited = new bool[G.V()];
        id = new int[G.V()];
        cnt = 0;
        for (int i = 0; i < G.V(); ++i){
            visited[i] = false;
            id[i] = -1;
        }

        for (int i = 0; i < G.V(); ++i){
            if (!visited[i]){
                dfs(i);
                ++cnt;
            }
        }
    }

    ~Component(){
        delete [] visited;
        delete [] id;
    }

    int count(){ return cnt; }

    bool isConnected(int v1, int v2){
        assert(v1 >= 0 && v1 < G.V());
        assert(v2 >= 0 && v2 < G.V());
        return id[v1] == id[v2];
    }
    
};