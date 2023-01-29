#include <bits/stdc++.h>
using namespace std;
int board[22][22];
int n, ans;

void board_cpy(int desc[22][22], int src[22][22])
{
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < n; ++c)
      desc[r][c] = src[r][c];
}

void move(int dir)
{
  if (dir == 0)
  {
    vector<pair<int, int>> v;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] != 0)
        {
          bool is_first = true;
          bool is_sum = true;
          for (int x = i - 1; x >= 0; x--)
          {
            if (board[x][j] != 0)
            {
              is_first = false;
              for (int i = 0; i < v.size(); i++)
              {
                if (v[i].first == x && v[i].second == j)
                  is_sum = false;
              }
              if (board[x][j] == board[i][j] && is_sum) // 만약 수가 같을 경우 합치기
              {
                board[x][j] += board[i][j];
                board[i][j] = 0;
                v.push_back({x, j});
              }
              else // 만약 수가 같지 않을 경우
              {
                if (x + 1 != i)
                {
                  board[x + 1][j] = board[i][j];
                  board[i][j] = 0;
                }
              }
              break;
            }
          }
          if (is_first) // 만약 해당 file의 첫번째 수일 경우 무조건 x = 0 으로 이동
          {
            board[0][j] = board[i][j];
            board[i][j] = 0;
          }
        }
      }
    }
  }
  else if (dir == 1)
  {
    vector<pair<int, int>> v;
    for (int i = n - 2; i >= 0; i--)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] != 0)
        {
          bool is_first = true;
          bool is_sum = true;
          for (int x = i + 1; x < n; x++)
          {
            if (board[x][j] != 0)
            {
              is_first = false;
              for (int i = 0; i < v.size(); i++)
              {
                if (v[i].first == x && v[i].second == j)
                  is_sum = false;
              }
              if (board[x][j] == board[i][j] && is_sum) // 만약 수가 같을 경우 합치기
              {
                board[x][j] += board[i][j];
                board[i][j] = 0;
                v.push_back({x, j});
              }
              else // 만약 수가 같지 않을 경우
              {
                if (x - 1 != i)
                {
                  board[x - 1][j] = board[i][j];
                  board[i][j] = 0;
                }
              }
              break;
            }
          }
          if (is_first) // 만약 해당 file의 첫번째 수일 경우 무조건 x = n - 1 으로 이동
          {
            board[n - 1][j] = board[i][j];
            board[i][j] = 0;
          }
        }
      }
    }
  }
  else if (dir == 2)
  {
    vector<pair<int, int>> v;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[j][i] != 0)
        {
          bool is_first = true;
          bool is_sum = true;
          for (int x = i - 1; x >= 0; x--)
          {
            if (board[j][x] != 0)
            {
              is_first = false;
              for (int i = 0; i < v.size(); i++)
              {
                if (v[i].first == j && v[i].second == x)
                  is_sum = false;
              }
              if (board[j][x] == board[j][i] && is_sum) // 만약 수가 같을 경우 합치기
              {
                board[j][x] += board[j][i];
                board[j][i] = 0;
                v.push_back({j, x});
              }
              else // 만약 수가 같지 않을 경우
              {
                if (x + 1 != i)
                {
                  board[j][x + 1] = board[j][i];
                  board[j][i] = 0;
                }
              }
              break;
            }
          }
          if (is_first) // 만약 해당 file의 첫번째 수일 경우 무조건 x = 0 으로 이동
          {
            board[j][0] = board[j][i];
            board[j][i] = 0;
          }
        }
      }
    }
  }
  else if (dir == 3)
  {
    vector<pair<int, int>> v;
    for (int i = n - 2; i >= 0; i--)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[j][i] != 0)
        {
          bool is_first = true;
          bool is_sum = true;
          for (int x = i + 1; x < n; x++)
          {
            if (board[j][x] != 0)
            {
              is_first = false;
              for (int i = 0; i < v.size(); i++)
              {
                if (v[i].first == j && v[i].second == x)
                  is_sum = false;
              }
              if (board[j][x] == board[j][i] && is_sum) // 만약 수가 같을 경우 합치기
              {
                board[j][x] += board[j][i];
                board[j][i] = 0;
                v.push_back({j, x});
              }
              else // 만약 수가 같지 않을 경우
              {
                if (x - 1 != i)
                {
                  board[j][x - 1] = board[j][i];
                  board[j][i] = 0;
                }
              }
              break;
            }
          }
          if (is_first) // 만약 해당 file의 첫번째 수일 경우 무조건 x = n -1 으로 이동
          {
            board[j][n - 1] = board[j][i];
            board[j][i] = 0;
          }
        }
      }
    }
  }
}
void func(int k)
{
  if (k == 10)
  {
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (tmp < board[i][j])
          tmp = board[i][j];
      }
    }
    if (ans < tmp)
      ans = tmp;
    return;
  }
  int copy_board[22][22];
  for (int i = 0; i < 4; i++)
  {
    board_cpy(copy_board, board);
    move(i);
    func(k + 1);
    board_cpy(board, copy_board);
  }
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }
  func(0);
  cout << ans;
}