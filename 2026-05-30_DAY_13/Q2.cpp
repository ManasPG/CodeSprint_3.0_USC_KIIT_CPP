#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  getline(cin, s);
  vector<string> words;

  string curr = "";

  for (char c : s)
  {
    if (c == ' ')
    {
      if (!curr.empty())
      {
        words.push_back(curr);
        curr = "";
      }
    }
    else
      curr += c;
  }

  if (!curr.empty())
    words.push_back(curr);

  for (int i = words.size() - 1; i >= 0; i--)
  {
    cout << words[i];
    if (i > 0)
      cout << " ";
  }
  return 0;
}