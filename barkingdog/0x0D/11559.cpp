#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[14];
bool isused[14][14];
int ans;

void search()
{
  bool isfire = false;
  for (int i = 0; i < 12; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (board[i][j] != '.' && !isused[i][j])
      {
        queue<pair<int, int>> Q;
        vector<pair<int, int>> V;
        Q.push({i, j});
        int tmp = 1;
        char origin = board[i][j];
        isused[i][j] = 1;
        while (!Q.empty())
        {
          auto cur = Q.front();
          V.push_back(cur);
          Q.pop();
          for (int dir = 0; dir < 4; dir++)
          {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
              continue;
            if (board[nx][ny] != origin || isused[nx][ny])
              continue;
            tmp++;
            isused[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
        if (tmp >= 4)
        {
          isfire = true;
          for (int i = 0; i < V.size(); i++)
            board[V[i].X][V[i].Y] = '.';
        }
      }
    }
  }
  if (isfire)
    ans++;
  for (int i = 0; i < 12; i++)
    for (int j = 0; j < 6; j++)
      isused[i][j] = 0;
}
bool gravity()
{
  bool isflag = false;
  for (int i = 10; i >= 0; i--) // gravity
  {
    for (int j = 0; j < 6; j++)
    {
      if (board[i][j] != '.' && board[i + 1][j] == '.')
      {
        isflag = true;
        for (int k = i + 1; k < 12; k++)
        {
          if (board[k][j] != '.')
          {
            board[k - 1][j] = board[i][j];
            board[i][j] = '.';
            break;
          }
          if (k == 11 && board[k][j] == '.')
          {
            board[k][j] = board[i][j];
            board[i][j] = '.';
          }
        }
      }
    }
  }
  return isflag;
}
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  for (int i = 0; i < 12; i++)
    cin >> board[i];
  bool con = true;
  while (con)
  {
    search();
    con = gravity();
  }

  cout << ans;
}