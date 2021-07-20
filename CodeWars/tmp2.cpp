# include <iostream>
# include <vector>
# include <string>

class BigPositiveNum {
public:
    BigPositiveNum(int n){
        BigPositiveNum(std::to_string(n));
    }
    BigPositiveNum(long long n){
        BigPositiveNum(std::to_string(n));
    }
    BigPositiveNum(std::string n){
        size = n.size();
        bigNum = new LinkedNum(n.c_str()[size - 1] - '0');
        if (size > 1){
            LinkedNum * tmp = bigNum;
            for (int i = size - 2; i >= 0; --i){
                tmp->next = new LinkedNum(n.c_str()[i] - '0');
                tmp = tmp->next;
            }
        }
        stripZero();
    }

    std::string toString(){
        char res[size + 1];
        res[size] = '\0';
        LinkedNum * tmp = bigNum;
        for (int i = size - 1; i >= 0; --i){
            res[i] = tmp->digit + '0';
            tmp = tmp->next;
        }
        return std::string(res);
    }
    
    BigPositiveNum & operator+=(const BigPositiveNum & other){
        LinkedNum * a = bigNum, * b = other.bigNum;
        while (b){
            a->digit += b->digit;
            if (!(a->next)){
                a->next = new LinkedNum(0);
                ++size;
            }
            a = a->next;
            b = b->next;
        }
        rippleCarryUp();
        stripZero();
        return *this;
    }

    BigPositiveNum & operator*=(const BigPositiveNum & other){
        /* init result linked_number */
        LinkedNum * res = new LinkedNum();
        int maxSize = ((size > other.size) ? size : other.size) << 1; // 我相信不會有人用超過 0x7fffffff 位的數字吧
        int i = maxSize;
        std::cout << "max size : " << maxSize << std::endl;
        LinkedNum * tmp = res;
        while (--i > 0){
            tmp->next = new LinkedNum();
            tmp = tmp->next;
        }

        /* Add, pivot and traverse each b's node */
        LinkedNum * resPivot = res, * b = other.bigNum;
        while (b){
            for (LinkedNum * r = resPivot, * a = bigNum; a; a = a->next, r = r->next){
                r->digit += a->digit * b->digit;
            }
            b = b->next;
            resPivot = resPivot->next;
        }

        /* delete origin bigNum */
        while ((tmp = bigNum)){
            bigNum = bigNum->next;
            delete tmp;
        }
        delete bigNum;

        /* repoint to new bigNum */
        bigNum = res;
        size = maxSize;

        /* last work */
        // std::cout << "bn : " << bigNum->digit << std::endl;
        // if (bigNum->next)
        //     std::cout << "bn : " << bigNum->next->digit << std::endl;
        // stripZero();
        // std::cout << "Call ripple" << std::endl;
        rippleCarryUp();
        // std::cout << "Out of ripple" << std::endl;
        stripZero();
        return *this;
    }
    
// private:

    struct LinkedNum {
        int digit;
        LinkedNum * next; // 由低至高位
        LinkedNum(){
            digit = 0;
            next = NULL;
        }
        LinkedNum(int d){
            digit = d;
            next = NULL;
        }
    };
    int size;
    LinkedNum * bigNum;

    void stripZero(){
        LinkedNum * tmp = bigNum, * toStrip = NULL;
        bool zeroHeadFlag = false;
        while (tmp){
            if (tmp != bigNum && !(tmp->digit) && !zeroHeadFlag){
                toStrip = tmp;
                zeroHeadFlag = true;
            }
            else if (tmp->digit){
                toStrip = NULL;
                zeroHeadFlag = false;
            }
            tmp = tmp->next;
        }
        if (toStrip){ // need strip
            int numOfStripped = 0;
            LinkedNum * prev;
            while ((prev = toStrip)){
                toStrip = toStrip->next;
                delete prev;
                ++numOfStripped;
            }
            size -= numOfStripped;
        }
    }

    void rippleCarryUp(){
        LinkedNum * tmp = bigNum;
        while (tmp){
            // std::cout << "meow" << std::endl;
            // std::cout << "peek (1) : " << tmp->digit << std::endl;
            // if (tmp->next)
            //     std::cout << "peek (2) : " << tmp->next->digit << std::endl;
            if (tmp->digit > 9){
                int d = tmp->digit;
                tmp->digit = d % 10;
                if (!(tmp->next)){
                    tmp->next = new LinkedNum(d / 10);
                    ++size;
                }
                else 
                    tmp->next->digit += d / 10;
            }
            tmp = tmp->next;
        }
    }

    ~BigPositiveNum(){
        LinkedNum * tmp;
        while ((tmp = bigNum)){
            bigNum = bigNum->next;
            delete tmp;
        }
        delete bigNum;
    }
};

std::string factorial(int factorial){
    BigPositiveNum res("1");
    while (factorial > 0){
        BigPositiveNum tmp(std::to_string(factorial));
        std::cout << "tmp : " << tmp.toString() << std::endl;
        std::cout << "fc : " << factorial << std::endl;
        res *= tmp;
        std::cout << "res : " << res.toString() << std::endl;
        --factorial;
    }
    // std::string res_str = "";
    // res_str += res.toString();
    // std::cout << "res_str : " << res_str << std::endl;
    return res.toString();
}

int main(void){
    // BigPositiveNum a("120");
    // BigPositiveNum b("04");
    // BigPositiveNum c("000050");
    // std::cout << a.toString() << std::endl;
    // std::cout << b.toString() << std::endl;
    // std::cout << c.toString() << std::endl;
    // c *= b;
    // std::cout << c.toString() << std::endl;
    auto t = factorial(4);
    // std::cout << factorial(1) << std::endl;
    std::cout << "t : " << t << std::endl;
}

