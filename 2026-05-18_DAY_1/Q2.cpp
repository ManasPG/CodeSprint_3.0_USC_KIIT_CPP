#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  unordered_set<int> track(n);

  for (int i = 0; i < n; i++)
  {
    int el;
    cin >> el;
    if (track.find(el) != track.end())
    {
      cout << "Yes";
      return 0;
    }
    track.insert(el);
  }
  cout << "No";
  return 0;
}