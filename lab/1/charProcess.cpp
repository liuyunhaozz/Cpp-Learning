#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int isCharOrNum(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

char lower2upper(char c)
{
    if (c >= '0' && c <= '9')
        return c;
    else if (c >= 'a' && c <= 'z')
        return c - 32;
    else
        return c + 32;
}

bool cmp(char x, char y)
{
    return x > y;
}

string unique(string &str)
{
    string tmp;
    string ans;
    int size = str.size();
    for (int i = 0; i < size; i++) {
        if (tmp.find(str[i]) == tmp.npos && isCharOrNum(str[i])) {
            ans += lower2upper(str[i]);
        }
        tmp += str[i];
    }
    sort(ans.begin(), ans.end(), cmp);
    return ans;
}




int main()
{
    int n;
    string A;
    cin >> n >> A;
    string ans = unique(A);
    for (int i = 0; i < n; i++)
        cout << ans;
    return 0;
}