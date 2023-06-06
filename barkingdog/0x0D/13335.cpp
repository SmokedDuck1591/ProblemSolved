#include <bits/stdc++.h>
using namespace std;
int n, w, l, tot, curl, ans;
int bridge[1005];
queue<int> Q;
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> w >> l;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    tot += tmp;
    Q.push(tmp);
  }

  bridge[0] = Q.front();
  Q.pop();
  curl = bridge[0];

  while (tot != bridge[w])
  {
    ans++;
    for (int i = w - 1; i >= 0; --i)
    {
      if (bridge[i] != 0)
      {
        if (i == w - 1)
        {
          bridge[w] += bridge[i];
          curl -= bridge[i];
        }
        else
        {
          bridge[i + 1] = bridge[i];
        }
        bridge[i] = 0;
      }
    }
    if (curl + Q.front() <= l && !Q.empty())
    {
      bridge[0] = Q.front();
      curl += Q.front();
      Q.pop();
    }
  }
  cout << ans + 1;
}