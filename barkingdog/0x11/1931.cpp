#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> p[100002];

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> p[i].second >> p[i].first;
  sort(p, p + n);

  int time = 0;
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (time > p[i].second)
    {
        }
    time = p[i].first;
  }
}