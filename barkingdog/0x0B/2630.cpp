#include <bits/stdc++.h>
using namespace std;
int paper[130][130];
int check[2];

void func(int r, int c, int n)
{
  if (n == 0) // base condition
    return;
  bool flag = true;
  for (int i = r; i < r + n; i++)
  {
    for (int j = c; j < c + n; j++)
    {
      if (paper[i][j] != paper[r][c])
      {
        flag = false;
        break;
      }
    }
  }
  if (flag)
    check[paper[r][c]]++;
  else
  {
    for (int i = r; i < r + n; i += n / 2)
    {
      for (int j = c; j < c + n; j += n / 2)
      {
        func(i, j, n / 2);
      }
    }
  }
}
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> paper[i][j];
    }
  }
  func(0, 0, n);
  for (auto c : check)
    cout << c << '\n';
}