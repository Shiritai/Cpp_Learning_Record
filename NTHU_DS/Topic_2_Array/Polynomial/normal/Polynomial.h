# ifndef _POLYNOMIAL_H
# define _POLYNOMIAL_H

# include <string>
/* Available degree range [0, MAX_INT] */
# define INVALID_NUM 0xffffffff

typedef float Number;

class Polynomial {
public:
    /* 係數模板化, 建議使用 int, float, double 等基本類型 */
    Polynomial();
    ~Polynomial();
    void add_term(int exp, Number coeff);
    Polynomial operator+(const Polynomial & other) const;
    Number valueOf(Number val) const;
    std::string to_string(int precision = 3) const;

private:
    struct t_term {
        Number coeff;
        int exp;
        t_term(){
            exp = coeff = INVALID_NUM;
        }
        t_term(int exp, Number coeff){
            this->exp = exp;
            this->coeff = coeff;
        }
    };

    int degree;
    t_term * list;
    int size, capacity;

    void __add_term(t_term & t);
    void __add_term(int exp, Number coeff);
    void __resize(int n_cap);
};

# endif