#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<string> store(n);
  for (int i = 0; i < n; i++)
  {
    cin >> store[i];
  }
  string prefix;
  cout << "Search Prefix: ";
  cin >> prefix;
  sort(store.begin(), store.end());
  bool found = false;

  for (string s : store)
  {
    if (s.substr(0, prefix.size()) == prefix)
    {
      cout << s << "\n";
      found = true;
    }
  }
  if (!found)
    cout << -1;
  return 0;
}