#include<iostream>
#include"matrix.h"
using std::endl;
using std::cout;
using std::istream;
using std::ostream;

int main()
{
    double m[4][4] = {{1, 2, 3, 4}, {8, 6, 7, 9}, {4, 10, -4, 12}, {-13, 14, 45, 28}};
    Matrix a;
    Matrix b(a);
    Matrix c(m);
    Matrix d;
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            d[i][j] = m[i][j];
        }
    }


    cout << "a:  " << a << endl;
    cout << "b(a):  " << b << endl;
    cout << "c(m):  " << c << endl;
    cout << "d:  " << d << endl;

    d = a + c;
    cout << "d = a + c:  " << d << endl;

    d = d - a;
    cout << "d = d - a:  " << d << endl;

    d = d * d.inverse();
    cout << "d = d * d.inverse():  " << d << endl;

    d = a ^ 3;
    cout << "d = a ^ 3:  " << d << endl;

    d = c.transpose();
    cout << "d = c.transpose():  " << d << endl << "c  :  " << c;
    
}