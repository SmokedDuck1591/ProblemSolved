#include <bits/stdc++.h>
using namespace std;
char arr[3072][6143];

void draw(int r, int c, int n)
{
  if (n == 3)
  {
    arr[r][c] = '*';

    arr[r + 1][c - 1] = '*';
    arr[r + 1][c + 1] = '*';

    for (int i = 0; i < 5; i++)
      arr[r + 2][c - 2 + i] = '*';
    return;
  }

  draw(r, c, n / 2);
  draw(r + n / 2, c - n / 2, n / 2);
  draw(r + n / 2, c + n / 2, n / 2);
}
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n * 2 - 1; j++)
    {
      arr[i][j] = ' ';
    }
  }

  draw(0, n - 1, n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n * 2 - 1; j++)
    {
      cout << arr[i][j];
    }
    cout << '\n';
  }
}