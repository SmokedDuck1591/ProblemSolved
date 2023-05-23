#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[52][52];
bool vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;

  while (t--)
  {
    queue<pair<int, int>> Q;
    int r, c, num, ans(0);
    cin >> r >> c >> num;

    while (num--)
    {
      int x, y;
      cin >> x >> y;
      board[x][y] = 1;
    }

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (board[i][j] == 1 && !vis[i][j])
        {
          vis[i][j] = 1;
          Q.push({i, j});
          while (!Q.empty())
          {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
              int nx = cur.X + dx[dir];
              int ny = cur.Y + dy[dir];
              if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
              if (vis[nx][ny] || board[nx][ny] != 1)
                continue;
              vis[nx][ny] = 1;
              Q.push({nx, ny});
            }
          }
          ans++;
        }
      }
    }
    cout << ans << '\n';
    ans = 0;
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        board[i][j] = 0;
        vis[i][j] = 0;
      }
    }
  }
}