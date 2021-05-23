# ifndef EDGE_H
# define EDGE_H

# include <iostream>

using namespace std;

template <typename Weight>
class Edge {
private:
    int v1, v2;
    Weight w;
public:
    Edge(int v1, int v2, Weight w){
        this->v1 = v1;
        this->v2 = v2;
        this->w = w;
    }

    /* 更新 Edge */
    void modify(Weight w){
        this->w = w;
    }

    Edge(){}
    ~Edge(){}
    
    /* 打哪個頂點來 */
    int from(){ return v1; }
    /* 到哪個頂點 */
    int to(){ return v2; }

    Weight weight(){ return w; }
    
    /* 傳回另一個對應頂點 */
    int other(int x){
        assert(x == v1 || x == v2);
        return x == v1 ? v2 : v1;
    }

    friend ostream & operator<< (ostream &o, const Edge &e){
        o << e.v1 << "-" << e.v2 << " : " << e.w;
        return o;
    }
    
    bool operator< (Edge<Weight> & e){
        return w < e.w;
    }

    bool operator<= (Edge<Weight> & e){
        return w <= e.w;
    }

    bool operator== (Edge<Weight> & e){
        return w == e.w;
    }

    bool operator> (Edge<Weight> & e){
        return w > e.w;
    }

    bool operator>= (Edge<Weight> & e){
        return w >= e.w;
    }
};

# endif