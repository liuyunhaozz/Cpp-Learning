#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

class Tempeature {
    private: 
        int c = 0;
        double f = 0.0;
    public:
        Tempeature(int, double);
        void getC();
        void getF();
        void transfrom();
};

Tempeature::Tempeature(int c, double f = 0.0) {
    this->c = c;
    this->f = f;
}

void Tempeature::transfrom() {
    this->f = ((double)this->c) * 9 / 5 + 32;
}

void Tempeature::getC() {
    cout << this->c;
}

void Tempeature::getF() {
    cout << setiosflags(ios::fixed) << setprecision(1) << (this->f);
}

int main()
{
    int c;
    cin >> c;
    Tempeature test(c);
    test.transfrom();
    test.getF();

}