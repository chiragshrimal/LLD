#include<bits/stdc++.h>
using namespace std;

class Shape{
private:
    double side;

public:

    Shape(double s){
        side = s;
    }

    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape{

private:
    double side;

public:

    Square(double s) : Shape(s){
        side = s;
    }

    double area() override{
        return side * side;
    }

    double volume() override{
        throw logic_error("Volume not applicable for Square");
    }
};

class Rectangle : public Shape{

private:
    double length;
    double breadth;

public:

    Rectangle(double l, double b) : Shape(0){
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

class Cube : public Shape{

private:
    double side;

public:

    Cube(double s) : Shape(s){
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

    Shape *sqr = new Square(3);
    Shape *rect = new Rectangle(2,3);
    Shape *cub = new Cube(4);

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