# include <iostream>
# include "UnionFindHelper.h"
# include "UnionFind.h"

using namespace std;

int main(void){
    int n = 100000000;

    /* 以下兩者都很快，時差不明顯 */
    auto qru = unionfind::QuickerUnion(n); // 甚至 n = 10 ^ 8 只花 12 秒...
    UnionFindHelper::testUnionFind(qru, n, "Quicker Union");

    auto qstu = unionfind::QuickestUnion(n); // 甚至 n = 10 ^ 8 只花 12 秒...
    UnionFindHelper::testUnionFind(qstu, n, "Quickest Union");

    return 0;
}
