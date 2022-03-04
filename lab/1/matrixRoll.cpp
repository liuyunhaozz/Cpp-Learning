#include<iostream>
#include<cmath>

#define SIZE 15

using namespace std;

int matrix[SIZE][SIZE];
int ans[SIZE][SIZE];

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            ans[j][m-1-i] = matrix[i][j];
    } 
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            cout << ans[i][j] << " ";
        }
        if (i != n - 1)
            cout << ans[i][m-1] << endl;
        else
            cout << ans[i][m-1];
    }
    
    

}