#include <iostream>
using namespace std;
const int SIZE = 10;
 
class safearay
{
   private:
      int arr[SIZE][SIZE];
   public:
      safearay() 
      {
         register int i;
         register int j;
         for(i = 0; i < SIZE; i++)
         {
            for(j = 0; j < SIZE; j++) {
               arr[i][j] = 1;
            }
           
         }
      }
      int* operator[](int i)
      {
          if( i > SIZE )
          {
              cout << "索引超过最大值" <<endl; 
              // 返回第一个元素
              return arr[0];
          }
          return arr[i];
      }
};
int main()
{
   safearay A;
 
   cout << "A[2] 的值为 : " << A[2][2] <<endl;
   cout << "A[5] 的值为 : " << A[5][3]<<endl;
   cout << "A[12] 的值为 : " << A[12]<<endl;
 
   return 0;
}