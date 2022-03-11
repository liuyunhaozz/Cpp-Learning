#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Rectangle {
    private:
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
    public:
        void read();
        int process(Rectangle &);
        
};

void Rectangle::read() {
    cin >> x1 >> y1 >> x2 >> y2;
}

int Rectangle::process(Rectangle &rec) {
    int max_ax = max(x1, x2);
    int max_bx = max(rec.x1, rec.x2);
    int min_ax = min(x1, x2);
    int min_bx = min(rec.x1, rec.x2);
    int delta_x = min(max_ax, max_bx) - max(min_ax, min_bx);
    if (delta_x < 0)
        delta_x = 0;
    int max_ay = max(y1, y2);
    int max_by = max(rec.y1, rec.y2);
    int min_ay = min(y1, y2);
    int min_by = min(rec.y1, rec.y2);
    int delta_y = min(max_ay, max_by) - max(min_ay, min_by);
    if (delta_y < 0)
        delta_y = 0;
    return delta_x * delta_y;
}

int main()
{
    Rectangle a, b;
    a.read();
    b.read();
    cout << a.process(b);
}