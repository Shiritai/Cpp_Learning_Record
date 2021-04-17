# C++ Data Structure

## Iterator

以索引的概念, 存取 Container 的元素 (可以將 Pointer 視為其子集), 分為 :

1. Random Access : 可隨機訪問，支持 ++, --, 增或減 x 項
2. Bidirectional : 支持 ++, --
3. Forward : 只可以 ++

C++ Iterator 所有賦值操作都是 $O(n)$

Iterator 頭尾 :

    `c.begin()` : 指向第一項的迭代器
    `c.end()` : 指向最後一項的後一項，內容不可預期

Iterator 都有反向版本 :

    `c.rbegin()` : 指向最後一項的迭代器
    `c.rend()` : 指向第一項的前一項，內容不可預期



