# include <iostream>
# include "SparseGraph.h"
# include "DenseGraph.h"
# include "ReadGraph.h"
# include "Path.h"
# include "ShortestPath.h"

using namespace std;
using namespace sparseGraph;
using namespace denseGraph;

int main(void){
    string filename = "testG.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout << endl;

    Path<SparseGraph> dfs(g, 0);
    cout << "DFS : " << endl;
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g, 0);
    cout << "BFS : " << endl;
    bfs.showPath(6);

    return 0;
}