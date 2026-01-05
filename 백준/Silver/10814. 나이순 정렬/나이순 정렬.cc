#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, pair<int, string>>& a, const pair<int, pair<int, string>>& b)
{
   if (a.second.first == b.second.first)
   {
      return a.first < b.first;
   }
   else
   {
      return a.second.first < b.second.first;
   }
}

int main()
{
   int N;
   cin >> N;
   
   vector<pair<int, pair<int, string>>> User(N);
   for (int i = 0; i < N; ++i)
   {
      int age;
      string name;
      cin >> age >> name;
      User[i].first = i;
      User[i].second.first = age;
      User[i].second.second = name;
   }
   
   sort(User.begin(), User.end(), compare);
   
   for (int i = 0; i < User.size(); ++i)
   {
      cout << User[i].second.first << " " << User[i].second.second << endl;
   }
}