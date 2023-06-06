#include <bits/stdc++.h>
using namespace std;
vector<int> dice(7);
int board[22][22];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m, dix, diy, cmd;

bool isBorder(int x, int y)
{
  if (x < 0 || x >= n || y < 0 || y >= m)
    return false;
  return true;
}

void roll(int dir)
{
  if (dir == 1)
    dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
  else if (dir == 2)
    dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
  else if (dir == 3)
    dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
  else if (dir == 4)
    dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> dix >> diy >> cmd;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];

  while (cmd--)
  {
    int command;
    cin >> command;
    if (isBorder(dix + dx[command - 1], diy + dy[command - 1]) == false)
      continue;
    roll(command);

    dix += dx[command - 1];
    diy += dy[command - 1];

    cout << dice[1] << '\n';

    if (board[dix][diy] == 0)
      board[dix][diy] = dice[6];
    else
    {
      dice[6] = board[dix][diy];
      board[dix][diy] = 0;
    }
  }
}