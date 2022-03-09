#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

class Caculater {
    private:
        int data1 = 0;
        int data2 = 0;
        string op;
    public:
        Caculater(int data1, int data2, string op);
        void caculate();
};


Caculater::Caculater(int data1, int data2, string op) {
    this->data1 = data1;
    this->data2 = data2;
    this->op = op;
}

void Caculater::caculate() {
    if (this->op == "+") {
        cout << this->data1 + this->data2;
    }
    else if (op == "-") {
        cout << this->data1 - this->data2;
    }
    else if (op == "*") {
        cout << this->data1 * this->data2;
    }
    else if (op == "/") {
        if (this->data1 % this->data2 == 0) 
            cout << this->data1 / this->data2;
        else
            cout << setiosflags(ios::fixed) << setprecision(2) << ((double)this->data1) / this->data2;
    }

}


int main()
{
    int n1, n2;
    string op;
    cin >> n1 >> n2 >> op;
    Caculater test(n1, n2, op);
    test.caculate();
}