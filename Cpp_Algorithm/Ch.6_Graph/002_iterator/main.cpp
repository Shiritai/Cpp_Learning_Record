# include <iostream>
# include <time.h>
# include "SparseGraph.h"
# include "DenseGraph.h"

using namespace std;
using namespace sparseGraph;
using namespace denseGraph;

int main(void){
    int V = 20;
    int E = 100;

    srand(time(NULL));

    /* for Sparse Graph */
    SparseGraph g1(V, false);

    for (auto i = 0; i < E; ++i){
        g1.addEdge(rand() % V, rand() % V);
    }

    /* O(E) */
    for (auto i = 0; i < V; ++i){
        cout << i << " : ";
        SparseGraph::adjIterator adj(g1, i);
        for (auto j = adj.begin(); !adj.end(); j = adj.next())
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";

    /* for Dense Graph */
    DenseGraph g2(V, false);

    for (auto i = 0; i < E; ++i){
        g2.addEdge(rand() % V, rand() % V);
    }

    /* O(V^2) */
    for (auto i = 0; i < V; ++i){
        cout << i << " : ";
        DenseGraph::adjIterator adj2(g2, i);
        for (auto j = adj2.begin(); !adj2.end(); j = adj2.next())
            cout << j << " ";
        cout << "\n";
    }
}