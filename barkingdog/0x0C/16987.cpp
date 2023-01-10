#include <bits/stdc++.h>
using namespace std;
#define S first
#define W second

int n, ans, cnt;
vector<pair<int, int>> v;

void func(int cur)
{
  if (cur == n)
  {
    ans = max(cnt, ans);
    return;
  }
  if (v[cur].S <= 0 || cnt == n - 1)
  {
    func(cur + 1);
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (cur == i or v[i].W <= 0)
      continue;
    v[cur].S -= v[i].W;
    v[i].S -= v[cur].W;
    if (v[cur].S <= 0)
      cnt++;
    if (v[i].S <= 0)
      cnt++;
    func(cur + 1);
    if (v[cur].S <= 0)
      cnt--;
    if (v[i].S <= 0)
      cnt--;
    v[cur].S += v[i].W;
    v[i].S += v[cur].W;
  }
}
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int s, w;
    cin >> s >> w;
    v.push_back({s, w});
  }
  func(0);
  cout << ans;
}