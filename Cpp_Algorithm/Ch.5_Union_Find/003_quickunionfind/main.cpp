# include <iostream>
# include "UnionFindHelper.h"
# include "UnionFind.h"

using namespace std;

int main(void){
    int n = 10000000;

    auto qstu = unionfind::QuickestUnion(n); // 甚至 n = 10 ^ 8 只花 12 秒...
    UnionFindHelper::testUnionFind(qstu, n, "Quickest Union");

    auto quf = unionfind::QuickUnionFind(n); // 甚至 n = 10 ^ 8 只花 8 秒...
    UnionFindHelper::testUnionFind(quf, n, "Quick Union Find");

    /* 遞迴 */
    auto qruf = unionfind::QuickerUnionFind(n); // 甚至 n = 10 ^ 8 只花 8 秒...
    UnionFindHelper::testUnionFind(qruf, n, "Quicker Union Find");

    /* 迴圈 */
    auto qstuf = unionfind::QuickestUnionFind(n); // 甚至 n = 10 ^ 8 只花 7 秒...
    UnionFindHelper::testUnionFind(qstuf, n, "Quickest Union Find");

    return 0;
}
