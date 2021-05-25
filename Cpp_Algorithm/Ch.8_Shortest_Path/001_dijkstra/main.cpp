#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"

using namespace std;
using namespace denseGraph;
using namespace sparseGraph;

// 测试我们的Dijkstra最短路径算法
int main() {

    string filename = "testG1.txt";
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true); // 有向圖
    // Dijkstra最短路径算法同样适用于有向图
    // SparseGraph<int> g = SparseGraph<int>(V, false); // 無向圖
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout << "Test Dijkstra:" << endl << endl;
    Dijkstra<SparseGraph<int>, int> dij(g,0);
    for( int i = 1 ; i < V ; i ++ ){
        if(dij.hasPathTo(i)){
            cout << "Shortest Path to " << i << " : " << dij.shortestPathTo(i) << endl;
            dij.showPath(i);
        }
        else
            cout << "No Path to " << i << endl;

        cout << "----------" << endl;
    }

    return 0;
}