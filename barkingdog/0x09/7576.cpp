#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int box[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, ans(0);
  queue<pair<int, int>> Q;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> box[i][j];
      if (box[i][j] == 1)
      {
        Q.push({i, j});
        dist[i][j] = 1;
      }
      else if (box[i][j] == -1)
        dist[i][j] = -1;
    }
  }

  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n)
        continue;
      if (box[nx][ny] == -1 || dist[nx][ny] != 0)
        continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (dist[i][j] > ans)
        ans = dist[i][j];
      else if (dist[i][j] == 0)
      {
        cout << -1;
        return 0;
      }
    }
  }

  if (ans == 1)
    cout << 0;
  else
    cout << ans - 1;
}