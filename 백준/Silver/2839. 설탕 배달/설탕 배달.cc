#include <iostream>
#include <vector>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int N;
   cin >> N;

   int Count = N / 5;
   int Remain;
   while (Count >= 0)
   {
      Remain = N - (Count * 5);
      if (Remain % 3 == 0)
      {
         Count += Remain / 3;
         break;
      }
      Count--;
   }
   
   cout << Count;
}