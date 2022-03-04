#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int root = sqrt(n);
    int flag = 0; // 第一个数前面没空格
    for(int i = 2; i <= root; i++) {
       if(n % i == 0) {
           while(n % i == 0) {
                n /= i;
                if (flag == 0) {
                    cout << i;
                    flag = 1;
                }
                else
                    cout << " " << i;
           }
       }
    }

    if (n != 1) {
        if (flag == 0)
            cout << n;
        else
            cout << " " << n;
   }
   return 0;
}