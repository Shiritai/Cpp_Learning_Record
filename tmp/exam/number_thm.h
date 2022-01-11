# ifndef NUMBER_THM_H
# define NUMBER_THM_H

# include <string>
# include <cstring>
# include <utility>
# include <vector>
# include <sstream>
# include <iostream>

using namespace std;

namespace eroikoADS {

pair<int, int> CRT(vector<pair<int, int>> & data){
    const int sz = data.size();
    int res = 0, coo = 1;
    cout << "x = ";
    for (int i = 0; i < sz; ++i){
        coo *= data[i].second;
        int mul = 1;
        for (int j = 0; j < sz; ++j)
            if (j != i)
                mul *= data[j].second;
        // cout << "mul: " << mul << endl;
        int _res = mul;
        while (_res % data[i].second != 1)
            _res += mul;
        res += data[i].first * _res;
        cout << data[i].first << " x " << _res;
        if (i + 1 != sz)
            cout << " + ";
        else 
            cout << "  ( mod " << coo << " )";
    }
    cout << " = " << res << endl;
    while (res > coo) res -= coo;
    return pair<int, int>(res, coo);
}

vector<pair<int, int>> factorization(int n){
    const int num = n >> 1;
    bool table[num]; // traverse number (sieve) table
    memset(table, 0, sizeof(bool) * num);
    int prime[num]; // prime table
    prime[0] = 2; // of course
    int pr_i = 1;
    vector<pair<int, int>> res;
    {
        /* compute 2's first to avoid wasting memory and speed up */
        int times = 0;
        while (n >> 1 && !(n & 1)){
            n >>= 1;
            ++times;
        }
        if (times)
            res.emplace_back(pair<int, int>(2, times));
    }
    for (int i = 3; i < num && n > 1; i += 2){
        if (!table[i]){
            int times = 0;
            while (!(n % i)){
                ++times;
                n /= i;
            }
            if (times)
                res.emplace_back(pair<int, int>(i, times));
            prime[pr_i++] = i;
        } 
        for (int j = 0; j < pr_i && i * prime[j] < num; ++j){
            table[i * prime[j]] = true;
            if (!(i % prime[j])) break;
        }   
    }
    return res;
}

int Euler_phi_fn(int n){
    int res = n;
    auto v = factorization(n);
    for (auto & p: v)
        res /= p.first;
    for (auto & p: v)
        res *= p.first - 1;
    return res;
}

pair<int, int> extended_Euclidean_algo(int a, int b){
    int num[] = { a, b };
    pair<int, int> coeff[] = {
        pair<int, int>(1, 0), 
        pair<int, int>(0, 1)
    };
    bool turn = b > a;
    int diff;
    while (true) {
        int times = num[turn] / num[!turn];
        diff = num[turn] - num[!turn] * times;
        if (!diff)
            return coeff[!turn];
        coeff[turn].first -= times * coeff[!turn].first;
        coeff[turn].second -= times * coeff[!turn].second;
        num[turn] = diff;
        turn = !turn;
    };
}

int modular_exponentiation(int num, int exp, int high_bit, int mod){
    int ret = 1;
    while (high_bit){
        ret *= ret;
        ret %= mod;
        if (high_bit & exp) ret *= num;
        ret %= mod;
        high_bit >>= 1;
    }
    return ret;
}

/** 
 * 大數次方取模函式，使用對分演算法
 */
int modular_exponentiation(int num, int exp, int mod){
    int high_bit = 1;
    while ((high_bit << 1) < exp) high_bit <<= 1;
    return modular_exponentiation(num, exp, high_bit, mod);
}

string decrypt(vector<int> && txt, int e, int n){
    int phi = Euler_phi_fn(n);
    int d = extended_Euclidean_algo(e, phi).first;
    while (d < 0) d += phi;
    int high_bit = 1;
    while ((high_bit << 1) < d) high_bit <<= 1;
    string res;
    for (auto i: txt)
        res += (char) modular_exponentiation(i, d, high_bit, n);
    return res;
}

string decrypt(vector<int> & txt, int e, int n){
    return decrypt((vector<int> &&) txt, e, n);
}

vector<int> parse(char * txt, char * deli){
    vector<int> v;
    strtok(txt, deli);
    while (txt){
        int val;
        sscanf(txt, "%d", &val);
        v.push_back(val);
        txt = strtok(NULL, deli);
    }
    return v;
}

string decrypt(char * txt, char * deli, int e, int n){
    return decrypt(parse(txt, deli), e, n);
}

/* RSA decrypting program */
class RSA {
public:
    int phi; // phi(n)
    int d; // private key d s.t. e * d = 1 mod phi(n)
    int e; // public key, coprime to phi(n)
    int n; // public key, multiple of two prime numbers p and q
    vector<int> res_ls;
    string result;
    RSA(char * msg, char * deli, int e, int n);
    string to_string() const;
    friend std::ostream& operator<<(std::ostream& o, const RSA & rsa);
    string decode(int start, int shift);
};

RSA::RSA(char * msg, char * deli, int e, int n): phi(Euler_phi_fn(n)), 
    d(extended_Euclidean_algo(e, phi).first), e(e), n(n) {
    while (d < 0) d += phi;
    int high_bit = 1;
    while ((high_bit << 1) < d) high_bit <<= 1;
    auto v = parse(msg, deli);
    // for (auto i: parse(msg, deli))
    for (auto i: v){
        int r = modular_exponentiation(i, d, high_bit, n);
        res_ls.push_back(r);
        result += (char) r;
    }
}

string RSA::to_string() const {
    ostringstream ss;
    ss << "e: " << e << endl;
    ss << "n: " << n << endl;
    ss << "phi: " << phi << endl;
    ss << "d: " << d << endl;
    ss << "result numbers: ";
    for (auto i: res_ls)
        ss << i << ' ';
    ss << endl;
    // ss << "result string: " << result << endl;
    return ss.str();
}

string RSA::decode(int start, int shift){
    ostringstream res;
    for (auto i: res_ls)
        res << (char) (i - shift + start);
    return res.str();
}

std::ostream& operator<<(std::ostream& o, const RSA & rsa){
    o << rsa.to_string();
    return o;
}

}

# endif /* NUMBER_THM_H */