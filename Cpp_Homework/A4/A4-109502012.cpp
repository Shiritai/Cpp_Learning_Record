#include <iostream>

using namespace std;

class Square{
public:
    friend class Area;
    friend class Circle;
    Square(){}
    Square(int side){
        area = side * side;
    }
    float getArea(void){ return area;}
private:
    float area;
};

class Circle{
public:
    friend class Area;
    Circle(){}
    Circle(int radius){
        area = radius * radius * pi;
    }
    float getArea(void){ return area;}

    static float circleArea(int rad){ return rad * rad * pi;}
    void compareArea(Square sq){
        cout << (this->area > sq.area ? "Circle" : "Square") << " one is the biggest\n";
    }
private:
    static const  int pi = 3;
    float area;
};

class Area{ 
public:
    static void compare(Circle c, Square sq){
        // cout << (c.getArea() > sq.getArea() ? "Circle" : "Square") << " one is the biggest\n";
        cout << (c.area > sq.area ? "Circle" : "Square") << " one is the biggest\n";
    }
};

int main(){
    int r;
    cin >> r;
    cout << "Circle Area:" << Circle::circleArea(r) << endl;

    //new�@�ӥb�|��10��Circle Class
    Circle r1(10);
    //new�@�ӥb�|��3��Circle Class
    Circle r2(3);
    //new�@�������3��Square Class
    Square s1(3);
    //new�@�������10��Square Class
    Square s2(10);
    //r1�Ms1������n
    r1.compareArea(s1);
    //r2�Ms2������n
    Area::compare(r2,s2);
    return 0;
}
