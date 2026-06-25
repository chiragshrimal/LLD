#include<bits/stdc++.h>
using namespace std;

class TwoDShape{
private:
    double side;

public:

    TwoDShape(double s){
        side = s;
    }

    virtual double area() = 0;
    virtual double volume() = 0;
};

class ThreeDShape{

    private : 
    double side;

    public:

    ThreeDShape(double s){
        this->side=s;
    }

    virtual double area()=0;

    virtual double volume()=0;


};

class Square : public TwoDShape{

private:
    double side;

public:

    Square(double s) : TwoDShape(s){
        side = s;
    }

    double area() override{
        return side * side;
    }

    double volume() override{
        throw logic_error("Volume not applicable for Square");
    }
};

class Rectangle : public TwoDShape{

private:
    double length;
    double breadth;

public:

    Rectangle(double l, double b) : TwoDShape(0){
        length = l;
        breadth = b;
    }

    double area() override{
        return length * breadth;
    }

    double volume() override{
        throw logic_error("Volume not applicable for Rectangle");
    }
};

class Cube : public ThreeDShape{

private:
    double side;

public:

    Cube(double s) : ThreeDShape(s){
        side = s;
    }

    double area() override{
        return 6 * side * side;
    }

    double volume() override{
        return side * side * side;
    }
};

int main(){

    TwoDShape *sqr = new Square(3);
    TwoDShape *rect = new Rectangle(2,3);
    ThreeDShape *cub = new Cube(4);

    cout << "Square Area : " << sqr->area() << endl;
    cout << "Rectangle Area : " << rect->area() << endl;
    cout << "Cube Area : " << cub->area() << endl;
    cout << "Cube Volume : " << cub->volume() << endl;

    try{
        cout << "Square Volume : " << sqr->volume() << endl;
    }
    catch(logic_error &e){
        cout << "Exception: " << e.what() << endl;
    }

    delete sqr;
    delete rect;
    delete cub;

    return 0;
}