#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> expand(string &str, int left, int right)
{
    int len = str.size();
    while (left >= 0 && right < len && str[left] == str[right]) {
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}

string Substring(string &str) 
{
    int len = str.size();
    if (len < 2) 
        return str;
    int left = 0;
    int right = 0;
    for(int i = 0; i < len; ++i) {
        vector<int> rangeOdd = expand(str, i, i);
        vector<int> rangeEven = expand(str, i, i + 1);
        if (rangeOdd[1] - rangeOdd[0] > right - left) {
            left = rangeOdd[0];
            right = rangeOdd[1];
        } 
        if (rangeEven[1] - rangeEven[0] > right - left) {
            left = rangeEven[0];
            right = rangeEven[1];
        } 
    }
    return str.substr(left, right - left + 1);
}
    


int main()
{
    string str;
    cin >> str;
    string ans = Substring(str);
    int len = ans.size();
    if (len < 2)
        cout << 0;
    else
        cout << len << endl << ans;
    
}
