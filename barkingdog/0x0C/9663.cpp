#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, ans;
bool board[16][16];
vector<pair<int, int>> v;
void func(int k)
{
  if (k == n)
  {
    ans++;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    bool flag = true;
    for (int j = 0; j < v.size(); j++)
    {
      if (v[j].Y == i || v[j].X - v[j].Y == k - i || v[j].X + v[j].Y == k + i)
        flag = false;
    }
    if (flag)
    {
      v.push_back({k, i});
      func(k + 1);
      v.pop_back();
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  func(0);
  cout << ans;
}