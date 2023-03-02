#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k, ch;
queue<pair<int, int>> Q;
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> m >> n >> k;
  vector<int> v;

  for (int i = 0; i < k; i++)
  {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    for (int i = sy; i < ey; i++)
      for (int j = sx; j < ex; j++)
        board[i][j] = 1;
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == 0 && vis[i][j] == 0)
      {
        Q.push({i, j});
        vis[i][j] = 1;
        int num = 1;
        ch++;
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
            if (vis[nx][ny] == 1 || board[nx][ny] == 1)
              continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            num++;
          }
        }
        v.push_back(num);
      }
    }
  }
  sort(v.begin(), v.end());
  cout << ch << '\n';
  for (auto c : v)
    cout << c << ' ';
}