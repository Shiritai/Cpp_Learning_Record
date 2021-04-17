# Union Find

> 1. To solve Connectivity Problems
>   e.g. 抽象網路的連接狀態
> 2. Implement "Union"
> 3. 也是一棵樹喔

> 思想 : 若一個演算法回答了除了所需問題外的額外功能，就表示此算法很有可能有優化空間，優化成能回答比較少問題的，更加快速的演算法

## Union 支持操作

```C++
void union(P p, Q q);
P find(P p);
bool isConnected(P p, Q q);
```

## Union Find 整體操作近乎是 $O(1)$ 複雜度 more precisely, $O(alpha)$