# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <cassert>

using namespace std;

template <typename Graph>
class ReadGraph {
public:
    /* 對特定格式的圖資料檔, 讀取至 Graph 資料結構 */
    ReadGraph(Graph & graph, const string & filename){
        ifstream file(filename);
        string line;
        int V, E;

        assert(file.is_open());

        /* read the numbers of edge, vertex */
        assert(getline(file, line));
        stringstream ss(line);
        ss >> V >> E;
        assert(V == graph.V());

        for (int i = 0; i < E; ++i){
            assert(getline(file, line));
            stringstream ss(line);
            int v1, v2;
            ss >> v1 >> v2;
            assert(v1 >= 0 && v1 < V);
            assert(v2 >= 0 && v2 < V);
            graph.addEdge(v1, v2);
        }
    }
};
