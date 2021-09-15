# include <iostream>
using namespace std;

class Base{
    virtual void method(){
        cout << "From Base" << endl;
    }
public:
    virtual ~Base() { 
        method();
    }
    void baseMethod(){ 
        method();
    }
};

class A : public Base {
    void method(){
        cout << "from A" <<endl;
    } 
public: 
    ~A(){
        method();
    } 
};

int main(){ 
    Base * base = new A();
    /**
     * 先調用 baseMethod(), 接著調用被 Override 的 method()
     * 印出 "from A"
     */
    base->baseMethod();

    /** 
     * 先解構 A，調用被 Override 的 method()
     * 印出 "from A"，之後 A 的 method() 被清掉
     * 最後解構父類，調用 Base 的 method
     * 印出 "from Base"
     */
    delete base;
    return 0;
}

/**
 * 前者是函式指標，接受兩整數作為參數，並回傳整數
 * 後者是一般函式，接受兩整數作為參數，並回傳整數指標
*/
int * addition(int a, int b){
    return new int(a + b);
}
int (* get_addition_value) (int a, int b){
    
}