#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[27];
bool vis[27][27];
vector<int> v;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n, cnt(0);
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> board[i];

  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!vis[i][j] && board[i][j] == '1')
      {
        Q.push({i, j});
        vis[i][j] = 1;
        int width = 1;
        cnt++;
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
            if (vis[nx][ny] || board[nx][ny] != '1')
              continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            width++;
          }
        }
        v.push_back(width);
      }
    }
  }
  sort(v.begin(), v.end());
  cout << cnt << '\n';
  for (auto c : v)
    cout << c << '\n';
}