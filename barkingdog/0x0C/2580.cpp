#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[9][9];
vector<pair<int, int>> v;
int cnt;
bool complete = false;

bool verify(pair<int, int> p) // 참고
{
  int square_x = p.first / 3;
  int square_y = p.second / 3;
  for (int i = 0; i < 9; i++)
  {
    if (board[p.first][i] == board[p.first][p.second] && i != p.second)
      return false;
    if (board[i][p.second] == board[p.first][p.second] && i != p.first)
      return false;
  }
  for (int i = 3 * square_x; i < 3 * square_x + 3; i++)
    for (int j = 3 * square_y; j < 3 * square_y + 3; j++)
    {
      if (board[i][j] == board[p.first][p.second])
      {
        if (i != p.first && j != p.second)
          return false;
      }
    }
  return true;
}

void func(int k)
{
  if (k == cnt)
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        cout << board[i][j] << ' ';
      }
      cout << '\n';
    }
    complete = true;
    return;
  }
  for (int i = 1; i <= 9; i++)
  {
    board[v[k].X][v[k].Y] = i;
    if (verify(v[k]))
      func(k + 1);
    if (complete)
      return;
  }
  board[v[k].X][v[k].Y] = 0;
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 0)
      {
        v.push_back({i, j});
        cnt++;
      }
    }
  }
  func(0);
}