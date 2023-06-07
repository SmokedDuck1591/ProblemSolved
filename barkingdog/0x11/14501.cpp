#include <bits/stdc++.h>
using namespace std;
int t[17];
int p[17];
int d[17];

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> t[i] >> p[i];

  for (int i = n; i > 0; --i)
  {
    if (i + t[i] > n + 1)
    {
      d[i] = d[i + 1];
      continue;
    }
    if (t[i] == 1)
    {
      d[i] += d[i + 1] + p[i];
      continue;
    }
    if (p[i] >= d[i + 1])
      d[i] += d[i + t[i]] + p[i];
    else
      d[i] = d[i + 1];
  }

  cout << d[1];
}