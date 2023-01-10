#include <bits/stdc++.h>
using namespace std;

string board[22];
bool alpha[27];
int n, m, ans;

void search(int x, int y, int cur)
{
  if (x < 0 || y < 0 || x >= n || y >= m)
    return;
  if (alpha[board[x][y] - 65] == 1)
    return;
  alpha[board[x][y] - 65] = 1;
  if (cur > ans)
  {
    ans = cur;
  }
  search(x + 1, y, cur + 1);
  search(x, y + 1, cur + 1);
  search(x - 1, y, cur + 1);
  search(x, y - 1, cur + 1);
  alpha[board[x][y] - 65] = 0;
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> board[i];
  search(0, 0, 1);
  cout << ans;
  ans = 0;
}