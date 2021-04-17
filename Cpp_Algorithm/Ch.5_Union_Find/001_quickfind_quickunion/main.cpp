# include <iostream>
# include "UnionFindHelper.h"
# include "UnionFind.h"

using namespace std;

int main(void){
    int n = 10000000;

    auto qf = unionfind::QuickFind(n);
    UnionFindHelper::testUnionFind(qf, n, "Quick Find");

    auto qu = unionfind::QuickUnion(n);
    UnionFindHelper::testUnionFind(qu, n, "Quick Union");

    return 0;
}
