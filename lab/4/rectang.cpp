#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Rectangle {
    private:
        double length = 0.0;
        double width = 0.0;
    public:
        void setWidth(double wid) { width = wid; }
        double getWidth() { return width; }
        void setLength(double len) { length = len; }
        double getLength() { return length; }
        void setRange();
        double perimeter() { return 2 * (width + length); }
        double area() { return width * length; }
};

void Rectangle::setRange() {
    if (length < 0.0 || length > 20.0) {
        cout << "length is not in 0.0 - 20.0" << endl;
    }
    if (width < 0.0 || width > 20.0) {
        cout << "width is not in 0.0 - 20.0" << endl;
    }
    if (length >= 0.0 && length <= 20.0 && width >= 0.0 && width <= 20.0) {
        cout << "length and width are both in 0.0 - 20.0" << endl;
    }
}

int main()
{
    Rectangle rec;
    double len, wid;
    cin >> len >> wid;
    rec.setLength(len);
    rec.setWidth(wid);
    printf("Length: %d    Width: %d\n", (int)rec.getLength(), (int)rec.getWidth());
    rec.setRange();
    cout << "Perimeter: " << rec.perimeter() << endl;
    cout << "Area: " << rec.area();

}



