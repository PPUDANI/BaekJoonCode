#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int N;
   cin >> N;
   
   vector<pair<int, int>> people;
   people.reserve(N);
   for (int i = 0; i < N; i++)
   {
      int x, y;
      cin >> x >> y;
      people.push_back({x, y});
   }
   
   for (int i = 0; i < people.size(); i++)
   {
      int cnt = 1;
      for (int j = 0; j < people.size(); j++)
      {
         if (people[i].first < people[j].first && people[i].second < people[j].second)
         {
            ++cnt;
         }
      }
      
      cout << cnt << " ";
   }
}
