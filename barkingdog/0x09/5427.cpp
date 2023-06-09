#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1005];
int human[1005][1005];
int fire[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  while (n--)
  {
    int w, h;
    bool exit = false;
    cin >> w >> h;
    queue<pair<int, int>> Q1; // 불 전용
    queue<pair<int, int>> Q2; // 사람 전용
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        char tmp;
        cin >> tmp;
        if (tmp == '@')
          Q2.push({i, j});
        if (tmp == '*')
          Q1.push({i, j});
        board[i][j] = tmp;
      }
    }
    while (!Q1.empty())
    {
      auto cur = Q1.front();
      Q1.pop();
      for (int dir = 0; dir < 4; dir++)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
          continue;
        if (fire[nx][ny] > 0 || board[nx][ny] == '#')
          continue;
        fire[nx][ny] = fire[cur.X][cur.Y] + 1;
        Q1.push({nx, ny});
      }
    }
    while (!Q2.empty())
    {
      auto cur = Q2.front();
      Q2.pop();
      for (int dir = 0; dir < 4; dir++)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
        {
          cout << human[cur.X][cur.Y] + 1 << '\n';
          exit = true;
          break;
        }
        if (board[nx][ny] == '#' || board[nx][ny] == '*')
          continue;
        if (human[nx][ny] > 0 || fire[nx][ny] <= human[cur.X][cur.Y] + 1)
          continue;
        human[nx][ny] = human[cur.X][cur.Y] + 1;
        Q2.push({nx, ny});
      }
    }
    if (!exit)
      cout << "IMPOSSIBLE" << '\n';

    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        fire[i][j] = 0;
        human[i][j] = 0;
        board[i][j] = 0;
      }
    }
  }
}
