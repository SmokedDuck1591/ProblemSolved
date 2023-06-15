#include <bits/stdc++.h>
using namespace std;
int l, r, c;
char board[32][32][32];
int dist[32][32][32];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);

  while (1)
  {
    cin >> l >> r >> c;
    if (l == 0 && r == 0 || c == 0)
      return 0;

    queue<tuple<int, int, int>> Q;
    bool esc = false;
    for (int i = 0; i < l; i++)
      for (int j = 0; j < r; j++)
        for (int k = 0; k < c; k++)
        {
          cin >> board[i][j][k];
          if (board[i][j][k] == 'S')
          {
            Q.push({i, j, k});
            dist[i][j][k] = 1;
          }
        }

    while (!Q.empty())
    {
      int qx = get<1>(Q.front());
      int qy = get<2>(Q.front());
      int qz = get<0>(Q.front());
      Q.pop();
      for (int dir = 0; dir < 6; dir++)
      {
        int nx = qx + dx[dir];
        int ny = qy + dy[dir];
        int nz = qz + dz[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)
          continue;
        if (dist[nz][nx][ny] > 0 || board[nz][nx][ny] == '#')
          continue;
        if (board[nz][nx][ny] == 'E')
        {
          esc = true;
          cout << "Escaped in " << dist[qz][qx][qy] << " minute(s).\n";
          break;
        }
        dist[nz][nx][ny] = dist[qz][qx][qy] + 1;
        Q.push({nz, nx, ny});
      }
      if (esc == true)
        break;
    }
    if (!esc)
      cout << "Trapped!\n";

    for (int i = 0; i < l; i++)
      for (int j = 0; j < r; j++)
        for (int k = 0; k < c; k++)
          dist[i][j][k] = 0;
  }
}