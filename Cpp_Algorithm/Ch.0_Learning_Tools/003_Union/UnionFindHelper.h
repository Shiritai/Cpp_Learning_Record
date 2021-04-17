# ifndef UNIONFINDHELPER_H
# define UNIONFINDHELPER_H

# include <iostream>
# include <cassert>
# include <time.h>
# include <string>
# include "UnionFind.h"

namespace UnionFindHelper {
    
    /* abstract interface, implemented by UnionFind Series */
    class UnionFind {
    public :
        virtual bool isConnected(int, int) = 0; // abstract method
        virtual void unionThem(int, int) = 0;
    };

    void testUnionFind(UnionFind & uf, int n, string type){
        srand(time(NULL));
        time_t startTime = clock();

        for (int i = 0; i < n; ++i){
            uf.unionThem(rand() % n, rand() % n);
        }


        for (int i = 0; i < n; ++i){
            uf.isConnected(rand() % n, rand() % n);
        }
        
        time_t endTime = clock();

        cout << type << " did " << 2 * n << " operations with : " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds." << endl;
    }

}


# endif