#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[52][52];
bool isused[15];
int n, m, ans(0x7f7f7f7f);

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> v;

void func(int k, int idx)
{
  if (k == m)
  {
    int tmp = 0;
    for (int i = 0; i < house.size(); i++)
    {
      int mnum = 0x7f7f7f7f;
      for (int j = 0; j < v.size(); j++)
      {
        int dist = abs(house[i].X - v[j].X) + abs(house[i].Y - v[j].Y);
        mnum = min(dist, mnum);
      }
      tmp += mnum;
    }
    ans = min(tmp, ans);
    return;
  }
  for (int i = idx; i < chicken.size(); i++)
  {
    if (!isused[i])
    {
      v.push_back(chicken[i]);
      isused[i] = 1;
      func(i, k + 1);
      isused[i] = 0;
      v.pop_back();
    }
  }
}
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 1)
        house.push_back({i, j});
      if (board[i][j] == 2)
        chicken.push_back({i, j});
    }
  }
  func(0, 0);
  cout << ans;
}