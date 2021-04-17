# include <vector>
# include <queue> // for priority_queue, functional::less, functional::greater

using namespace std;

int main(void){
    auto pq = priority_queue<int, vector<int>, less<int>>();
}