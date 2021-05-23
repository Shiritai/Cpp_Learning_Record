# include <vector>
# include <queue> // for priority_queue, functional::less, functional::greater
# include <algorithm>

using namespace std;

int main(void){
    auto pq = priority_queue<int, vector<int>, less<int>>();
    next_permutation(begin(pq), end(pq), less<int>);
}