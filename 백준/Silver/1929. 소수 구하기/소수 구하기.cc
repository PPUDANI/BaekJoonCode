#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int N, M;
   cin >> N >> M;
   
   vector<bool> vec(M + 1, true);

   for (int i = 2; i <= sqrt(M); ++i)
   {
      if (vec[i] == true)
      {
         for (int j = i * i; j <= M; j += i)
         {
            vec[j] = false;
         }
      }
   }
   
   if (N < 2)
   {
      N = 2;
   }
   
   for (int i = N; i <= M; ++i)
   {
      if (vec[i] == true)
      {
         cout << i << "\n";
      }
   }
}