#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    string tmp;
    tmp = to_string(i);

    int clapcount = 0;
    for (int j = 0; j < tmp.length(); j++)
    {
      if (tmp[j] != '0' && tmp[j] % 3 == 0)
        clapcount++;
    }
    if (clapcount != 0)
    {
      for (int k = 0; k < clapcount; k++)
        cout << '-';
    }
    else
      cout << tmp;
    cout << ' ';
  }
}