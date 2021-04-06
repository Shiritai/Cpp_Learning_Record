# ifndef BINARYSEARCHTREE_H
# define BINARYSEARCHTREE_H

# include <iostream>
# include <cassert>
# include <queue>
using namespace std;

template <typename K, typename V> // K : key, V : value
class BST {
private:
    struct Node {
        K key;
        V value;
        Node * left, * right;

        Node(K key, V value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }

        Node(Node * tmp){
            this->key = key, this->value = value;
            this->left = left, this->right = right;
        }
    };
    
    Node * root;
    int _size_;

    /* *
     * Use Recursion
     * 以 cur 為根, 試著插入 Node(key, value)
     * return 插入新 Node 後的根
     * */
    Node * insert(Node * cur, K key, V value){
        if (cur == NULL){ // basis
            cur = new Node(key, value); // 也可以直接 return new Node(key, value)
            ++_size_;
        }
        else if (key > cur->key) // inductive
            cur->right = insert(cur->right, key, value);
        else if (key < cur->key) // inductive
            cur->left = insert(cur->left, key, value);
        else // key == cur->key, i.e. refresh value // inductive
            cur->value = value;
        return cur;
    }

    bool contain(Node * cur, K key){
        if (cur == NULL) // basis
            return false;
        if (key > cur->key) // inductive
            return contain(cur->right, key);
        else if (key < cur->key) // inductive
            return contain(cur->left, key);
        else // key == cur->key // inductive
            return true;
    }

    V * search(Node * cur, K key){
        if (cur == NULL) // basis
            return NULL;
        if (key > cur->key) // inductive
            return search(cur->right, key);
        else if (key < cur->key) // inductive
            return search(cur->left, key);
        else // key == cur->key // inductive
            return &(cur->value);
    }

    typedef enum FUNC {
        INSERT, CONTAIN, SEARCH
    } FUNC;

    /* *
     * dive from root node and find the proper parent node
     * 嘗試特定出 node, 並返回之 
     * */
    Node * dive(K key, V * value, FUNC func){
        Node * tmp = root, * prev = NULL;
        int direction = 0; // non
        while (tmp != NULL){
            if (key < tmp->key)
                prev = tmp, tmp = tmp->left, direction = 1;
            else if (key > tmp->key)
                prev = tmp, tmp = tmp->right, direction = 2;
            else { // 成功找到
                switch (func){
                    case INSERT: // 插入 -> 更新 value, 若未找到跳出迴圈 (tmp == NULL), return insert() 新增 node
                        tmp->value = * value;
                        return tmp;
                    case CONTAIN: // 包含 -> return 同樣 key 的 node 回去就好
                        return tmp;
                    case SEARCH: // 搜尋 -> return node
                        return tmp;
                    default:
                        cout << "Switch error\n";
                }
            }
        }
        if (func == INSERT){
            if (direction == 1)
                prev->left = tmp = new Node(key, * value);
            else if (direction == 2)
                prev->right = tmp = new Node(key, * value);
            ++_size_;
        }
        return tmp;
    }

    void preOrder(Node * cur){
        if (cur != NULL){
            cout << "Key : " << cur->key << ", value : " << cur->value << endl;
            preOrder(cur->left);
            preOrder(cur->right);
        }
    }

    void inOrder(Node * cur){
        if (cur != NULL){
            preOrder(cur->left);
            cout << "Key : " << cur->key << ", value : " << cur->value << endl;
            preOrder(cur->right);
        }
    }

    void postOrder(Node * cur){
        if (cur != NULL){
            preOrder(cur->left);
            preOrder(cur->right);
            cout << "Key : " << cur->key << ", value : " << cur->value << endl;
        }
    }

    void freeTree(Node * cur){
        if (cur != NULL){
            freeTree(cur->left);
            freeTree(cur->right);
            delete cur;
            --_size_;
        }
    }
    Node * minimum(Node * cur){
        assert(cur != NULL);
        Node * tmp = cur;
        while (tmp->left != NULL)
            tmp = tmp->left;
        return tmp->key;
    }

    Node * maximum(Node * cur){
        assert(cur != NULL);
        Node * tmp = cur;
        while (tmp->right != NULL)
            tmp = tmp->right;
        return tmp->key;
    }

    /* 刪除當前根以下之最小節點, return 新的根 */
    Node * removeMin(Node * cur){
        if (cur->left == NULL){
            Node successor = cur->right;
            delete cur;
            --_size_;
            return successor;
        }
        cur->left = removeMin(cur->left);
        return cur;
    }

    /* 刪除當前根以下之最大節點, return 新的根 */
    Node * removeMax(Node * cur){
        if (cur->right == NULL){
            Node successor = cur->left;
            delete cur;
            --_size_;
            return successor;
        }
        cur->right = removeMax(cur->right);
        return cur;
    }

    /* 刪除當前根以下之 特定 key 節點, return 新的根 */
    Node * remove(Node * cur, K key){
        if (cur == NULL)
            return NULL;
        if (key == cur->key){
            Node * successor = NULL;
            if (cur->left == NULL)
                successor = cur->right;
            else if (cur->right == NULL)
                successor = cur->left;
            else {
                successor = new Node(minimum(cur->right));
                ++_size_;
                successor->right = removeMin(cur->right);
                successor->left = cur->left;
            }
            --_size_;
            delete cur;
            return successor;
        }
        else if (key < cur->key)
            cur = remove(cur->left, key);
        else // key > cur->key
            cur = remove(cur->right, key);
        return cur;
    }


public:
    BST(){
        root = NULL;
        _size_ = 0;
    }

    int size(){ return _size_;}

    bool isEmpty(){ return _size_ == 0;}

    void insert(K key, V value){
        root = insert(root, key, value);
    }

    bool contain(K key){
        return contain(root, key);
    }

    V * search(K key){
        return search(root, key);
    }

    void insertNonRecur(K key, V value){ // non-recur version
        if (dive(key, &value, INSERT) == NULL)
            root = new Node(key, value);
        return;
    }

    bool containNonRecur(K key){ // non-recur version
        return dive(key, NULL, CONTAIN) == NULL ? false : true;
    }

    V * searchNonRecur(K key){ // non-recur version
        Node * tmp = dive(key, NULL, SEARCH);
        return tmp != NULL ? &(tmp->value) : NULL;
    }

    K minimum(){
        assert(root != NULL);
        return minimum(root)->key;
    }

    K maximum(){
        assert(root != NULL);
        return maximum(root)->key;
    }

    void * removeMin(){
        if (root)
            root = removeMin(root);
    }

    void * removeMax(){
        if (root)
            root = removeMax(root);
    }

    void remove(K key){
        root = remove(root, key);
    }

    void preOrder(){ preOrder(root);}
    
    void inOrder(){ preOrder(root);}
        
    void postOrder(){ preOrder(root);}

    void levelOrder(){
        queue<Node *> q;
        q.push(root);
        while (!q.empty()){
            Node * cur = q.front();
            q.pop();
            cout << "Key : " << cur->key << ", value : " << cur->value << endl;
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }

    ~BST(){ freeTree(root);} // just the same as postOrder
};

# endif