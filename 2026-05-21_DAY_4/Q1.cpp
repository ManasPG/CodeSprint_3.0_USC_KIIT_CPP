#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  getline(cin, s);
  int v = 0, co = 0, w = 0;
  bool inword = false;

  for (char c : s)
  {
    if (isalnum(c))
    {
      if (isalpha(c))
      {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
          v++;
        }
        else
        {
          co++;
        }
      }

      if (!inword)
      {
        w++;
        inword = true;
      }
    }
    else
      inword = false;
  }

  cout << "Total Vowels: " << v;
  cout << "\nTotal Consonants: " << co;
  cout << "\nTotal Words: " << w;

  return 0;
}