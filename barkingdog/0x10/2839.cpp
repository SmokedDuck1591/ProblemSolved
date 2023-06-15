#include <bits/stdc++.h>
using namespace std;
int d[5002];
int n;
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  d[3] = 1;
  d[5] = 1;

  for (int i = 6; i <= n; i++)
  {
    if (d[i - 5] == 0)
    {
      if (d[i - 3] == 0)
        continue;
      else
        d[i] = d[i - 3] + 1;
    }
    else
      d[i] = d[i - 5] + 1;
  }
  if (n == 3 || n == 5)
  {
    cout << 1;
    return 0;
  }
  if (d[n] <= 1)
    cout << -1;
  else
    cout << d[n];
}