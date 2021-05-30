/* for method 1 : quick select */
# include "K-th_Smallest_Number_in_a_Running_Window.h"
/* for methid 2 : nth_element function */
# include <vector>
// # include <algorithm> // for debug
# include <iostream>

using namespace std;

int main(void){
    int N, M, K;
    cin >> N >> M >> K;
    int arr[N];
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    /* methid 1 : quick select */
    K_th_number_window k(arr, N, M, K - 1);
    k.print();

    cout << endl;
    
    /* method 2 : nth_element function */
    vector<int> vec(M, 0);
    for (int i = 0; i <= N - M; ++i){
        for (int j = 0; j < M; ++j)
            vec[j] = arr[i + j];
        nth_element(vec.begin(), vec.begin() + K - 1, vec.end());
        // for_each(vec.begin(), vec.end(), [](int t){cout << t << " ";}); // for debug
        cout << "\nres : " << * (vec.begin() + K - 1) << "\n\n";
    }
}