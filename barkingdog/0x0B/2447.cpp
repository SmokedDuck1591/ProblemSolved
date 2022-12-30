#include <bits/stdc++.h>
using namespace std;
int cnt;
char paper[7000][7000];
void star(int r, int c, int n)
{
  if (n == 1)
    return;
  for (int i = r; i < r + n; i++)
  {
    for (int j = c; j < c + n; j++)
    {
      if ((i >= r + n / 3 && i < r + n / 3 * 2) && (j >= c + n / 3 && j < c + n / 3 * 2))
        paper[i][j] = ' ';
    }
  }
  for (int i = r; i < r + n; i += n / 3)
  {
    for (int j = c; j < c + n; j += n / 3)
    {
      star(i, j, n / 3);
    }
  }
}
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> cnt;

  for (int i = 0; i < cnt; i++)
    for (int j = 0; j < cnt; j++)
      paper[i][j] = '*';
  star(0, 0, cnt);
  for (int i = 0; i < cnt; i++)
  {
    for (int j = 0; j < cnt; j++)
    {
      cout << paper[i][j];
    }
    cout << '\n';
  }
}