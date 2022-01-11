# include "number_thm.h"
# include <iostream>

using namespace std;

int main(void){
    /* Exam 2020 (1) */
    // auto ans = eroikoADS::modular_exponentiation(654, 321, 13);
    // cout << ans << endl;

    /* Exam 2020 (2) */
    vector<pair<int, int>> v;
    v.push_back(pair<int, int>(3, 8));
    v.push_back(pair<int, int>(6, 9));
    v.push_back(pair<int, int>(7, 25));
    // v.push_back(pair<int, int>(3, 4));
    // v.push_back(pair<int, int>(2, 5));
    // v.push_back(pair<int, int>(6, 9));
    // v.push_back(pair<int, int>(1, 13));
    auto crt = eroikoADS::CRT(v);
    cout << crt.first << " + " << crt.second <<  "k" << endl;

    /* Exam 2020 (3) */
    // char msg[] = "139 195 79 154 204", deli[] = " ";
    // eroikoADS::RSA rsa(msg, deli, 103, 209);
    // cout << rsa;
    // cout << "result string: " << rsa.decode('a', 27);
}