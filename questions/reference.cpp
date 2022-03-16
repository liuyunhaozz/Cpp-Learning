#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int a = 1, b = 2;
    cout << typeid(a = b).name();

    int null = 0, *p = (int *)null;

    const int *p = nullptr;  // p 是一个指向整形常量的指针

    constexpr int *q = nullptr; // q 是一个指向整数的常量指针


    int i = 0;
    int *const p1 = &i;
    const int ci = 42;
    int *p = &i;
    int &nn = i;
    const int &mm = i;
    
    const int *p2 = &ci;
    
    const int &r = ci;

    // 合法，当执行对象的拷贝操作时，顶层const不受影响；
    const int j = 3;
    int m = j;
    const int *const p3 = p2;
    int *p = p3;   // wrong
    p2 = p3;
    i = ci;


    p2 = &i;
    p2 = p;
    p2 = nn;
    p2 = mm;


    int &r = ci;
    const int &r2 = i;


    
    // 返回指向函数的指针
    using PF = int(*)(int*, int);
    PF f1(int);
    f1(2);

}