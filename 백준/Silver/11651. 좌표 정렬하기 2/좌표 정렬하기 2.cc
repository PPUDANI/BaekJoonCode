#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
   if (a.second == b.second)
   {
      return a.first < b.first;
   }
   else
   {
      return a.second < b.second;
   }
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int N;
   cin >> N;
   
   vector<pair<int, int>> points(N);
   for (int i = 0; i < N; ++i)
   {
      int x, y;
      cin >> x >> y;
      points[i] = {x, y};
   }
   
   sort(points.begin(), points.end(), compare);
   
   for (int i = 0; i < N; ++i)
   {
      cout << points[i].first << " " << points[i].second << "\n";
   }
}
