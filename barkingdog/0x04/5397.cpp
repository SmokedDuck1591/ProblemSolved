#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  while (n--)
  {
    string cmd;
    list<char> L;
    cin >> cmd;
    auto cur = L.begin();

    for (auto c : cmd)
    {
      if (c == '<')
      {
        if (cur != L.begin())
          cur--;
      }
      else if (c == '>')
      {
        if (cur != L.end())
          cur++;
      }
      else if (c == '-')
      {
        if (cur != L.begin())
        {
          cur--;
          cur = L.erase(cur);
        }
      }
      else
      {
        // insert를 할 시 포인터가 자동으로 뒤로 넘어감
        L.insert(cur, c);
      }
    }
    for (auto ch : L)
      cout << ch;
    cout << '\n';
  }
}