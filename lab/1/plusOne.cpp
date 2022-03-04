#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void PlusOne(string &str)
{
    string tmp;
    int len = str.size();
    int num = 0;
    for (int i = len - 1; i >= 0; --i) {
        if(str[i] == '9') {
            str[i] = '0';
            ++num;
        }
        else break;            
    }
    if (num == len)
        str = '1' + str;
    else 
        str[len-1-num] += 1;
    
}

int main()
{
    string str;
    cin >> str;
    PlusOne(str);
    cout << str;
}