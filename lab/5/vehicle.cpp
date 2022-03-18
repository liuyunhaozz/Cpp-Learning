#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>


using namespace std;

class Vehicle {
    protected:
        int speed;
        int wheel;
        int weight;
    public:
        Vehicle(int spd, int whl, int wet) : speed(spd), wheel(whl), weight(wet) {}
        // 如果不声明成纯虚函数，则必须给出虚函数的定义
        virtual void print() = 0;
};

class Car : public Vehicle {
    protected:
        int guest;
    public:
        Car(int spd, int whl, int wet, int gst) : Vehicle(spd, whl, wet), guest(gst) {}
        virtual void print();
};

class Truck : public Vehicle {
    protected:
        int load;
    public:
        Truck(int spd, int whl, int wet, int lod) : Vehicle(spd, whl, wet), load(lod) {}
        virtual void print();
};

class Boat : public Vehicle {
    protected:
        char type;
    public:
        Boat(int spd, int whl, int wet, char typ) : Vehicle(spd, whl, wet), type(typ) {}
        virtual void print();
};

void Car::print() {
    cout << "car message" << endl;
    cout << speed << " " << wheel << " " << weight << " " << guest << endl;
}

void Truck::print() {
    cout << "truck message" << endl;
    cout << speed << " " << wheel << " " << weight << " " << load << endl;
}

void Boat::print() {
    cout << "boat message" << endl;
    cout << speed << " " << wheel << " " << weight << " " << type << endl;
}

int main()
{
    // Also Right
    // Vehicle *p = new Car(80, 4, 1000, 4);
    // p->print();
    Vehicle *p;
    Car car(80, 4, 1000, 4);
    Truck truck(80, 4, 2500, 3000);
    Boat boat(30, 0, 12000, 'k');
    p = &car;
    p->print();
    p = &truck;
    p->print();
    p = &boat;
    p->print();
}