# include <string>
# include <sstream>
# include <cassert>
# include "Polynomial.h" 

# define PL Polynomial

PL::PL(){
    capacity = 16;
    list = new t_term[capacity];
    degree = INVALID_NUM;
    size = 0;
}

PL::~PL(){
    delete [] list;
}

void PL::add_term(int exp, Number coeff){
    PL::__add_term(exp, coeff);
}

Number PL::valueOf(Number val) const {
    if (!size)
        return 0.;
    Number res = 0., exp_val = 1.;
    int ind = 0, cur_exp = 0;
    while (ind < size){
        while (cur_exp < list[ind].exp){
            ++cur_exp;   
            exp_val *= val;
        }
        res += exp_val;
        ++ind;
    }
    return res;
}

std::string PL::to_string(int precision) const {
    std::string ret;
    if (size > 0){
        ret += ("Size : " + std::to_string(size) + \
            ", Degree : " + std::to_string(degree) + "\n");
        ret += (std::to_string(list[0].coeff).substr(0, precision) + \
             "x^" + std::to_string(list[0].exp).substr(0, precision));
        for (int i = 1; i < size; ++i)
            ret += (" + " + std::to_string(list[i].coeff).substr(0, precision) + \
             "x^" + std::to_string(list[i].exp).substr(0, precision));
    }
    return ret.size() ? ret : "EMPTY";
}

/* O(size + other.size) */
PL PL::operator+(const PL & other) const {
    PL pl_ret;
    int sz, pos, o_pos;
    sz = pos = o_pos = 0;
    while (pos < size && o_pos < other.size){
        if (list[pos].exp == other.list[o_pos].exp){
            Number tmp = list[pos].coeff + other.list[o_pos].coeff;
            if (tmp){
                pl_ret.__add_term(list[pos].exp, tmp);
                ++pos, ++o_pos, ++sz;
            }
        }
        else if (list[pos].exp < other.list[o_pos].exp){
            pl_ret.__add_term(list[o_pos]);
            ++o_pos, ++sz;
        }
        else {
            pl_ret.__add_term(other.list[o_pos]);
            ++pos, ++sz;
        }
    }
    while (pos < degree){
        pl_ret.__add_term(list[pos++]);
        ++sz;
    }
    while (o_pos < other.degree){
        pl_ret.__add_term(other.list[o_pos++]);
        ++sz;
    }
    pl_ret.size = sz;
    pl_ret.degree = degree > other.degree ? degree : other.degree;
    return pl_ret;
}

void PL::__add_term(t_term & t){
    __add_term(t.exp, t.coeff);
}

void PL::__add_term(int exp, Number coeff){
    if (size + 1 == capacity)
        __resize(capacity << 1);
    for (int i = 0; i < size; ++i){
        if (exp > list[i].exp){ // found correct position
            for (int j = size; j > i; --j)
                list[j] = list[j - 1];
            list[i] = t_term(exp, coeff);
            ++size;
            return;
        }
    }
    /* 剛好在最後一項 */
    list[size++] = t_term(exp, coeff);
    degree = exp;
}

void PL::__resize(int n_cap){
    assert(n_cap > size);
    t_term * n_list = new t_term[n_cap];
    for (int i = 0; i < size; ++i)
        n_list[i] = list[i];
    delete [] list;
    capacity = n_cap;
    list = n_list;
}