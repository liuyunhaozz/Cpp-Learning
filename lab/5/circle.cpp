#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#define PI 3.14

using namespace std;


class Circle {
    protected:
        double radius = 0;
    public:
        void readRadius();
        void getCicleArea();
};

class Cylinder : public Circle {
    protected:
        double height = 0;
    public:
        void readHeight();
        void getSurArea();
        void getVol();
};

void Circle::readRadius() {
    cout << "Please enter the radius of the circle:";
    cin >> radius;
}

void Circle::getCicleArea() {
    cout << "The area of the circle is:";
    cout << PI * radius * radius << endl;
}

void Cylinder::readHeight() {
    cout << "Please enter the height of the cylinder:";
    cin >> height;
}

void Cylinder::getSurArea() {
    cout << "The area of the cylinder is:";
    cout << 2 * PI * radius * height + 2 * PI * radius * radius << endl;
}

void Cylinder::getVol() {
    cout << "The volumn of the cylinder is:";
    cout << PI * radius * radius * height << endl;
}


int main()
{
    Cylinder cyl;
    cyl.readRadius();
    cyl.readHeight();
    cyl.getCicleArea();
    cyl.getSurArea();
    cyl.getVol();
}
