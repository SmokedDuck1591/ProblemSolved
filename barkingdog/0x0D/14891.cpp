#include <bits/stdc++.h>
using namespace std;
vector<deque<char>> d(5);
int dirr[2] = {-1, 1};
void rotate(int c, int k)
{
  if (k == 1) // 시계방향
  {
    char tmp = d[c].back();
    d[c].pop_back();
    d[c].push_front(tmp);
  }
  if (k == -1) // 반시계방향
  {
    char tmp = d[c].front();
    d[c].pop_front();
    d[c].push_back(tmp);
  }
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);

  for (int i = 1; i <= 4; i++)
  {
    string init;
    cin >> init;
    for (int j = 0; j < 8; j++)
      d[i].push_back(init[j]);
  }
  int cmd;
  cin >> cmd;

  while (--cmd)
  {
    int num, dir;
    cin >> num >> dir;

    bool check[4] = {0};
    queue<int> Q;
    Q.push(num);
    check[num - 1] = 1;
    while (!Q.empty())
    {
      int cur = Q.front();
      Q.pop();
      for (int i = 0; i < 2; i++)
      {
        int nx = cur + dirr[i];
        if (nx >= 5 || nx < 1)
          continue;
        if (check[nx - 1])
          continue;
        rotate(cur, dir);
        if (cur > nx)
        {
          if (d[cur][6] == d[nx][2])
          {
            if (dir == 1)
            {
            }
            else
            {
            }
          }
        }
        Q.push(nx);
      }
    }
  }
}
