#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[302][302];
int dist[302][302];
int dx[8] = {1, 2, 2, 1, -2, -1, -1, -2};
int dy[8] = {2, 1, -1, -2, 1, 2, -2, -1};

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;

  while (t--)
  {
    int n, x, y, ax, ay, ans(0);
    cin >> n >> x >> y >> ax >> ay;

    queue<pair<int, int>> Q;
    Q.push({x, y});
    dist[x][y] = 1;

    while (!Q.empty())
    {
      auto cur = Q.front();
      Q.pop();
      for (int dir = 0; dir < 8; dir++)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
          continue;
        if (board[nx][ny] != 0 || dist[nx][ny] != 0)
          continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        if (nx == ax && ny == ay)
          break;
        Q.push({nx, ny});
      }
    }
    cout << dist[ax][ay] - 1 << '\n';

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        dist[i][j] = 0;
        board[i][j] = 0;
      }
    }
  }
}