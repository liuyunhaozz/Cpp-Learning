#include<algorithm>
#include<iostream>
#include<string>

using namespace std;


bool cmp(char x, char y)
{
    return x > y;
}

int main()
{
    string x = "abcde";
    sort(x.begin(), x.end(), cmp);
    cout << x;
}
