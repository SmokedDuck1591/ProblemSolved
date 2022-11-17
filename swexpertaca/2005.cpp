#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int test_case;
  int T;

  cin >> test_case;

  for (int test_num = 1; test_num <= test_case; test_num++)
  {
    cin >> T;
    cout << '#' << test_num << '\n';
    int arr[11][11];
    arr[0][0] = 1;
    for (int i = 0; i < T; i++)
    {
      for (int j = 0; j < i + 1; j++)
      {
        if (j == 0 || j == i)
        {
          arr[i][j] = 1;
          continue;
        }
        else
        {
          arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
      }
    }
    for (int i = 0; i < T; i++)
    {
      for (int j = 0; j < i + 1; j++)
      {
        cout << arr[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}