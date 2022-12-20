#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  list<char> L;
  string str;
  int cnt;
  cin >> str >> cnt;

  for (auto c : str)
    L.push_back(c);

  auto cur = L.end();
  while (cnt--)
  {
    char tmp;
    cin >> tmp;
    if (tmp == 'P')
    {
      char ch;
      cin >> ch;
      L.insert(cur, ch);
    }

    else if (tmp == 'B')
    {
      if (cur != L.begin())
      {
        --cur;
        cur = L.erase(cur);
      }
    }
    else if (tmp == 'D')
    {
      if (cur != L.end())
        cur++;
    }
    else // L
    {
      if (cur != L.begin())
        cur--;
    }
  }

  for (auto c : L)
  {
    cout << c;
  }
}