# Heap

## 堆的特性

1. 平衡二叉樹
2. 完全樹
3. 最[大/小]堆 -> 父 Node 比子 Node [大/小]

## 以陣列實現最大堆

### 基礎

1. 從 1 開始編號 (棄用 0)
2. parent(i) = i / 2
3. left_child(i) = i * 2
4. right_child(i) = i * 2 + 1

### 添加元素

**Shift Up** : 將添加的元素放置於陣列末尾，並不斷與父節點比較，若比父節點大，則父子節點交換。如此保持最大堆的性質

### 刪除元素

**Shift Down**(刪除頂端元素) : 將最後一個元素取代頂端(第一)元素後，不斷比較兩個子節點，最大者上移，最小者(原本最後一個元素)不斷下移

### Heap Sort

#### method 1 : 一個個 insert 進 Heap 後 pop 出

#### method 2 : Heapify $O(n)$ : 欲排序陣列從子節點不斷 Shift Down 到父節點，使陣列化成堆

#### method 3 : 就地 Heapify 後排序 : 節省空間

## Index Heap

1. 引入 index 使數據的移動、交換更加快速
2. 再引入 reverse_index 使changeElement 更加快速 ($O(1)$)



# Sort 比較

Sort|Avg Complexity|就地排序|額外空間|穩定性
:-:|:-:|:-:|:-:|:-:
**Insertion**|$O(n^2)$|Y|$O(1)$|Y
**Merge**|$O(nlog(n))$|N|$O(n)$|Y
**Quick**|$O(nlog(n))$|Y|$O(log(n))$|N
**Heap**|$O(nlog(n))$|Y|$O(1)$|N
*OOXX*|$O(nlog(n))$|Y|$O(1)$|Y

上方之 *OOXX* 排序，理論上雖存在...但目前仍被未發掘
