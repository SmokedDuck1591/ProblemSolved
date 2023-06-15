#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[105][105];
bool vis[105][105];
bool depth[101];

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  int maxd = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int tmp;
      cin >> tmp;
      board[i][j] = tmp;
      if (!depth[tmp])
      {
        maxd = max(tmp, maxd);
        depth[tmp] = true;
      }
    }
  }

  for (int num = 0; num <= maxd; num++)
  {
    queue<pair<int, int>> Q;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (num < board[i][j] && !vis[i][j])
        {
          tmp++;
          Q.push({i, j});
          vis[i][j] = 1;
          while (!Q.empty())
          {
            auto cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
              int nx = cur.X + dx[dir];
              int ny = cur.Y + dy[dir];
              if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
              if (vis[nx][ny] || board[nx][ny] <= num)
                continue;
              vis[nx][ny] = 1;
              Q.push({nx, ny});
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        vis[i][j] = 0;
    ans = max(tmp, ans);
  }

  cout << ans;
}