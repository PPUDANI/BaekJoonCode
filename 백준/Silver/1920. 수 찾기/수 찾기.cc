#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int N, M;
   cin >> N;
   
   vector<int> Nums(N);
   for (int i = 0; i < N; ++i)
   {
      cin >> Nums[i];
   }
   
   cin >> M;
   sort(Nums.begin(), Nums.end());
   
   for (int i = 0; i < M; ++i)
   {
      int Num;
      cin >> Num;
      int Start = 0;
      int End = N - 1;
      
      bool IsFind = false;
      while(Start <= End)
      {
         int Mid = Start + ( End - Start) / 2;
         if (Nums[Mid] < Num)
         {
            Start = Mid + 1;
         }
         else if (Nums[Mid] > Num)
         {
            End = Mid - 1;
         }
         else
         {
            IsFind = true;
            break;
         }
      }
      
      if (IsFind)
      {
         cout << "1\n";
      }
      else
      {
         cout << "0\n";
      }
   }
}